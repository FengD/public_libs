/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#ifndef _ITD_IPD_LIBS_OUR_THREAD_PERIOD_H_
#define _ITD_IPD_LIBS_OUR_THREAD_PERIOD_H_

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
  virtual void SetParam(YAML::Node config) = 0;

};
}  // namespace itd

#endif  // _ITD_IPD_LIBS_OUR_THREAD_PERIOD_H_
