// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg serialization

#include "msg_deserialization.h"

namespace itd {
namespace communication {
void MsgDeserialization::CloudDeserialization(const std::string &output_buffer,
                                              pcl::PointCloud<pcl::PointXYZI> &cloud) {
  itd::communication::protobuf::Message in_msg;
  if (in_msg.ParseFromString(output_buffer)) {
    if (in_msg.type() == itd::communication::protobuf::Message_MessageType_PointCloud) {
      itd::communication::protobuf::PointCloud proto_cloud = in_msg.cloud();
      cloud.header.seq = proto_cloud.header().seq();
      cloud.header.stamp = proto_cloud.header().stamp();
      cloud.header.frame_id = proto_cloud.header().frame_id();
      int cloud_size = proto_cloud.width();
      for (int i = 0; i < cloud_size; i++) {
        pcl::PointXYZI point;
        point.x = proto_cloud.x()[i];
        point.y = proto_cloud.y()[i];
        point.z = proto_cloud.z()[i];
        point.intensity = proto_cloud.intensity()[i];
        point.data[3] = proto_cloud.time_offset()[i];
        point.data_c[1] = proto_cloud.azimuth()[i];
        point.data_c[2] = proto_cloud.ring()[i];
        point.data_c[3] = proto_cloud.hor()[i];
        cloud.push_back(std::move(point));
      }
    }
  }
}

void MsgDeserialization::FsDeserialization(const std::string &output_buffer, float *fs) {
  itd::communication::protobuf::Message in_msg;
  if (in_msg.ParseFromString(output_buffer)) {
    if (in_msg.type() == itd::communication::protobuf::Message_MessageType_Freespace) {
      itd::communication::protobuf::Freespace freespace = in_msg.fs();
      for (int i = 0; i < 360; i++) {
        fs[i] = freespace.distance()[i];
      }
    }
  }
}

}  // namespace itd
}  // namespace communication
