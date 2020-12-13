// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description:

#ifndef OUR_THREAD_INCLUDE_THREAD_BASE_H_
#define OUR_THREAD_INCLUDE_THREAD_BASE_H_

#include <stdint.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <string>

namespace itd {
class ThreadBase {
enum State {
  Stopped,
  Running,
  Paused
};

 protected:
  std::thread *this_thread_;
  std::string p_name_;
  std::atomic<bool> pause_flag_;
  std::atomic<bool> stop_flag_;
  State state_;
  std::mutex mutex_;
  std::condition_variable condition_;

 private:
  void thread_func();

 public:
  ThreadBase();
  virtual ~ThreadBase();
  virtual void Run() = 0;

  std::thread::id GetPid() const;
  void SetPName(const std::string& p_name);
  std::string GetPName() const;
  State GetState() const;
  void Start();
  void Stop();
  void Pause();
  void Resume();
};
}  // namespace itd

#endif  // OUR_THREAD_INCLUDE_THREAD_BASE_H_
