// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef COMMUNICATION_MQTT_INCLUDE_HANDLER_H_
#define COMMUNICATION_MQTT_INCLUDE_HANDLER_H_

#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <functional>
#include "mqtt_config.h"
#include "publisher.h"
#include "subscriber.h"

namespace itd {
namespace communication {

class Handler {
 public:
  Handler(mosq_config cfg);
  Handler(std::string host, int32_t port,
          std::string username = "", std::string password = "");
  ~Handler();

  template<class M>
  Publisher* advertise(const std::string &topic) {
    return new Publisher(cfg_, topic);
  }

  template<class M>
  Publisher* advertise(const std::string &topic,
                      LogCallback on_log) {
    return new Publisher(cfg_, topic, on_log);
  }

  template<class M>
  Subscriber* subscribe(const std::string &topic, void (*on_message)(const M&)) {
    Subscriber *sub = new Subscriber(cfg_, topic);
    sub->Subscribe(on_message);
    return sub;
  }

  template<class M>
  Subscriber* subscribe(const std::string &topic, std::function<void(const M&)> on_message) {
    Subscriber *sub = new Subscriber(cfg_, topic);
    sub->Subscribe(on_message);
    return sub;
  }

  template<class M>
  Subscriber* subscribe(const std::string &topic, void (*on_message)(const M&), LogCallback on_log) {
    Subscriber *sub = new Subscriber(cfg_, topic, on_log);
    sub->Subscribe(on_message);
    return sub;
  }

  template<class M>
  Subscriber* subscribe(const std::string &topic, std::function<void(const M&)> on_message, LogCallback on_log) {
    Subscriber *sub = new Subscriber(cfg_, topic, on_log);
    sub->Subscribe(on_message);
    return sub;
  }
 private:
  struct mosq_config cfg_;

};

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_MQTT_INCLUDE_HANDLER_H_
