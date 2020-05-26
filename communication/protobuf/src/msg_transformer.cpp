// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg serialization

#include "msg_transformer.h"

namespace itd {
namespace communication {
void MsgTransformer::ToItdPointCloud(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
                                     itd::communication::protobuf::PointCloud &cloud_out) {
  ToItdPointCloudXYZI(cloud_in, cloud_out);
  int cloud_size = cloud_in.size();
  for (int i = 0; i < cloud_size; i++) {
    cloud_out.add_time_offset(cloud_in.points[i].data[3]);
    cloud_out.add_azimuth(cloud_in.points[i].data_c[1]);
    cloud_out.add_ring(cloud_in.points[i].data_c[2]);
    cloud_out.add_hor(cloud_in.points[i].data_c[3]);
  }
}

void MsgTransformer::ToItdPointCloudXYZ(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
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
  }
}

void MsgTransformer::ToItdPointCloudXYZI(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
                         itd::communication::protobuf::PointCloud &cloud_out) {
  ToItdPointCloudXYZ(cloud_in, cloud_out);
  int cloud_size = cloud_in.size();
  for (int i = 0; i < cloud_size; i++) {
    cloud_out.add_intensity(cloud_in.points[i].intensity);
  }
}

void MsgTransformer::FromItdPointCloud(const itd::communication::protobuf::PointCloud &cloud_in,
                                       pcl::PointCloud<pcl::PointXYZI> &cloud_out) {
  cloud_out.clear();
  cloud_out.header.seq = cloud_in.header().seq();
  cloud_out.header.stamp = cloud_in.header().stamp();
  cloud_out.header.frame_id = cloud_in.header().frame_id();
  int cloud_size = cloud_in.width();

  for (int i = 0; i < cloud_size; i++) {
    pcl::PointXYZI p;
    p.x = cloud_in.x()[i];
    p.y = cloud_in.y()[i];
    p.z = cloud_in.z()[i];
    p.intensity = cloud_in.intensity()[i];
    p.data[3] = cloud_in.time_offset()[i];
    p.data_c[1] = cloud_in.azimuth()[i];
    p.data_c[2] = cloud_in.ring()[i];
    p.data_c[3] = cloud_in.hor()[i];
    cloud_out.push_back(std::move(p));
  }
}

void MsgTransformer::FromItdPointCloudXYZ(const itd::communication::protobuf::PointCloud &cloud_in,
                                          pcl::PointCloud<pcl::PointXYZ> &cloud_out) {
  cloud_out.clear();
  cloud_out.header.seq = cloud_in.header().seq();
  cloud_out.header.stamp = cloud_in.header().stamp();
  cloud_out.header.frame_id = cloud_in.header().frame_id();
  int cloud_size = cloud_in.width();

  for (int i = 0; i < cloud_size; i++) {
    pcl::PointXYZ p;
    p.x = cloud_in.x()[i];
    p.y = cloud_in.y()[i];
    p.z = cloud_in.z()[i];
    cloud_out.push_back(std::move(p));
  }
}

void MsgTransformer::FromItdPointCloudXYZI(const itd::communication::protobuf::PointCloud &cloud_in,
                                           pcl::PointCloud<pcl::PointXYZI> &cloud_out) {
  cloud_out.clear();
  cloud_out.header.seq = cloud_in.header().seq();
  cloud_out.header.stamp = cloud_in.header().stamp();
  cloud_out.header.frame_id = cloud_in.header().frame_id();
  int cloud_size = cloud_in.width();

  for (int i = 0; i < cloud_size; i++) {
    pcl::PointXYZI p;
    p.x = cloud_in.x()[i];
    p.y = cloud_in.y()[i];
    p.z = cloud_in.z()[i];
    p.intensity = cloud_in.intensity()[i];
    cloud_out.push_back(std::move(p));
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

void MsgTransformer::ToItdBoundary(const float &k, const float &b, const int &flag,
                                   itd::communication::protobuf::Boundary &boundary_out) {
  boundary_out.Clear();
  boundary_out.set_k(k);
  boundary_out.set_b(b);
  boundary_out.set_flag(flag);
}

void MsgTransformer::ToItdSignboard(const float &k, const float &b, const float &x, const float &y,
                                    const int &type, itd::communication::protobuf::Signboard &signboard_out) {
  signboard_out.Clear();
  signboard_out.set_k(k);
  signboard_out.set_b(b);
  signboard_out.set_x(x);
  signboard_out.set_y(y);
  signboard_out.set_type(type);
}

void MsgTransformer::ToItdTrailer(const float &k, const float &b, const int &flag,
                                  itd::communication::protobuf::Trailer &trailer_out) {
  trailer_out.Clear();
  trailer_out.set_k(k);
  trailer_out.set_b(b);
  trailer_out.set_flag(flag);
}

void MsgTransformer::ToItdGrabber(const int &grabber_left_angle, const float &grabber_left_obstacle_dis,
                                  const int &grabber_right_angle, const float &grabber_right_obstacle_dis,
                                  itd::communication::protobuf::Grabber &grabber_out) {
  grabber_out.Clear();
  grabber_out.set_left_angle(grabber_left_angle);
  grabber_out.set_left_obstacle_dis(grabber_left_obstacle_dis);
  grabber_out.set_right_angle(grabber_right_angle);
  grabber_out.set_right_obstacle_dis(grabber_right_obstacle_dis);

}

void MsgTransformer::ToItdContainer(const int &front_container_flag, const float &front_container_dis,
                                    itd::communication::protobuf::Container &container_out) {
  container_out.Clear();
  container_out.set_flag(front_container_flag);
  container_out.set_distance(front_container_dis);
}

void MsgTransformer::ToItdCanMessage(const long &id, const double *value, const int &value_size,
                                     itd::communication::protobuf::CanSignal &signal) {
  signal.Clear();
  signal.set_id(id);
  signal.set_nb_signal(value_size);
  for (int i = 0; i < value_size; i++) {
    signal.add_signal(value[i]);
  }
}

}  // namespace itd
}  // namespace communication
