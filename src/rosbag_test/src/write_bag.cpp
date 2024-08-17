#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[]){
    ros::init(argc,argv,"bag_write");
    ros::NodeHandle nh;

    rosbag::Bag bag;

    // open bag
    bag.open("/home/Catkin_ros/src/rosbag_test/data/test.bag",
    rosbag::BagMode::Write);

    //write bag
    std_msgs::String msg;

    msg.data = "hello_world";
    bag.write("/chatter",ros::Time::now(),msg);

    bag.close();

    return 0;
}