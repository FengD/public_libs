// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This template class synchronizes mutiplue data streams of different types.
//              The data can be added using add0, add1, ... addn methods which expects
//              also a timestamp of type uint64_t.
//              If multiple matching data objects are found, registered callback functions
//              are invoked with the objects and the time stamps.
//              The only assumption of the timestamp is, that they are in the same unit,
//              linear and strictly monotonic increasing.
//              If filtering is desired, e.g. thresholding of time differences, the user
//              can do that in the callback method.
//              This class is thread safe.
//              Now two data support.

#ifndef OUR_THREAD_INCLUDE_SYNCHRONIZER_H_
#define OUR_THREAD_INCLUDE_SYNCHRONIZER_H_

#include <deque>
#include <functional>
#include <mutex>
#include <map>
#include <utility>

namespace itd {
template <typename T1, typename T2>
class Synchronizer {
  using T1Stamped = std::pair<uint64_t, T1>;
  using T2Stamped = std::pair<uint64_t, T2>;
  std::mutex mutex1_;
  std::mutex mutex2_;
  std::mutex publish_mutex_;
  std::deque<T1Stamped> queueT1;
  std::deque<T2Stamped> queueT2;

  using CallbackFunction = std::function<void(T1, T2, uint64_t, uint64_t)>;

  std::map<int32_t, CallbackFunction> cb_;
  int32_t callback_counter = 0;

 public:
  int32_t addCallback(const CallbackFunction& callback) {
    std::unique_lock<std::mutex> publish_lock(publish_mutex_);
    cb_[callback_counter] = callback;
    return callback_counter++;
  }

  void removeCallback(const int32_t& i) {
    std::unique_lock<std::mutex> publish_lock(publish_mutex_);
    cb_.erase(i);
  }

  void add0(const T1& t, const uint64_t& time) {
    mutex1_.lock();
    queueT1.push_back(T1Stamped(time, t));
    mutex1_.unlock();
    publish();
  }

  void add1(const T2& t, const uint64_t& time) {
    mutex2_.lock();
    queueT2.push_back(T2Stamped(time, t));
    mutex2_.unlock();
    publish();
  }

 private:
  void publishData() {
    std::unique_lock<std::mutex> lock1(mutex1_);
    std::unique_lock<std::mutex> lock2(mutex2_);

    for (const auto& cb : cb_) {
      if (cb.second) {
        cb.second.operator()(queueT1.front().second, queueT2.front().second,
                             queueT1.front().first, queueT2.front().first);
      }
    }

    queueT1.pop_front();
    queueT2.pop_front();
  }

  void publish() {
    // only one publish call at once allowed
    std::unique_lock<std::mutex> publish_lock(publish_mutex_);
    std::unique_lock<std::mutex> lock1(mutex1_);
    if (queueT1.empty()) {
      return;
    }

    T1Stamped t1 = queueT1.front();
    lock1.unlock();
    std::unique_lock<std::mutex> lock2(mutex2_);
    if (queueT2.empty()) {
      return;
    }

    T2Stamped t2 = queueT2.front();
    lock2.unlock();
    bool do_publish = false;

    if (t1.first <= t2.first) {
      lock1.lock();
      while (queueT1.size() > 1 && queueT1[1].first <= t2.first) {
        queueT1.pop_front();
      }
       // we have at least 2 measurements; first in past and second in future -> find out closer one!
      if (queueT1.size() > 1) {
        if ((t2.first << 1) > (queueT1[0].first + queueT1[1].first)) {
          queueT1.pop_front();
        }

        do_publish = true;
      }
      lock1.unlock();
    } else {  // iterate over queue2
      lock2.lock();
      while (queueT2.size() > 1 && (queueT2[1].first <= t1.first)) {
        queueT2.pop_front();
      }
      // we have at least 2 measurements; first in past and second in future -> find out closer one!
      if (queueT2.size() > 1) {
        if ((t1.first << 1) > queueT2[0].first + queueT2[1].first ) {
          queueT2.pop_front();
        }

        do_publish = true;
      }
      lock2.unlock();
    }

    if (do_publish) {
      publishData();
    }
  }
};
}  // namespace itd


#endif  // OUR_THREAD_INCLUDE_SYNCHRONIZER_H_
