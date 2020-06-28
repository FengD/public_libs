// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef OUR_THREAD_INCLUDE_THREAD_MSG_HEADER_H_
#define OUR_THREAD_INCLUDE_THREAD_MSG_HEADER_H_

#include <stdint.h>
#include "thread_mutex.h"

namespace itd {

typedef struct {
  uint64_t timestamp;
  uint64_t timeoffset;
  ThreadMutex mutex;
} ThreadMsgHeader;

}  // namespace itd

#endif  // OUR_THREAD_INCLUDE_THREAD_MSG_HEADER_H_
