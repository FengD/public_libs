// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt publisher

#ifndef _ITD_IPD_LIBS_COMMUNICATION_MQTT_PUBLISHER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_MQTT_PUBLISHER_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>

namespace itd {
namespace communication {

class MqttClient;

class MqttPublisher {
 public:
  MqttPublisher(int32_t keep_alive,
                std::string host,
                int32_t port,
                std::string topic,
	              std::string username = "",
	              std::string password = "");

  ~MqttPublisher();
  void Publish(const void *payload, const int32_t &payloadlen);
  void SetOnPublish(void (*on_publish)(struct mosquitto *, void *, int));
  void SetOnLog(void (*on_log)(struct mosquitto *, void *, int, const char *));

 private:
  struct mosquitto *mosq_;
  MqttClient *mqtt_client_;
  std::string topic_;
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_PUBLISHER_H_
