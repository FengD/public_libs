// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "mqtt_subscriber.h"
#include "mqtt_client.h"

namespace itd {
namespace communication {

MqttSubscriber::MqttSubscriber(int32_t keep_alive,
                               std::string host,
                               int32_t port,
                               std::string topic,
                               std::string username,
                               std::string password) {
  mqtt_client_ = new MqttClient();
  mqtt_client_->SetHost(host);
  mqtt_client_->SetPort(port);
  mqtt_client_->SetKeepAlive(keep_alive);
  mqtt_client_->SetUserName(username);
  mqtt_client_->SetPassword(password);
  mosquitto_lib_init();
  mosq_ = mosquitto_new(NULL, true, NULL);
  if (mqtt_client_->ConnectClient(mosq_) < 0) {
    printf("Error: client connect failed.\n");
    return;
  }
  topic_ = topic;
}

MqttSubscriber::~MqttSubscriber() {
  mqtt_client_->DisconnectClient(mosq_);
  delete mqtt_client_;
}

void MqttSubscriber::Subscribe() {
  mosquitto_subscribe(mosq_, NULL, topic_.c_str(), 0);
  mosquitto_loop_forever(mosq_, -1, 1);
}

void MqttSubscriber::SetOnMessage(void (*on_message)(struct mosquitto *, void *, const struct mosquitto_message *)) {
  mosquitto_message_callback_set(mosq_, on_message);
}

void MqttSubscriber::SetOnSubscribe(void (*on_subscribe)(struct mosquitto *, void *, int, int, const int *)) {
  mosquitto_subscribe_callback_set(mosq_, on_subscribe);
}

void MqttSubscriber::SetOnLog(void (*on_log)(struct mosquitto *, void *, int, const char *)) {
  mosquitto_log_callback_set(mosq_, on_log);
}

void MqttSubscriber::SetOnUnsubscribe(void (*on_unsubscribe)(struct mosquitto *, void *, int)) {
  mosquitto_unsubscribe_callback_set(mosq_, on_unsubscribe);
}


}  // namespace communication
}  // namespace itd
