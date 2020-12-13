// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#include "thread_base.h"
#include "hlog.h"

namespace itd {

void ThreadBase::thread_func() {
  while (!stop_flag_) {
    Run();
    if (pause_flag_) {
      std::unique_lock<std::mutex> locker(mutex_);
      while (pause_flag_) {
        condition_.wait(locker);
      }
    }
  }
  pause_flag_ = false;
  stop_flag_ = false;
}

ThreadBase::ThreadBase() : this_thread_(nullptr),
                           p_name_(""),
                           pause_flag_(false),
                           stop_flag_(false),
                           state_(Stopped) {}

ThreadBase::~ThreadBase() {
  Stop();
}

std::thread::id ThreadBase::GetPid() const {
  if (this_thread_ != nullptr) {
    return this_thread_->get_id();
  }
  return std::thread::id(0);
}

void ThreadBase::SetPName(const std::string& p_name) {
  p_name_ = p_name;
}

std::string ThreadBase::GetPName() const {
  return p_name_;
}

ThreadBase::State ThreadBase::GetState() const {
  return state_;
}

void ThreadBase::Start() {
  if (this_thread_ == nullptr) {
    this_thread_ = new std::thread(&ThreadBase::thread_func, this);
    pause_flag_ = false;
    stop_flag_ = false;
    state_ = Running;
  }
}

void ThreadBase::Stop() {
  if (this_thread_ != nullptr) {
    pause_flag_ = false;
    stop_flag_ = true;
    condition_.notify_all();
    this_thread_->join();
    delete this_thread_;
    this_thread_ = nullptr;
    state_ = Stopped;
  }
}

void ThreadBase::Pause() {
  if (this_thread_ != nullptr) {
    pause_flag_ = true;
    state_ = Paused;
  }
}

void ThreadBase::Resume() {
  if (this_thread_ != nullptr) {
    pause_flag_ = false;
    condition_.notify_all();
    state_ = Running;
  }
}


}  // namespace itd
