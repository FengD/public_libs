// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef OUR_THREAD_INCLUDE_MACRO_DEFINE_H_
#define OUR_THREAD_INCLUDE_MACRO_DEFINE_H_
#include "hlog.h"

template<typename T>
class ThreadManager {
 public:
  static void ThreadStart(const bool &on_flag, const T& t) {
    if (on_flag) {
      t.Start();
    }
  }

  static void ThreadStop(const bool &on_flag, const T& t) {
    if (on_flag) {
      t.Stop();
    }
  }

  static void ThreadResume(const bool &on_flag, const T& t) {
    if (on_flag) {
      t.Resume();
    }
  }

  static void ThreadPause(const bool &on_flag, const T& t) {
    if (on_flag) {
      t.Pause();
    }
  }
};

// thread start and detach
#define SDT(switch, thread)\
if (switch) {\
  LOGINFO("%s start: %d\n", thread->getPName().c_str(), thread->Start());\
  LOGINFO("deatch: %d\n", thread->getPName().c_str(), thread->Detach());\
}
// thread start and join
#define SJT(switch, thread)\
if (switch) {\
  LOGINFO("%s start: %d\n", thread->getPName().c_str(), thread->Start());\
  LOGINFO("%s join: %d\n", thread->getPName().c_str(), thread->Join());\
}
#define S(switch, thread)\
if (switch) {\
  LOGINFO("%s start: %d\n", thread->getPName().c_str(), thread->Start());\
}
// thread stop
#define ST(switch, thread)\
if (switch) {\
  LOGINFO("%s start: %d\n", thread->getPName().c_str(), thread->Stop());\
}

#endif  // OUR_THREAD_INCLUDE_MACRO_DEFINE_H_
