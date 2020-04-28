// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef _ITD_IPD_LIBS_COMMUNICATION_MQTT_MQTT_SUBSCRIBER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_MQTT_MQTT_SUBSCRIBER_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>
#include "mqtt_config.h"

namespace itd {
namespace communication {

class MqttClient;
class MqttSubscriber {
 public:
  MqttSubscriber(std::string host, int32_t port,
	             std::string username = "", std::string password = "");
  MqttSubscriber(struct mosq_config cfg);
  ~MqttSubscriber();
  void Subscribe(std::string topic);
  void SetOnMessage(MessageCallback mcb);
  void SetOnSubscribe(SubscribeCallback scb);
  void SetOnLog(LogCallback lcb);
  void SetOnUnsubscribe(UnsubscribeCallback ucb);
  void Spin();
  void NotSpin();

 private:
  struct mosquitto *mosq_;
  MqttClient *mqtt_client_;
  struct mosq_config cfg_;

  MessageCallback mcb_;
  SubscribeCallback scb_;
  LogCallback lcb_;
  UnsubscribeCallback ucb_;

  static void OnMessage(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);
  static void OnSubscribe(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos);
  static void OnLog(struct mosquitto *mosq, void *obj, int level, const char *str);
  static void OnUnsubscribe(struct mosquitto *mosq, void *obj, int mid);
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_MQTT_SUBSCRIBER_H_
