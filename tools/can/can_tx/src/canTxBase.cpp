/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#include "canTxBase.h"
#include "dbc_file_analysis.h"
#include "dbc_canmsg_pack.h"
#include "util.h"
#include "socket_can.h"
#include "socket_can_handler.h"
#include "socket_can_config.h"

namespace itd {
namespace tools {
namespace can {

CanTxBase::CanTxBase() {}

CanTxBase::~CanTxBase() {
  Finish();
}

void CanTxBase::Init() {
  ret_ = 0;
  communication::CanConfig cfg;
  char interface[5];
  sprintf(interface, "can%d", channel_);
  cfg.ifname = interface;
  cfg.loopback = 1;
  cfg.is_filter_set = 0;
   // can socket open
  ret_ = communication::SocketCan::can_open(&can_hdl_, &cfg);
  if (ret_ < 0) {
    printf("Unable to open CAN interface: %s\n", cfg.ifname);
  }
}

void CanTxBase::Finish() {
  communication::SocketCan::can_close(&can_hdl_);
}

void CanTxBase::SetParam(YAML::Node config) {
  channel_ = config["canChannel"].as<int32_t>();
  dbcsFolderPath_ = config["dbcsFolderPath"].as<std::string>();
  Init();
}

void CanTxBase::SetChannel(const int32_t &channel) {
  channel_ = channel;
}

void CanTxBase::SetDbcsFolderPath(const std::string &dbcsFolderPath) {
  dbcsFolderPath_ = dbcsFolderPath;
}

void CanTxBase::LoadDbcs() {
  std::vector<std::string> files;
  getAllFilesInFolder(dbcsFolderPath_, &files);
  for (std::string &file : files) {
    DbcAnalysis::getInstance()->addOneDbcFile(file);
  }
  DbcAnalysis::getInstance()->analysisFiles();
}

void CanTxBase::packValue(const int64_t &id, const int32_t &valueSize, const double *valueInput, Canmsg *msg) {
  memset(msg->data, 0, 8 * sizeof(unsigned char));
  Message canMsgStruct = DbcAnalysis::getInstance()->getMessages()[id];
  packCanmsg(canMsgStruct, valueSize, valueInput, msg);
  msg->length = canMsgStruct.length;
  msg->id = id;
}

void CanTxBase::copyFromCanmsg2CanFrame(const Canmsg &msg, struct can_frame *frame) {
  memset(frame->data, 0, 8 * sizeof(unsigned char));
  frame->can_id = msg.id;
  frame->can_dlc = msg.length;
  for(int32_t j = 0; j < msg.length; j++) {
    frame->data[j] = msg.data[j];
  }
}

int32_t CanTxBase::Send(const int64_t &id, const double *value , const int32_t &value_size) {
  packValue(id, value_size, value, &msg_);
  copyFromCanmsg2CanFrame(msg_, &can_tx_frame_);
  return communication::SocketCan::can_write(can_hdl_, &can_tx_frame_);
}

}  // namespace can
}  // namespace tools
}  // namespace itd
