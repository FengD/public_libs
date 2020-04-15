// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef _ITD_IPD_LIBS_COMMUNICATION_MQTT_SUBSCRIBER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_MQTT_SUBSCRIBER_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>
#include <functional>

namespace itd {
namespace communication {

class MqttClient;

class MqttSubscriber {
 public:
  MqttSubscriber(int32_t keep_alive,
                 std::string host,
                 int32_t port,
                 std::string topic,
	               std::string username = "",
	               std::string password = "");
  ~MqttSubscriber();
  void Subscribe();
  void SetOnMessage(void (*on_message)(struct mosquitto *, void *, const struct mosquitto_message *));
  void SetOnSubscribe(void (*on_subscribe)(struct mosquitto *, void *, int, int, const int *));
  void SetOnLog(void (*on_log)(struct mosquitto *, void *, int, const char *));
  void SetOnUnsubscribe(void (*on_unsubscribe)(struct mosquitto *, void *, int));

 private:
  struct mosquitto *mosq_;
  MqttClient *mqtt_client_;
  std::string topic_;
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_SUBSCRIBER_H_
