// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef _ITD_IPD_LIBS_COMMUNICATION_MQTT_CLIENT_H_
#define _ITD_IPD_LIBS_COMMUNICATION_MQTT_CLIENT_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>
#include <functional>

namespace itd {
namespace communication {

struct mosq_config {
	int32_t keep_alive;
	std::string host;
	int32_t port;
	std::string username;
	std::string password;
};

class MqttClient {
 public:
  MqttClient();
  ~MqttClient();
  int32_t ConnectClient(struct mosquitto *mosq);
  void DisconnectClient(struct mosquitto *mosq);
  void SetHost(const std::string &host);
  void SetPort(const int32_t &port);
  void SetKeepAlive(const int32_t &keep_alive);
  void SetUserName(const std::string &username);
  void SetPassword(const std::string &password);

 private:
  static void OnConnect(struct mosquitto *mosq, void *obj, int rc);
  static void OnDisconnect(struct mosquitto *mosq, void *obj, int rc);
  struct mosq_config cfg_;
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_CLIENT_H_
