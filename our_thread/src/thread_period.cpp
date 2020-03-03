/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#include "thread_period.h"
#include <stdio.h>
#include "util.h"
#include "hlog.h"

namespace itd {

void ThreadPeriod::Run() {
  while (isAlive() == true) {
    struct timespec startTime, endTime, elapsedTime, sleepTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);
    RunInPeriod();
    clock_gettime(CLOCK_MONOTONIC, &endTime);
    calc_time_diff(&startTime, &endTime, &elapsedTime);
    calc_time_diff(&elapsedTime, &periodCall_, &sleepTime);

    if (isLogOn_) {
      LOGINFO("%s(%d), [%1lu.%06ld]\n", getPName().c_str(), getPid(),
             (unsigned long)elapsedTime.tv_sec,
             elapsedTime.tv_nsec / 1000);
    }

    if (sleepTime.tv_sec < 0) {
      continue;
    }

    clock_nanosleep(CLOCK_MONOTONIC, 0, &sleepTime, NULL);
  }
}

void ThreadPeriod::setPeriodCall(const int32_t& usec) {
  periodCall_.tv_sec = usec / 1000000;
  periodCall_.tv_nsec = (usec * 1000) % 1000000000;
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

}// namespace itd
