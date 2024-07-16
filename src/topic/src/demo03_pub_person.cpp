#include "ros/ros.h"
#include "topic/Person.h"



int main(int argc, char *argv[]){

    ros::init(argc, argv,"Person");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<topic::Person>("chatter",10);

    // 设置数据
    topic::Person person;
    person.name = "Leslie";
    person.age = 25;
    person.height =176.00;

    ros::Rate rate(1);

    while(ros::ok()){
        //数据发布
        pub.publish(person);
        ROS_INFO("publish Person: name = %s, age = %d, height = %.2f", person.name.c_str(), person.age, person.height);
        //休眠
        rate.sleep();
        //回调函数
        ros::spinOnce();
    }
    return 0;
}