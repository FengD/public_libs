// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_mutex.h"
#include <stdio.h>

namespace itd {

ThreadMutex::ThreadMutex() {
  int32_t r = pthread_mutex_init(&mutex_, 0);
  if (r != 0) {
    printf("Error mutex init\n");
  }
}

ThreadMutex::~ThreadMutex() {
  int32_t r = pthread_mutex_destroy(&mutex_);
  if (r != 0) {
    printf("Error mutex deinit\n");
  }
}

void ThreadMutex::Lock() {
  int32_t r = pthread_mutex_lock(&mutex_);
  if (r != 0) {
    printf("Error mutex lock\n");
  }
}

void ThreadMutex::Unlock() {
  int32_t r = pthread_mutex_unlock(&mutex_);
  if (r != 0) {
    printf("Error mutex unlock\n");
  }
}

EnterCriticalSection::EnterCriticalSection(ThreadMutex * threadMutex) {
  threadMutex_ = threadMutex;
  threadMutex_->Lock();
}

EnterCriticalSection::~EnterCriticalSection() {
  threadMutex_->Unlock();
}

}  // namespace itd
