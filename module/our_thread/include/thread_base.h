// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef _MODULE_OUR_THREAD_THREAD_BASE_H_
#define _MODULE_OUR_THREAD_THREAD_BASE_H_

#include <pthread.h>
#include <signal.h>
#include <string>

namespace itd {
class ThreadBase {
  enum ThreadStat {
    ThreadStartFailed = -3,
    ThreadJoinFailed = -2,
    ThreadDetachFailed = -1,
    ThreadNoError = 0
  };
 private:
  static void* func(void* arg);
  pthread_t pid_;
  bool isAlive_;
  std::string pName_;

 public:
  int32_t Start();
  int32_t Join();
  int32_t Detach();
  int32_t Stop();

  pthread_t getPid();
  void setPName(std::string pName);
  std::string getPName();
  bool isAlive();

  virtual void Run() = 0;
  virtual ~ThreadBase();
};
} // namespace itd

#endif  // _MODULE_OUR_THREAD_THREAD_BASE_H_
