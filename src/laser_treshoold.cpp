#include <laser_treshoold/laser_treshoold.hpp>

//consrtuctor

LaserTreshoold::LaserTreshoold(ros::NodeHandle &nh)
{
    nodehandle_ = nh;
    scan_sub_ = nodehandle_.subscribe("scan", 1, &LaserTreshoold::scanCallback, this);
    scan_pub_ = nodehandle_.advertise<sensor_msgs::LaserScan>("treshoold", 1000);
    nodehandle_.getParam("/threshoold_value",threshold_string_value_);
    threshold_value_= atof(threshold_string_value_.c_str());
}

// Destructor
LaserTreshoold::~LaserTreshoold(){}

// Init
void LaserTreshoold::init(){}

//ScanCallback implementation
//void LaserTreshoold::scanCallback(sensor_msgs::LaserScan scan_msg)
void LaserTreshoold::scanCallback(const sensor_msgs::LaserScan &scan_msg)
{
   //final_scan_msgs_ = * scan_msg;
    final_scan_msgs_.header = scan_msg.header;
    final_scan_msgs_.angle_min = scan_msg.angle_min;
    final_scan_msgs_.angle_max = scan_msg.angle_max;
    final_scan_msgs_.angle_increment = scan_msg.angle_increment;
    final_scan_msgs_.time_increment = scan_msg.time_increment;
    final_scan_msgs_.scan_time = scan_msg.scan_time;
    final_scan_msgs_.range_min = scan_msg.range_min;
    final_scan_msgs_.range_max = scan_msg.range_max;
    final_scan_msgs_.intensities = scan_msg.intensities;

    for(contador=0;contador<=scan_msg.ranges.size();contador++)
    {
        if(scan_msg.ranges[contador]>threshold_value_)
        {
            final_scan_msgs_.ranges[contador]=0;
        }
        else
        {
            final_scan_msgs_.ranges[contador]=scan_msg.ranges[contador];
        }
    }
    scan_pub_.publish(final_scan_msgs_);
}

