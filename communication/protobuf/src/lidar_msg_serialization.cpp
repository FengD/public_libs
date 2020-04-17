// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg serialization

#include "lidar_msg_serialization.h"

namespace itd {
namespace communication {
int LidarMsgSerialization::CloudSerialization(const pcl::PointCloud<pcl::PointXYZI> &cloud,
                                              char *output_buffer, int filter_size) {
  if (filter_size == 0) {
    printf("error filter_size\n");
    return -1;
  }
  itd::communication::protobuf::Message out_msg;
  itd::communication::protobuf::PointCloud *proto_cloud = new itd::communication::protobuf::PointCloud();
  int cloud_size = cloud.size();
  proto_cloud->set_height(1);
  proto_cloud->set_width(cloud_size / filter_size);
  for (int i = 0; i < cloud_size; i += filter_size) {
    proto_cloud->add_x(cloud.points[i].x);
    proto_cloud->add_y(cloud.points[i].y);
    proto_cloud->add_z(cloud.points[i].z);
    proto_cloud->add_intensity(cloud.points[i].intensity);
    proto_cloud->add_time_offset(cloud.points[i].data[3]);
    proto_cloud->add_azimuth(cloud.points[i].data_c[1]);
    proto_cloud->add_ring(cloud.points[i].data_c[2]);
    proto_cloud->add_hor(cloud.points[i].data_c[3]);
  }

  out_msg.set_type(itd::communication::protobuf::Message_MessageType_PointCloud);
  out_msg.set_allocated_cloud(proto_cloud);
  int out_size = out_msg.ByteSize();
  memset(output_buffer, 0, out_size * sizeof(char));
  out_msg.SerializeToArray(output_buffer, out_size);
  return out_size;
}

int LidarMsgSerialization::FsSerialization(const float *fs, char *output_buffer) {
  itd::communication::protobuf::Message out_msg;
  itd::communication::protobuf::Freespace *freespace = new itd::communication::protobuf::Freespace();

  for (int i = 0; i < 360; i++) {
    freespace->add_distance(fs[i]);
  }

  out_msg.set_type(itd::communication::protobuf::Message_MessageType_Freespace);
  out_msg.set_allocated_fs(freespace);
  int out_size = out_msg.ByteSize();
  memset(output_buffer, 0, out_size * sizeof(char));
  out_msg.SerializeToArray(output_buffer, out_size);
  return out_size;
}

}  // namespace itd
}  // namespace communication
