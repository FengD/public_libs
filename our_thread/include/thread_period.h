/* -*- mode: C++ -*-
 *
 *  Copyright (C) 2019 Feng DING, Hirain
 *
 *  License: Modified BSD Software License Agreement
 *
 */

#ifndef _MODULE_OUR_THREAD_PERIOD_H_
#define _MODULE_OUR_THREAD_PERIOD_H_

#include <yaml-cpp/yaml.h>
#include "thread_base.h"
#include <stdint.h>

namespace itd {
class ThreadPeriod : public ThreadBase {
 private:
  struct timespec periodCall_;
  bool isLogOn_;

 protected:
  void setPeriodCall(const int32_t &usec);
  void setLogSwitch(const bool &isLogOn);
  bool getLogSwitch() const;
  void setThreadParam(const YAML::Node &config);

 public:
  virtual ~ThreadPeriod();
  void Run();
  virtual void RunInPeriod() = 0;
  virtual void SetParam(YAML::Node config) = 0;
};
}  // namespace itd

#endif  // _MODULE_OUR_THREAD_PERIOD_H_
