// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef _ITD_IPD_LIBS_COMMUNICATION_MQTT_HANDLER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_MQTT_HANDLER_H_

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
  Handler(std::string host, int32_t port,
          std::string username = "", std::string password = "");
  ~Handler();

  template<class M>
  Publisher advertise(const std::string &topic) {
    return Publisher(cfg_, topic);
  }

  template<class M>
  Publisher advertise(const std::string &topic,
                      LogCallback on_log) {
    return Publisher(cfg_, topic, on_log);
  }

  template<class M>
  Subscriber subscribe(const std::string &topic, void (*on_message)(const M&)) {
    Subscriber sub(cfg_, topic);
    sub.Subscribe(on_message);
    return sub;
  }

  template<class M>
  Subscriber subscribe(const std::string &topic, void (*on_message)(const M&), LogCallback on_log) {
    Subscriber sub(cfg_, topic, on_log);
    sub.Subscribe(on_message);
    return sub;
  }
 private:
  struct mosq_config cfg_;

};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_HANDLER_H_
