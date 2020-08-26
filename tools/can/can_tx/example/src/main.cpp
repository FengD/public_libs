// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example can rx
// Date: 2019-11-22
// Change Log:

#include "canTxBase.h"
#include <unistd.h>
#include <functional>

int main(int argv, char ** argc) {
  itd::tools::can::CanTxBase *canTx_ = new itd::tools::can::CanTxBase();
  canTx_->SetChannel(1);
  if (argv < 1) {
    return 1;
  }
  canTx_->SetDbcsFolderPath(argc[1]);
  canTx_->LoadDbcs();
  canTx_->Init();
  double value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  while (1) {
    printf("send before\n");
    canTx_->Send(2566868725, value, 13);
    printf("send after\n");
    usleep(100000);
  }
  canTx_->Finish();
  delete canTx_;
  return 0;
}
