// Copyright (C) 2020 Hirain Technologies
// License: Modified BSD Software License Agreement
// Author: Feng DING
// Description: This file used to define the protobuf msg transform

#ifndef _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_TRANSFORMER_H_
#define _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_TRANSFORMER_H_

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "msg.pb.h"

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
                                   pcl::PointCloud<pcl::PointXYZI> &cloud_out);

  static void FromItdPointCloudXYZI(const itd::communication::protobuf::PointCloud &cloud_in,
                                    pcl::PointCloud<pcl::PointXYZI> &cloud_out);

  static void ToItdFs(const float *fs_in, itd::communication::protobuf::Freespace &fs_out);
  //
  static void ToItdBridge(const float &k, const float &b, const int &flag,
                          itd::communication::protobuf::Bridge &bridge_out);
};

}  // namespace itd
}  // namespace communication

#endif  // _ITD_IPD_LIBS_COMMUNICATION_PROTOBUF_MSG_TRANSFORMER_H_
