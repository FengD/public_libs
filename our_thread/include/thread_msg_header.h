// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef _ITD_IPD_LIBS_OUR_THREAD_THREAD_MSG_HEADER_H_
#define _ITD_IPD_LIBS_OUR_THREAD_THREAD_MSG_HEADER_H_

// #include <semaphore.h>
#include <stdint.h>
#include "thread_mutex.h"

namespace itd {

typedef struct {
  uint64_t timestamp;
  uint64_t timeoffset;
  // sem_t semFreespace;
  ThreadMutex mutex;
} ThreadMsgHeader;

}  // namespace itd

#endif  // _ITD_IPD_LIBS_OUR_THREAD_THREAD_MSG_HEADER_H_
