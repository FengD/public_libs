// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "mqtt_client.h"
#include <string.h>
#include <functional>
#include "error_code.h"

namespace itd {
namespace communication {

MqttClient::MqttClient() {
  cfg_.port = -1;
  cfg_.keep_alive = 60;
  cfg_.host = "";
  cfg_.username = "";
  cfg_.password = "";
}

MqttClient::~MqttClient() = default;

int32_t MqttClient::ConnectClient(struct mosquitto *mosq) {
  mosquitto_connect_callback_set(mosq, OnConnect);
  mosquitto_disconnect_callback_set(mosq, OnDisconnect);
  if (!mosq) {
    printf("Error: Create client failed.\n");
    mosquitto_lib_cleanup();
    return ERR_MQTT_INIT;
  }

  if (mosquitto_connect(mosq, cfg_.host.c_str(), cfg_.port, cfg_.keep_alive)) {
    printf("Error: Unable to connect.\n");
    mosquitto_lib_cleanup();
    return ERR_MQTT_CONNECT;
  }

  if((!cfg_.username.empty() || !cfg_.password.empty()) &&
      mosquitto_username_pw_set(mosq, cfg_.username.c_str(), cfg_.password.c_str())){
		printf("Error: Problem setting username and/or password.\n");
		mosquitto_lib_cleanup();
		return ERR_MQTT_USER_PWD;
	}

  return NO_ERROR;
}

void MqttClient::DisconnectClient(struct mosquitto *mosq) {
  mosquitto_destroy(mosq);
  mosquitto_lib_cleanup();
}

void MqttClient::SetHost(const std::string &host) {
  cfg_.host = host;
}

void MqttClient::SetPort(const int32_t &port) {
  cfg_.port = port;
}

void MqttClient::SetKeepAlive(const int32_t &keep_alive) {
  cfg_.keep_alive = keep_alive;
}

void MqttClient::SetUserName(const std::string &username) {
  cfg_.username = username;
}

void MqttClient::SetPassword(const std::string &password) {
  cfg_.password = password;
}

void MqttClient::OnConnect(struct mosquitto *mosq, void *obj, int rc) {
  (void)obj;
  (void)(rc);
  (void)(mosq);
  printf("Client Connected.\n");
}

void MqttClient::OnDisconnect(struct mosquitto *mosq, void *obj, int rc) {
  (void)(obj);
  (void)(rc);
  (void)(mosq);
  printf("Client Disconnected.\n");
}

}  // namespace communication
}  // namespace itd
