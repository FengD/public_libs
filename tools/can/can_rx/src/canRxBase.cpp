// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:
// Date: 2019-11-22
// Change Log:

#include "canRxBase.h"
#include "dbc_file_analysis.h"
#include "dbc_canmsg_unpack.h"
#include "util.h"
#include "hlog.h"
#include "socket_can.h"
#include "socket_can_handler.h"
#include "socket_can_config.h"

namespace itd {
namespace tools {
namespace can {

CanRxBase::CanRxBase() {
  can_rx_frame_ = (struct can_frame *) malloc(sizeof(struct can_frame));
  memset(can_rx_frame_, 0, sizeof(struct can_frame));
  id_list_size_ = 0;
  channel_ = 0;
  dbcs_folder_path_ = "";
  ret_ = 0;
}

CanRxBase::~CanRxBase() {
  delete can_rx_frame_;
  delete id_list_;
  Finish();
}

void CanRxBase::Init() {
  communication::CanConfig cfg;
  char interface[5];
  sprintf(interface, "can%d", channel_);
  cfg.ifname = interface;
  cfg.loopback = 1;
  cfg.is_filter_set = 1;
  setCanFilter(&cfg);
  ret_ = communication::SocketCan::can_open(&can_hdl_, &cfg);
  if (ret_ < 0) {
    printf("Unable to open CAN interface: %s\n", cfg.ifname);
  }
}

void CanRxBase::Finish() {
  communication::SocketCan::can_close(&can_hdl_);
}

void CanRxBase::SetParam(const YAML::Node &config) {
  SetChannel(config["canChannel"].as<int32_t>());
  SetDbcsFolderPath(config["dbcsFolderPath"].as<std::string>());
  SetCanFilterIdListByYaml(config["canRxFilterList"]);
  Init();
}

void CanRxBase::SetChannel(const int32_t &channel) {
  channel_ = channel;
}

void CanRxBase::SetDbcsFolderPath(const std::string &dbcs_folder_path) {
  dbcs_folder_path_ = dbcs_folder_path;
}

void CanRxBase::SetCanFilterIdListByYaml(const YAML::Node &list) {
  id_list_size_ = list.size();
  if (id_list_size_ > 0) {
    id_list_ = (int64_t *) malloc(id_list_size_ * sizeof(int64_t));
    memset(id_list_, 0, id_list_size_ * sizeof(int64_t));

    for (int32_t i = 0; i < id_list_size_; i++) {
      id_list_[i] = list[i].as<int64_t>();
    }
  }
}

void CanRxBase::SetCanFilterIdList(const int64_t* list, const int32_t &list_size) {
  id_list_size_ = list_size;
  if (id_list_size_ > 0) {
    id_list_ = (int64_t *) malloc(id_list_size_ * sizeof(int64_t));
    memset(id_list_, 0, id_list_size_ * sizeof(int64_t));

    for (int32_t i = 0; i < id_list_size_; i++) {
      id_list_[i] = list[i];
    }
  }
}

void CanRxBase::SetCallBackFunction(std::function<void(int64_t id,
                                                       double *value, int32_t value_size)> canmsg_unpack_callback) {
  canmsg_unpack_callback_ = canmsg_unpack_callback;
}

void CanRxBase::LoadDbcs() {
  std::vector<std::string> files;
  getAllFilesInFolder(dbcs_folder_path_, &files);
  for (std::string &file : files) {
    DbcAnalysis::getInstance()->addOneDbcFile(file);
  }
  DbcAnalysis::getInstance()->analysisFiles();
}

void CanRxBase::Receive() {
  double value_out[64];
  int32_t value_size = 0;
  for (;;) {
    memset(can_rx_frame_, 0, sizeof(struct can_frame));
    memset(value_out, 0, 64 * sizeof(double));
    ret_ = communication::SocketCan::can_read(can_hdl_, can_rx_frame_);

    if (ret_ < 0) {
      continue;
    }

    if (can_rx_frame_->can_id & CAN_ERR_FLAG) {
      LOGERROR("error frame id: %d\n", can_rx_frame_->can_id);
      LOGERROR("data[8] [%d %d %d %d %d %d %d %d]\n", can_rx_frame_->data[0], can_rx_frame_->data[1],
       can_rx_frame_->data[2], can_rx_frame_->data[3], can_rx_frame_->data[4],
       can_rx_frame_->data[5], can_rx_frame_->data[6], can_rx_frame_->data[7]);
       if (can_rx_frame_->can_id & CAN_ERR_CRTL) {
         system("ip link set can1 down");
         system("ip link set can1 up");
       }
    } else {
      unpackValue(*can_rx_frame_, value_out, value_size);
      canmsg_unpack_callback_(can_rx_frame_->can_id, value_out, value_size);
    }
  }
}

void CanRxBase::setCanFilter(communication::CanConfig *cfg) {
  if (id_list_size_ > 0) {
    cfg->rx_filter = (struct can_filter*) malloc(id_list_size_ * sizeof(struct can_filter));
    for (int32_t i = 0; i < id_list_size_; i++) {
      cfg->rx_filter[i].can_id = id_list_[i];
      cfg->rx_filter[i].can_mask = CAN_SFF_MASK;
    }
    cfg->rx_filter_len = id_list_size_;
  }
}

void CanRxBase::unpackValue(const struct can_frame &frame, double *value_output, int32_t &value_size) {
  struct Canmsg msg;
  copyFromCanFrame2Canmsg(frame, &msg);
  Message can_msg_struct = DbcAnalysis::getInstance()->getMessages()[frame.can_id];
  value_size = can_msg_struct.signals.size();
  memset(value_output, 0, value_size * sizeof(double));
  unpackCanmsg(can_msg_struct, msg, value_size, value_output);
}

void CanRxBase::copyFromCanFrame2Canmsg(const can_frame &frame, struct Canmsg *msg) {
  memset(msg->data, 0, 8 * sizeof(unsigned char));
  msg->id = frame.can_id;
  msg->length = frame.can_dlc;
  for (int32_t j = 0; j < frame.can_dlc; j++) {
    msg->data[j] = frame.data[j];
  }
}

}  // namespace can
}  // namespace tools
}  // namespace itd
