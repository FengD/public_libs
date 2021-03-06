// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt publisher

#ifndef COMMUNICATION_MQTT_INCLUDE_PUBLISHER_H_
#define COMMUNICATION_MQTT_INCLUDE_PUBLISHER_H_

#include <unistd.h>
#include <stdlib.h>
#include <string>
#include "mqtt_config.h"
#include "mqtt_publisher.h"

namespace itd {
namespace communication {

// The Publisher should always be created through a call to hander::advertise(),
// or copied from one that was.
class Publisher {
 public:
  Publisher();

  Publisher(struct mosq_config cfg, std::string topic);

  Publisher(struct mosq_config cfg, std::string topic, LogCallback on_log);

  ~Publisher();

  template<class M>
  void Publish(const M& message, const int32_t &qos = 0) {
    message.SerializeToString(&output_buffer_);
    mqtt_publisher_->Publish(output_buffer_.c_str(), output_buffer_.length(), qos);
  }

 private:
  MqttPublisher *mqtt_publisher_;
  std::string output_buffer_;
};

}  // namespace communication
}  // namespace itd

#endif  // COMMUNICATION_MQTT_INCLUDE_PUBLISHER_H_
