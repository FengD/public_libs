// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_base.h"

namespace itd {

void* ThreadBase::func(void* arg) {
  ThreadBase *ptr = (ThreadBase*) arg;
  ptr->Run();
  return NULL;
}

int32_t ThreadBase::Start() {
  pthread_attr_init(&attr_);
  pthread_attr_setdetachstate(&attr_, PTHREAD_CREATE_DETACHED);
  if (pthread_create(&pid_, NULL, func, (void*)this) != 0) {
    return ThreadStartFailed;
  }
  isAlive_ = true;
  return ThreadNoError;
}

int32_t ThreadBase::Join() {
  if (pthread_join(pid_, NULL) != 0) {
    return ThreadJoinFailed;
  }
  return ThreadNoError;
}

int32_t ThreadBase::Detach() {
  if (pthread_detach(pid_) != 0) {
    return ThreadDetachFailed;
  }
  return ThreadNoError;
}

int32_t ThreadBase::Stop() {
  isAlive_ = false;
  return ThreadNoError;
}

pthread_t ThreadBase::getPid() {
  return pid_;
}

void ThreadBase::setPName(std::string pName) {
  pName_ = pName;
}

std::string ThreadBase::getPName() {
  return pName_;
}


bool ThreadBase::isAlive() {
  return isAlive_;
}


ThreadBase::~ThreadBase() {
  if (isAlive_) {
    pthread_kill(pid_, 0);
    pthread_attr_destroy(&attr_);
  }
}

}  // namespace itd
