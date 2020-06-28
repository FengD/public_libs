// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt publisher

#ifndef COMMUNICATION_MQTT_INCLUDE_MQTT_PUBLISHER_H_
#define COMMUNICATION_MQTT_INCLUDE_MQTT_PUBLISHER_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>
#include "mqtt_config.h"

namespace itd {
namespace communication {

class MqttClient;
class MqttPublisher {
 public:
  MqttPublisher(std::string host, int32_t port, std::string topic,
                std::string username = "", std::string password = "");
  MqttPublisher(struct mosq_config cfg, std::string topic);

  ~MqttPublisher();
  void Publish(const void *payload, const int32_t &payloadlen);
  void SetOnPublish(PublishCallback pcb);
  void SetOnLog(LogCallback lcb);

 private:
  struct mosquitto *mosq_;
  MqttClient *mqtt_client_;
  std::string topic_;
  struct mosq_config cfg_;

  PublishCallback pcb_;
  LogCallback lcb_;

  static void OnPublish(struct mosquitto *mosq, void *obj, int mid);
  static void OnLog(struct mosquitto *mosq, void *obj, int level, const char *str);
};

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_MQTT_INCLUDE_MQTT_PUBLISHER_H_
