#include "ros/ros.h"
#include "topic/Person.h"


void doPerson(const topic::Person::ConstPtr &person){
    ROS_INFO("Subscrib message: %s, %d, %.2f",person->name.c_str(), person->age,person->height);

}


int main(int argc, char *argv[]){


    ros::init(argc, argv,"Subscribe");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter",10,doPerson);

    ros::spin();
    return 0;
}