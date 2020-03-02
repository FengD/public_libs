// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef _MODULE_OUR_THREAD_THREAD_MUTEX_H_
#define _MODULE_OUR_THREAD_THREAD_MUTEX_H_

#include <pthread.h>
#include <stdint.h>

namespace itd {

class ThreadMutex {
 private:
  pthread_mutex_t  mutex_;

 public:
  ThreadMutex();
  ~ThreadMutex();
  void Lock();
  void Unlock();
};

class EnterCriticalSection {
 private:
  ThreadMutex * threadMutex_;
 public:
  EnterCriticalSection(ThreadMutex * threadMutex);
  ~EnterCriticalSection();
};

} // namespace itd

#endif  // _MODULE_OUR_THREAD_THREAD_MUTEX_H_
