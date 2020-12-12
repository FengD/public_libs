// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_mutex.h"
#include <stdio.h>

namespace itd {

ThreadMutex::ThreadMutex() { }

ThreadMutex::~ThreadMutex() { }

void ThreadMutex::Lock() {
  mutex_.lock();
}

void ThreadMutex::Unlock() {
  mutex_.unlock();
}

EnterCriticalSection::EnterCriticalSection(ThreadMutex * threadMutex) {
  threadMutex_ = threadMutex;
  threadMutex_->Lock();
}

EnterCriticalSection::~EnterCriticalSection() {
  threadMutex_->Unlock();
}

}  // namespace itd
