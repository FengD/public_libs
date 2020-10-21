// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the mqtt connection

#include "subscriber.h"

namespace itd {
namespace communication {

Subscriber::Subscriber() {}

Subscriber::Subscriber(struct mosq_config cfg, std::string topic, const int32_t &qos) {
  mqtt_subscriber_ = new MqttSubscriber(cfg, topic, qos);
}

Subscriber::Subscriber(struct mosq_config cfg, std::string topic, LogCallback on_log, const int32_t &qos) {
  mqtt_subscriber_ = new MqttSubscriber(cfg, topic, qos);
  mqtt_subscriber_->SetOnLog(on_log);
}

Subscriber::~Subscriber() {
  delete mqtt_subscriber_;
}

void Subscriber::Spin() {
  mqtt_subscriber_->Spin();
}

void Subscriber::NotSpin() {
  mqtt_subscriber_->NotSpin();
}


}  // namespace communication
}  // namespace itd
