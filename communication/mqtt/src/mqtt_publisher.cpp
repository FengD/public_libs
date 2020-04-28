// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "mqtt_publisher.h"
#include "mqtt_client.h"

namespace itd {
namespace communication {

MqttPublisher::MqttPublisher(std::string host, int32_t port, std::string topic,
                             std::string username, std::string password) {
  cfg_.port = port;
  cfg_.host = host;
  cfg_.username = username;
  cfg_.password = password;
  MqttPublisher(cfg_, topic);
}

MqttPublisher::MqttPublisher(struct mosq_config cfg, std::string topic) {
  cfg_ = cfg;
  mqtt_client_ = new MqttClient(cfg_);
  mosquitto_lib_init();
  mosq_ = mosquitto_new(NULL, true, this);
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

void MqttPublisher::SetOnPublish(PublishCallback pcb) {
  pcb_ = pcb;
  mosquitto_publish_callback_set(mosq_, OnPublish);
}

void MqttPublisher::SetOnLog(LogCallback lcb) {
  lcb_ = lcb;
  mosquitto_log_callback_set(mosq_, OnLog);
}

void MqttPublisher::OnPublish(struct mosquitto *mosq, void *obj, int mid) {
  (void) mosq;
  MqttPublisher *self = static_cast<MqttPublisher*>(obj);
  self->pcb_(mid);
}

void MqttPublisher::OnLog(struct mosquitto *mosq, void *obj, int level, const char *str) {
  (void) mosq;
  MqttPublisher *self = static_cast<MqttPublisher*>(obj);
  self->lcb_(level, str);
}

}  // namespace communication
}  // namespace itd
