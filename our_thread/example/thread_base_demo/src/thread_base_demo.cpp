// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example mqtt sub

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "thread_period.h"

class Test : public itd::ThreadBase {
 public:
  Test() {
    SetPName("Test");
  }
  void Run () {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "haha" << std::endl;
  }
};

int main() {

  Test t;

  t.Start();
  std::cout << t.GetState() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << t.GetState() << std::endl;
  t.Pause();
  std::cout << t.GetState() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << t.GetState() << std::endl;
  t.Resume();
  std::cout << t.GetState() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << t.GetState() << std::endl;
  t.Stop();
  std::cout << t.GetState() << std::endl;
  return 0;
}
