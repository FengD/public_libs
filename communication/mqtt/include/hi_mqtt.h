// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#ifndef _ITD_IPD_LIBS_COMMUNICATION_HI_MQTT_H_
#define _ITD_IPD_LIBS_COMMUNICATION_HI_MQTT_H_

#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <string>
#include <functional>

namespace itd {
namespace communication {

class HiMqtt {
 public:
  HiMqtt();
  ~HiMqtt();
  int Init();
  void SetHost(const std::string host);
  void SetPort(const int32_t port);
  void SetAliveTime(const int32_t alive_time);
  void Publish(const std::string topic, const char *msg, const int32_t msg_size);
  void Subscribe(const std::string topic, std::function<void*(struct mosquitto*, void*, const struct mosquitto_message*)> msg_callback);

 private:
  std::string host_;
  int32_t port_;
  int32_t alive_time_;
  struct mosquitto *mosq_;
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_H_
