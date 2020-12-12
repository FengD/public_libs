// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example mqtt sub

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "thread_period.h"

class Test : public itd::ThreadPeriod {
 public:
  Test() {
    setPeriodCall(1000000);
    SetPName("Test");
    setLogSwitch(true);
  }
  void RunInPeriod () {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "haha" << std::endl;
  }
};

int main() {

  Test t;

  t.Start();

  std::this_thread::sleep_for(std::chrono::seconds(3));

  t.Pause();

  std::this_thread::sleep_for(std::chrono::seconds(3));

  t.Resume();

  std::this_thread::sleep_for(std::chrono::seconds(3));

  t.Stop();

  return 0;
}
