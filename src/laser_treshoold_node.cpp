#include <laser_treshoold/laser_treshoold.hpp>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "laser_treshoold");
  ros::NodeHandle n;

  LaserTreshoold laser_scan_threshoold(n);
  laser_scan_threshoold.init();

  ros::spin();
  return 0;
}
