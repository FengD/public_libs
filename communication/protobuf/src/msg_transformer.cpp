// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg serialization

#include "msg_transformer.h"

namespace itd {
namespace communication {
void MsgTransformer::ToItdPointCloud(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
                                     itd::communication::protobuf::PointCloud &cloud_out) {

  cloud_out.Clear();
  itd::communication::protobuf::Header *header = new itd::communication::protobuf::Header();
  header->set_seq(cloud_in.header.seq);
  header->set_stamp(cloud_in.header.stamp);
  header->set_frame_id(cloud_in.header.frame_id);
  cloud_out.set_allocated_header(header);
  int cloud_size = cloud_in.size();
  cloud_out.set_height(1);
  cloud_out.set_width(cloud_size);
  for (int i = 0; i < cloud_size; i++) {
    cloud_out.add_x(cloud_in.points[i].x);
    cloud_out.add_y(cloud_in.points[i].y);
    cloud_out.add_z(cloud_in.points[i].z);
    cloud_out.add_intensity(cloud_in.points[i].intensity);
    cloud_out.add_time_offset(cloud_in.points[i].data[3]);
    cloud_out.add_azimuth(cloud_in.points[i].data_c[1]);
    cloud_out.add_ring(cloud_in.points[i].data_c[2]);
    cloud_out.add_hor(cloud_in.points[i].data_c[3]);
  }
}

void MsgTransformer::ToItdFs(const float *fs_in, itd::communication::protobuf::Freespace &fs_out) {
  fs_out.Clear();
  for (int i = 0; i < 360; i++) {
    fs_out.add_distance(fs_in[i]);
  }
}

void MsgTransformer::ToItdBridge(const float &k, const float &b, const int &flag,
                                 itd::communication::protobuf::Bridge &bridge_out) {
  bridge_out.Clear();
  bridge_out.set_k(k);
  bridge_out.set_b(b);
  bridge_out.set_flag(flag);
}

}  // namespace itd
}  // namespace communication
