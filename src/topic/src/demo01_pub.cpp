#include "ros/ros.h"
#include "std_msgs/String.h"    // ROS中的文本类型
#include <sstream>
/*
    发布方实现：
        1.包含头文件
        2.初始化ros节点
        3.创建节点句柄
        4.创建发布方实现
        5. 发布消息

*/

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");

    ros::init(argc,argv,"Publisher");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10);

    std_msgs::String msg;
    //设置发布频率10Hz.

    ros::Rate rate(10);
    int count = 0;

    //休眠3秒    
    ros::Duration(3).sleep();

    while (ros::ok()) {
        // msg.data = "Hello ROS";
        count++;
        std::stringstream ss;

        ss << "Hello ROS " << count;    //字符串拼接
        msg.data = ss.str();

        pub.publish(msg);

        ROS_INFO("发布的数据：%s",ss.str().c_str());
        rate.sleep();
    }

    return 0;   
}