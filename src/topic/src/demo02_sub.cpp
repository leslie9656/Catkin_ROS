#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


void doMsg(const std_msgs::String::ConstPtr &msg){
    //通过msg参数获取并操作订阅到的数据
    ROS_INFO("the data is %s",msg->data.c_str());    
}


int main(int argc, char *argv[]){
    ros::init(argc, argv,"Subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter",10,doMsg);
    
    ros::spin(); // 循环等待接收数据并执行回调函数
    return 0;
}