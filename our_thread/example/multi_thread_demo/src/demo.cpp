// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: example multi_thread_demo

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "thread_period.h"
#include "macro_define.h"

class P : public itd::ThreadPeriod {
 public:
  P(std::string name) {
    setPeriodCall(1000000);
    SetPName("p:" + name);
    setLogSwitch(true);
    LOGINFO("%s\n", GetPName().c_str());
  }
  void RunInPeriod () {
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
};

class B : public itd::ThreadBase {
 public:
  B(std::string name) {
    SetPName("b:" + name);
    LOGINFO("%s\n", GetPName().c_str());
  }
  void Run () {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
};

int main() {
  std::vector<itd::ThreadBase*> thread_pool;
  thread_pool.push_back(new P("1"));
  thread_pool.push_back(new P("2"));
  thread_pool.push_back(new P("3"));
  thread_pool.push_back(new B("4"));
  thread_pool.push_back(new B("5"));
  thread_pool.push_back(new B("6"));
  thread_pool.push_back(new B("7"));
  thread_pool.push_back(new B("8"));
  thread_pool.push_back(new B("0"));
  thread_pool.push_back(new B("11"));
  thread_pool.push_back(new B("12"));
  thread_pool.push_back(new B("13"));
  thread_pool.push_back(new B("14"));
  thread_pool.push_back(new B("15"));

  for(auto *thread : thread_pool) {
    thread->Start();
  }

  while(1) {
    std::this_thread::sleep_for(std::chrono::seconds(100));
  }
  return 0;
}
