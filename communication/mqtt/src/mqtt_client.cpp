// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "mqtt_client.h"
#include <string.h>
#include <functional>
#include "error_code.h"
// This value defines the period that the broker send a ping message if the
// client do not receive any message.
#define KEEP_ALIVE 60

namespace itd {
namespace communication {

MqttClient::MqttClient(struct mosq_config cfg) {
  cfg_ = cfg;
  mosquitto_lib_init();
}

MqttClient::~MqttClient() {
  mosquitto_lib_cleanup();
}

int32_t MqttClient::ConnectClient(struct mosquitto *mosq, void (*on_connect)(struct mosquitto *, void *, int)) {
  if (on_connect != nullptr) {
    mosquitto_connect_callback_set(mosq, on_connect);
  } else {
    mosquitto_connect_callback_set(mosq, OnConnect);
  }

  mosquitto_disconnect_callback_set(mosq, OnDisconnect);
  if (!mosq) {
    printf("Error: Create client failed.\n");
    mosquitto_lib_cleanup();
    return ERR_MQTT_INIT;
  }

  if ((!cfg_.username.empty() || !cfg_.password.empty()) &&
       mosquitto_username_pw_set(mosq, cfg_.username.c_str(), cfg_.password.c_str())) {
    printf("Error: Problem setting username and/or password.\n");
    mosquitto_lib_cleanup();
    return ERR_MQTT_USER_PWD;
  }

  if (mosquitto_connect(mosq, cfg_.host.c_str(), cfg_.port, KEEP_ALIVE)) {
    printf("Error: Unable to connect.\n");
    mosquitto_lib_cleanup();
    return ERR_MQTT_CONNECT;
  }

  return NO_ERROR;
}

void MqttClient::OnConnect(struct mosquitto *mosq, void *obj, int mid) {
  mosquitto_threaded_set(mosq, true);
  printf("Client Connected. %p mid: %d\n", obj, mid);
}

void MqttClient::OnDisconnect(struct mosquitto *mosq, void *obj, int mid) {
  (void)mosq;
  printf("Client Disconnected. %p mid: %d\n", obj, mid);
}

}  // namespace communication
}  // namespace itd
