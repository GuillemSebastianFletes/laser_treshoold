#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"
#include <stdio.h>
#include <iostream>
#include <string>

class LaserTreshoold
{

//If something public here methods before args.

public:

    LaserTreshoold(ros::NodeHandle& nh);
    ~LaserTreshoold();

    void scanCallback(const sensor_msgs::LaserScan& scan_msg);
    void init();

    ros::NodeHandle nodehandle_;
    ros::Subscriber scan_sub_;
    ros::Publisher scan_pub_;
    std::string threshold_string_value_;
    sensor_msgs::LaserScan final_scan_msgs_;
    //sensor_msgs::LaserScan scan_msg;
    float threshold_value_;
    int contador;

};
