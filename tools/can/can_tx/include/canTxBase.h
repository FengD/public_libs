/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */
#ifndef _CANTX_BASE_H_
#define _CANTX_BASE_H_

#include <stdint.h>
#include <yaml-cpp/yaml.h>
#include <list>
#include <linux/can.h>
#include "canmsg_define.h"

namespace itd {
namespace communication {
  class CanHandler;
  class CanConfig;
}
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

#endif  // _CANTX_BASE_H_
