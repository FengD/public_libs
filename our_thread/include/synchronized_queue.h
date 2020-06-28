// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: Support class data point to point communication

#ifndef OUR_THREAD_INCLUDE_SYNCHRONIZED_QUEUE_H_
#define OUR_THREAD_INCLUDE_SYNCHRONIZED_QUEUE_H_

#include <condition_variable>
#include <mutex>
#include <queue>

namespace itd {
template<typename T>
class SynchronizedQueue {
 public:
  SynchronizedQueue() : queue_(), request_to_end_(false), enqueue_data_(true) { }

  void enqueue(const T& data) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (enqueue_data_) {
     queue_.push(data);
     cond_.notify_one();
    }
  }

  bool dequeue(T& result) {
    std::unique_lock<std::mutex> lock(mutex_);
    while (queue_.empty() && (!request_to_end_)) {
      cond_.wait(lock);
    }

    if (request_to_end_) {
      doEndActions();
      return false;
    }

    result = queue_.front();
    queue_.pop();
    return true;
  }

  void stopQueue() {
    std::unique_lock<std::mutex> lock(mutex_);
    request_to_end_ = true;
    cond_.notify_one();
  }

  uint32_t size() {
    std::unique_lock<std::mutex> lock(mutex_);
    return static_cast<uint32_t>(queue_.size());
  }

  bool isEmpty() const {
    std::unique_lock<std::mutex> lock(mutex_);
    return (queue_.empty());
  }

 private:
  void doEndActions() {
    enqueue_data_ = false;
    while (!queue_.empty()) {
      queue_.pop();
    }
  }

  std::queue<T> queue_;
  mutable std::mutex mutex_;
  std::condition_variable cond_;

  bool request_to_end_;
  bool enqueue_data_;
};
}  // namespace itd

#endif  // OUR_THREAD_INCLUDE_SYNCHRONIZED_QUEUE_H_
