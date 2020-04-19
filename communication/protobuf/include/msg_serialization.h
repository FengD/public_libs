// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg serialization

#ifndef _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_SERIALIZATION_H_
#define _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_SERIALIZATION_H_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "msg.pb.h"

namespace itd {
namespace communication {
class MsgSerialization {
 public:
  static bool CloudSerialization(const pcl::PointCloud<pcl::PointXYZI> &cloud,
                                 std::string &output_buffer, int filter_size = 1);

  static bool FsSerialization(const float *fs, std::string &output_buffer);

  static bool BridgeSerialization(const float &k,
                                  const float &b,
                                  const int &flag,
                                  std::string &output_buffer);
};

}  // namespace itd
}  // namespace communication

#endif  // _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_LIDAR_MSG_SERIALIZATION_H_
