// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "hi_mqtt.h"
#include "error_code.h"

namespace itd {
namespace communication {

HiMqtt::HiMqtt() : host_("localhost"), port_(1883), alive_time_(60) {}
HiMqtt::~HiMqtt() {
  mosquitto_destroy(mosq_);
  mosquitto_lib_cleanup();
}

int HiMqtt::Init() {
  mosquitto_lib_init();

  mosq_ = mosquitto_new(NULL, true, NULL);
  if (!mosq_) {
      printf("create client failed..\n");
      mosquitto_lib_cleanup();
      return ERR_INIT;
  }

  if (mosquitto_connect(mosq_, host_.c_str(), port_, alive_time_)) {
      printf("Unable to connect.\n");
      return CONNECT_ERROR;
  }
  mosquitto_loop_start(mosq_);
  return NO_ERROR;
}

void HiMqtt::SetHost(const std::string host) {
  host_ = host;
}

void HiMqtt::SetPort(const int32_t port) {
  port_ = port;
}

void HiMqtt::SetAliveTime(const int32_t alive_time) {
  alive_time_ = alive_time;
}

void HiMqtt::Publish(const std::string topic, const char *msg, const int32_t msg_size) {
  mosquitto_publish(mosq_, NULL, topic.c_str(), msg_size, msg, 0, 0);
}

void HiMqtt::Subscribe(const std::string topic, std::function<void*(struct mosquitto*, void*, const struct mosquitto_message*)> msg_callback) {
  typedef void function_t(mosquitto*, void*, const mosquitto_message*) ;
  function_t* msg_callback_ptr = msg_callback.target<function_t>() ;
  mosquitto_message_callback_set(mosq_, msg_callback_ptr);
  mosquitto_subscribe(mosq_, NULL, topic.c_str(), 2);
  mosquitto_loop_forever(mosq_, -1, 1);
}

}  // namespace communication
}  // namespace itd
