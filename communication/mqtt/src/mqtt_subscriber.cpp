// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "mqtt_subscriber.h"
#include "mqtt_client.h"

namespace itd {
namespace communication {

// MqttSubscriber::MqttSubscriber() {}

MqttSubscriber::MqttSubscriber(std::string host, int32_t port, std::string topic,
                               std::string username, std::string password) {
  cfg_.port = port;
  cfg_.host = host;
  cfg_.username = username;
  cfg_.password = password;
  topic_ = topic;
  mqtt_client_ = new MqttClient(cfg_);
  mosq_ = mosquitto_new(NULL, true, this);
  topic_ = topic;
  if (mqtt_client_->ConnectClient(mosq_, OnConnect) < 0) {
    printf("Error: client connect failed.\n");
    return;
  }
}

MqttSubscriber::MqttSubscriber(struct mosq_config cfg, std::string topic) {
  cfg_ = cfg;
  topic_ = topic;
  mqtt_client_ = new MqttClient(cfg_);
  mosq_ = mosquitto_new(NULL, true, this);
  if (mqtt_client_->ConnectClient(mosq_, OnConnect) < 0) {
    printf("Error: client connect failed.\n");
    return;
  }
}

MqttSubscriber::~MqttSubscriber() {
  delete mqtt_client_;
}

void MqttSubscriber::Subscribe() {
  mosquitto_subscribe(mosq_, NULL, topic_.c_str(), 0);
}

void MqttSubscriber::Spin() {
  mosquitto_loop_forever(mosq_, -1, 1);
}

void MqttSubscriber::NotSpin() {
  mosquitto_loop_start(mosq_);
}

void MqttSubscriber::SetOnMessage(MessageCallback mcb) {
  mcb_ = mcb;
  mosquitto_message_callback_set(mosq_, OnMessage);
}

void MqttSubscriber::SetOnSubscribe(SubscribeCallback scb) {
  scb_ = scb;
  mosquitto_subscribe_callback_set(mosq_, OnSubscribe);
}

void MqttSubscriber::SetOnLog(LogCallback lcb) {
  lcb_ = lcb;
  mosquitto_log_callback_set(mosq_, OnLog);
}

void MqttSubscriber::SetOnUnsubscribe(UnsubscribeCallback ucb) {
  ucb_ = ucb;
  mosquitto_unsubscribe_callback_set(mosq_, OnUnsubscribe);
}

void MqttSubscriber::OnMessage(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message) {
  (void) mosq;
  MqttSubscriber *self = static_cast<MqttSubscriber*>(obj);
  self->mcb_(message->payloadlen, message->payload);
}

void MqttSubscriber::OnSubscribe(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos) {
  (void) mosq;
  (void) granted_qos;
  MqttSubscriber *self = static_cast<MqttSubscriber*>(obj);
  self->scb_(mid, qos_count);
}

void MqttSubscriber::OnLog(struct mosquitto *mosq, void *obj, int level, const char *str) {
  (void) mosq;
  MqttSubscriber *self = static_cast<MqttSubscriber*>(obj);
  self->lcb_(level, str);
}

void MqttSubscriber::OnUnsubscribe(struct mosquitto *mosq, void *obj, int mid) {
  (void) mosq;
  MqttSubscriber *self = static_cast<MqttSubscriber*>(obj);
  self->ucb_(mid);
}

void MqttSubscriber::OnConnect(struct mosquitto *mosq, void *obj, int mid) {
  mosquitto_threaded_set(mosq, true);
  MqttSubscriber *self = static_cast<MqttSubscriber*>(obj);
  self->Subscribe();
  printf("Subscriber Connected. %p mid: %d\n", obj, mid);
}


}  // namespace communication
}  // namespace itd
