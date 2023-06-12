#include "utility.h"


class Tester
{
public:
    // Define subscriber
    ros::Subscriber subCycleTimeInfo;
    // Define Publisher
    ros::Publisher pubCycleTimeInfo;
    ros::NodeHandle nh;
    Tester()
    {
      // receive deskewed cloud_info, then call laserCloudInfoHandler.
      //subCycleTimeInfo = nh.subscribe<ros::Time>("lio_sam/init_time", 1, &Tester::CycleTimeHandler, this, ros::TransportHints().tcpNoDelay());

      pubCycleTimeInfo = nh.advertise<ros::Time> ("lio_sam/end_time", 1);
    }

    void CycleTimeHandler(const ros::Time& time)
    {

    }

};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "lio_sam");

    Tester TS;

    ROS_INFO("\033[1;32m----> Project_Timer Started.\033[0m");
    
    ros::spin();

    return 0;
}

/*
adjusting resolution of raw lidar points or skip some frames,

based on the speed of slam processing
(e.g slower than required rate of processing, downsample lidar points or cropping sample for region of interest)
or based on the resource utilization
(e.g slam is allocated 40% of budget but overrunning)



1. 
  a. LiDAR Point Rejection Based on IMU (or Wheel Odom) 
  b. LiDAR Point Rejection from the info composed with the previous map and IMU. 
2. How to skip frames
  a. Uniformly control the frame rate (i.e. 10Hz -> 3Hz)
  b. Addaptively control the frame rate (i.e. 10Hz -> 10Hz -> 10Hz to 8Hz -> 3Hz -> 9Hz)
    1) occluded region clustering and 
3. Measure the speed of slam processing? depend on updating Hz.
4. Location of stored map data
  a. There exist KeyFrame. Try to find Local Map
  b. Global Map: Summation of Local Maps. 

*/

/*
1-1. How to adjust resolution of raw lidar points.
  - Definition of Adjusting Resolution of LiDAR Points.
1-2. How to control the Frames.
  - Definition of Frames.
2-1. SLAM PROCESSING

2-2. Resource Utilization
  - 
*/