// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_period.h"
#include <stdio.h>
#include <thread>
#include "util.h"
#include "hlog.h"

namespace itd {

ThreadPeriod::ThreadPeriod() : isLogOn_(false) {}

void ThreadPeriod::Run() {
  // while (!stop_flag_) {
  start_time_ = std::chrono::high_resolution_clock::now();
  RunInPeriod();
  end_time_ = std::chrono::high_resolution_clock::now();
  elapsed_time_ = end_time_ - start_time_;
  sleep_time_ = period_call_ - elapsed_time_;
  if (isLogOn_) {
    LOGINFO("%s(%d), [%lfns]\n", GetPName().c_str(), GetPid(),
           elapsed_time_.count());
  }

  if (sleep_time_.count() > 0) {
    std::this_thread::sleep_for(sleep_time_);
  }

  //   if (pause_flag_) {
  //     std::unique_lock<std::mutex> locker(mutex_);
  //     while (pause_flag_) {
  //       condition_.wait(locker);
  //     }
  //   }
  // }
}

int64_t ThreadPeriod::getElapsedTimeUs() {
  return elapsed_time_.count();
}

void ThreadPeriod::setPeriodCall(const int32_t& usec) {
  period_call_ = std::chrono::duration<double, std::micro>(usec);
}

void ThreadPeriod::setLogSwitch(const bool& isLogOn) {
  isLogOn_ = isLogOn;
}

bool ThreadPeriod::getLogSwitch() const {
  return isLogOn_;
}

void ThreadPeriod::setThreadParam(const YAML::Node& config) {
  int32_t period = config["periodUsec"].as<int32_t>();
  bool isLogOn = config["log"].as<bool>();
  std::string name = config["name"].as<std::string>();
  setLogSwitch(isLogOn);
  SetPName(name);
  setPeriodCall(period);
}

ThreadPeriod::~ThreadPeriod() {}

}  // namespace itd
