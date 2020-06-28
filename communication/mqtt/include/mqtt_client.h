// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef COMMUNICATION_MQTT_INCLUDE_MQTT_CLIENT_H_
#define COMMUNICATION_MQTT_INCLUDE_MQTT_CLIENT_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>
#include <functional>
#include "mqtt_config.h"

namespace itd {
namespace communication {

class MqttClient {
 public:
  MqttClient(struct mosq_config cfg);
  ~MqttClient();
  int32_t ConnectClient(struct mosquitto *mosq, void (*on_connect)(struct mosquitto *, void *, int) = NULL);

 private:
  static void OnConnect(struct mosquitto *mosq, void *obj, int mid);
  static void OnDisconnect(struct mosquitto *mosq, void *obj, int mid);
  struct mosq_config cfg_;
};

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_MQTT_INCLUDE_MQTT_CLIENT_H_
