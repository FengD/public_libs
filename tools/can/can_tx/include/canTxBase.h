// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_CAN_CAN_TX_INCLUDE_CANTXBASE_H_
#define TOOLS_CAN_CAN_TX_INCLUDE_CANTXBASE_H_

#include <stdint.h>
#include <yaml-cpp/yaml.h>
#include <linux/can.h>
#include "canmsg_define.h"
#include <list>
#include <string>

namespace itd {
namespace communication {
class CanHandler;
class CanConfig;
}  // namespace communication

namespace tools {
namespace can {

class CanTxBase {
 private:
  // can channel
  int32_t channel_;
  std::string dbcsFolderPath_;
  void packValue(const int64_t &id, const int32_t &valueSize, const double *valueInput, Canmsg *msg);
  void copyFromCanmsg2CanFrame(const Canmsg &msg, struct can_frame *frame);
  int32_t ret_;
  communication::CanHandler *can_hdl_;
  struct can_frame can_tx_frame_;
  Canmsg msg_;

 public:
  CanTxBase();
  ~CanTxBase();
  void SetParam(YAML::Node config);
  void SetChannel(const int32_t &channel);
  void SetDbcsFolderPath(const std::string &dbcsFolderPath);
  void LoadDbcs();
  void Init();
  int32_t Send(const int64_t &id, const double *value , const int32_t &value_size);
  void Finish();
};

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  // TOOLS_CAN_CAN_TX_INCLUDE_CANTXBASE_H_
