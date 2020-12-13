// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_period.h"
#include <stdio.h>
#include <thread>
#include <future>
#include "util.h"
#include "hlog.h"

namespace itd {

ThreadPeriod::ThreadPeriod() :
  period_call_(std::chrono::duration<double, std::micro>(1000000)),
  is_log_on_(false),
  step_counter_(1),
  sum_runtime_(0),
  avg_runtime_(0) {}

void ThreadPeriod::Run() {
  start_time_ = std::chrono::high_resolution_clock::now();
  RunInPeriod();
  end_time_ = std::chrono::high_resolution_clock::now();
  elapsed_time_ = end_time_ - start_time_;
  sleep_time_ = period_call_ - elapsed_time_;
  CalculateAverageElapsedTimeUs();
  if (sleep_time_.count() > 0) {
    std::this_thread::sleep_for(sleep_time_);
  }
}

void ThreadPeriod::CalculateAverageElapsedTimeUs() {
  sum_runtime_ += static_cast<int64_t>(elapsed_time_.count());
  avg_runtime_ = sum_runtime_ / step_counter_;
  if (++step_counter_ > 100) {
    step_counter_ = 1;
    sum_runtime_ = 0;
  }
}

int64_t ThreadPeriod::getAverageElapsedTimeUs() {
  return avg_runtime_;
}

void ThreadPeriod::setPeriodCall(const int32_t& usec) {
  period_call_ = std::chrono::duration<double, std::micro>(usec);
}

void ThreadPeriod::setLogSwitch(const bool& isLogOn) {
  is_log_on_ = isLogOn;
}

bool ThreadPeriod::getLogSwitch() const {
  return is_log_on_;
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
