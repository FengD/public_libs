// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "publisher.h"

namespace itd {
namespace communication {

Publisher::Publisher() {
  output_buffer_ = "";
}

Publisher::Publisher(struct mosq_config cfg, std::string topic) {
  mqtt_publisher_ = new MqttPublisher(cfg, topic);
}

Publisher::Publisher(struct mosq_config cfg, std::string topic, LogCallback on_log) {
  mqtt_publisher_ = new MqttPublisher(cfg, topic);
  mqtt_publisher_->SetOnLog(on_log);
}

Publisher::~Publisher() {
  delete mqtt_publisher_;
}


}  // namespace communication
}  // namespace itd
