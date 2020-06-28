// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_period.h"
#include <stdio.h>
#include "util.h"
#include "hlog.h"

namespace itd {

void ThreadPeriod::Run() {
  while (isAlive() == true) {
    clock_gettime(CLOCK_MONOTONIC, &start_time_);
    RunInPeriod();
    clock_gettime(CLOCK_MONOTONIC, &end_time_);
    calc_time_diff(&start_time_, &end_time_, &elapsed_time_);
    calc_time_diff(&elapsed_time_, &period_call_, &sleep_time_);

    if (isLogOn_) {
      LOGINFO("%s(%d), [%1lu.%06ld]\n", getPName().c_str(), getPid(),
             (unsigned long) elapsed_time_.tv_sec,
             elapsed_time_.tv_nsec / 1000);
    }

    if (sleep_time_.tv_sec < 0) {
      continue;
    }

    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleep_time_, NULL);
  }
}

int64_t ThreadPeriod::getElapsedTimeUs() {
  return elapsed_time_.tv_sec * 1000 * 1000 + elapsed_time_.tv_nsec / 1000;
}

void ThreadPeriod::setPeriodCall(const int32_t& usec) {
  period_call_.tv_sec = usec / 1000000;
  period_call_.tv_nsec = (usec * 1000) % 1000000000;
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
  setPName(name);
  setPeriodCall(period);
}

ThreadPeriod::~ThreadPeriod() {}

}  // namespace itd
