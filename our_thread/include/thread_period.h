// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef OUR_THREAD_INCLUDE_THREAD_PERIOD_H_
#define OUR_THREAD_INCLUDE_THREAD_PERIOD_H_

#include <yaml-cpp/yaml.h>
#include <stdint.h>
#include <chrono>
#include "thread_base.h"

namespace itd {
class ThreadPeriod : public ThreadBase {
 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time_, end_time_;
  // period_call 100ms by default
  std::chrono::duration<double, std::micro> elapsed_time_, sleep_time_, period_call_;
  bool is_log_on_;
  int64_t step_counter_, sum_runtime_, avg_runtime_;
  void CalculateAverageElapsedTimeUs();

 protected:
  void setPeriodCall(const int32_t &usec);
  void setLogSwitch(const bool &isLogOn);
  bool getLogSwitch() const;
  void setThreadParam(const YAML::Node &config);

 public:
  ThreadPeriod();
  virtual ~ThreadPeriod();
  virtual void RunInPeriod() = 0;
  void Run();
  int64_t getAverageElapsedTimeUs();
};
}  // namespace itd

#endif  // OUR_THREAD_INCLUDE_THREAD_PERIOD_H_
