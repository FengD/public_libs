// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef _ITD_IPD_LIBS_OUR_THREAD_MACRO_DEFINE_H_
#define _ITD_IPD_LIBS_OUR_THREAD_MACRO_DEFINE_H_
#include "hlog.h"

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
// thread stop
#define ST(switch, thread)\
if (switch) {\
  LOGINFO("%s start: %d\n", thread->getPName().c_str(), thread->Stop());\
}

#endif  // _ITD_IPD_LIBS_OUR_THREAD_MACRO_DEFINE_H_
