#include <pcl/point_cloud.h>
#include <pcl/common/common.h>
#include "synchronized_queue.h"

template class itd::SynchronizedQueue<pcl::PointCloud<pcl::PointXYZI>>;
