// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:
// Date: 2019-11-22
// Change Log:

#ifndef TOOLS_CAN_CAN_RX_INCLUDE_CANRXBASE_H_
#define TOOLS_CAN_CAN_RX_INCLUDE_CANRXBASE_H_

#include <yaml-cpp/yaml.h>
#include <linux/can.h>
#include <stdint.h>
#include <float.h>
#include <list>
#include "canmsg_define.h"

namespace itd {
namespace communication {
  class CanHandler;
  class CanConfig;
}  // namespace communication

namespace tools {
namespace can {

class CanRxBase {
 private:
  void unpackValue(const struct can_frame &frame, double *value_output, int32_t &value_size);
  void copyFromCanFrame2Canmsg(const can_frame &frame, struct Canmsg *msg);
  void setCanFilter(communication::CanConfig *cfg);

  int32_t ret_;
  communication::CanHandler *can_hdl_;
  struct can_frame *can_rx_frame_;
  int64_t *id_list_;
  int32_t id_list_size_;
  int32_t channel_;
  std::string dbcs_folder_path_;
  std::function<void(int64_t id, double *value, int32_t value_size)> canmsg_unpack_callback_;

 public:
  CanRxBase();
  ~CanRxBase();
  void SetParam(const YAML::Node &config);
  void SetChannel(const int32_t &channel);
  void SetDbcsFolderPath(const std::string &dbcs_folder_path);
  void SetCanFilterIdListByYaml(const YAML::Node &list);
  void SetCanFilterIdList(const int64_t* list, const int32_t &list_size);
  void SetCallBackFunction(std::function<void(int64_t id, double *value, int32_t value_size)> canmsg_unpack_callback);
  void LoadDbcs();
  void Init();
  void Receive();
  void Finish();
};

}  // namespace can
}  // namespace tools
}  // namespace itd

#endif  // TOOLS_CAN_CAN_RX_INCLUDE_CANRXBASE_H_
