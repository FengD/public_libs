// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg transform

#ifndef _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_TRANSFORMER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_TRANSFORMER_H_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "itd_ipd_geometry_msgs.pb.h"
#include "itd_ipd_std_msgs.pb.h"
#include "itd_ipd_sensor_msgs.pb.h"


namespace itd {
namespace communication {
class MsgTransformer {
 public:
  static void ToItdPointCloud(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
                                 itd::communication::protobuf::PointCloud &cloud_out);

  static void ToItdPointCloudXYZ(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
                                 itd::communication::protobuf::PointCloud &cloud_out);

  static void ToItdPointCloudXYZI(const pcl::PointCloud<pcl::PointXYZI> &cloud_in,
                                  itd::communication::protobuf::PointCloud &cloud_out);

  static void FromItdPointCloud(const itd::communication::protobuf::PointCloud &cloud_in,
                                pcl::PointCloud<pcl::PointXYZI> &cloud_out);

  static void FromItdPointCloudXYZ(const itd::communication::protobuf::PointCloud &cloud_in,
                                   pcl::PointCloud<pcl::PointXYZ> &cloud_out);

  static void FromItdPointCloudXYZI(const itd::communication::protobuf::PointCloud &cloud_in,
                                    pcl::PointCloud<pcl::PointXYZI> &cloud_out);

  static void ToItdFs(const float *fs_in, itd::communication::protobuf::Freespace &fs_out);
  //
  static void ToItdBoundary(const float &k, const float &b, const int &flag,
                            itd::communication::protobuf::Boundary &boundary_out);
  //
  static void ToItdSignboard(const float &k, const float &b, const float &x, const float &y, const int &type,
                            itd::communication::protobuf::Signboard &signboard_out);
  //
  static void ToItdTrailer(const float &k, const float &b, const int &flag,
                          itd::communication::protobuf::Trailer &trailer_out);
  //
  static void ToItdBridge(const float &k, const float &b, const int &flag,
                          itd::communication::protobuf::Bridge &bridge_out);

  static void ToItdGrabber(const int &grabber_left_angle, const float &grabber_left_obstacle_dis,
                           const int &grabber_right_angle, const float &grabber_right_obstacle_dis,
                           itd::communication::protobuf::Grabber &grabber_out);

  static void ToItdContainer(const int &front_container_flag, const float &front_container_dis,
                                  itd::communication::protobuf::Container &container_out);

};

}  // namespace itd
}  // namespace communication

#endif  // _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_TRANSFORMER_H_
