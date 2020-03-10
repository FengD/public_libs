#include <pcl/point_cloud.h>
#include <pcl/common/common.h>
#include "synchronizer.h"

template class itd::Synchronizer<pcl::PointCloud<pcl::PointXYZI>, pcl::PointCloud<pcl::PointXYZI>>;
