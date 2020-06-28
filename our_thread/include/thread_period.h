// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef OUR_THREAD_INCLUDE_PERIOD_H_
#define OUR_THREAD_INCLUDE_PERIOD_H_

#include <yaml-cpp/yaml.h>
#include "thread_base.h"
#include <stdint.h>

namespace itd {
class ThreadPeriod : public ThreadBase {
 private:
  struct timespec period_call_, start_time_, end_time_, elapsed_time_, sleep_time_;
  bool isLogOn_;

 protected:
  void setPeriodCall(const int32_t &usec);
  void setLogSwitch(const bool &isLogOn);
  bool getLogSwitch() const;
  void setThreadParam(const YAML::Node &config);

 public:
  virtual ~ThreadPeriod();
  void Run();
  int64_t getElapsedTimeUs();
  virtual void RunInPeriod() = 0;
  // virtual void SetParam(YAML::Node config);

};
}  // namespace itd

#endif  // OUR_THREAD_INCLUDE_PERIOD_H_
