// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt publisher

#ifndef COMMUNICATION_MQTT_INCLUDE_SUBSCRIBER_H_
#define COMMUNICATION_MQTT_INCLUDE_SUBSCRIBER_H_

#include <unistd.h>
#include <stdlib.h>
#include <string>
#include "mqtt_config.h"
#include "mqtt_subscriber.h"

namespace itd {
namespace communication {

// The Subscriber should always be created through a call to hander::subscribe(),
// or copied from one that was.
class Subscriber {
 public:
  Subscriber();

  Subscriber(struct mosq_config cfg, std::string topic, const int32_t &qos = 0);

  Subscriber(struct mosq_config cfg, std::string topic, LogCallback on_log, const int32_t &qos = 0);

  // One of Spin ot Nospin should be used.
  // Spin is to create a thread and block
  // Notspin is to create a thread but still going on
  void Spin();

  void NotSpin();

  ~Subscriber();

  template<class M>
  void Subscribe(void (*on_message)(const M&)) {
     MessageCallback mcb = [=](int payloadlen, const void *payload) {
       M message;
       message.ParseFromArray((char *)payload, payloadlen);
       on_message(message);
     };
     mqtt_subscriber_->SetOnMessage(mcb);
  }

  template<class M>
  void Subscribe(std::function<void(const M&)> on_message) {
     MessageCallback mcb = [=](int payloadlen, const void *payload) {
       M message;
       message.ParseFromArray((char *)payload, payloadlen);
       on_message(message);
     };
     mqtt_subscriber_->SetOnMessage(mcb);
  }

 private:
  MqttSubscriber *mqtt_subscriber_;
};

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_MQTT_INCLUDE_SUBSCRIBER_H_
