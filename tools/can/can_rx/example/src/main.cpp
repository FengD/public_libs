// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example can rx
// Date: 2019-11-22
// Change Log:

#include "canRxBase.h"
#include <functional>

void canReceiveCallBack(int64_t id, double *value, int32_t value_size) {
  printf("%ldln  size:%d\n", id, value_size);
}

int main(int argv, char ** argc) {
  itd::tools::can::CanRxBase *canRx_ = new itd::tools::can::CanRxBase();
  canRx_->SetChannel(1);
  if (argv < 1) {
    return 1;
  }
  canRx_->SetDbcsFolderPath(argc[1]);
  int64_t id_list[3] = {773, 2163251494, 2002};
  canRx_->SetCanFilterIdList(id_list, 3);
  canRx_->LoadDbcs();
  canRx_->Init();
  canRx_->LoadDbcs();
  canRx_->SetCallBackFunction(std::bind(canReceiveCallBack,
                                        std::placeholders::_1,
                                        std::placeholders::_2,
                                        std::placeholders::_3));
  canRx_->Receive();
  delete canRx_;
  return 0;
}
