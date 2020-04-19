// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg serialization

#ifndef _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_DESERIALIZATION_H_
#define _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_DESERIALIZATION_H_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "msg.pb.h"

namespace itd {
namespace communication {
class MsgDeserialization {
 public:
  static void CloudDeserialization(const std::string &output_buffer,
                                   pcl::PointCloud<pcl::PointXYZI> &cloud);

  static void FsDeserialization(const std::string &output_buffer, float *fs);
};

}  // namespace itd
}  // namespace communication

#endif  // _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_LIDAR_MSG_SERIALIZATION_H_
