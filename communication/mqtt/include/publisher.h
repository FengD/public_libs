// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt publisher

#ifndef _ITD_IPD_LIBS_COMMUNICATION_MQTT_PUBLISHER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_MQTT_PUBLISHER_H_

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
  void Publish(const M& message) {
    message.SerializeToString(&output_buffer_);
    mqtt_publisher_->Publish(output_buffer_.c_str(), output_buffer_.length());
  }

 private:
  MqttPublisher *mqtt_publisher_;
  std::string output_buffer_;
};

}  // namespace communication
}  // namespace itd

#endif  // _ITD_IPD_LIBS_COMMUNICATION_MQTT_PUBLISHER_H_
