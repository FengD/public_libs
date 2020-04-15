// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "mqtt_publisher.h"
#include "mqtt_client.h"

namespace itd {
namespace communication {

MqttPublisher::MqttPublisher(int32_t keep_alive,
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
  mosquitto_loop_start(mosq_);
}

MqttPublisher::~MqttPublisher() {
  mqtt_client_->DisconnectClient(mosq_);
  delete mqtt_client_;
}

void MqttPublisher::Publish(const void *payload, const int32_t &payloadlen) {
  mosquitto_publish(mosq_, NULL, topic_.c_str(), payloadlen, payload, 0, 0);
}

void MqttPublisher::SetOnPublish(void (*on_publish)(struct mosquitto *, void *, int)) {
  mosquitto_publish_callback_set(mosq_, on_publish);
}

void MqttPublisher::SetOnLog(void (*on_log)(struct mosquitto *, void *, int, const char *)) {
  mosquitto_log_callback_set(mosq_, on_log);
}

}  // namespace communication
}  // namespace itd
