#include "ros/ros.h"


/*
需要实现参数的新增和修改
需求：首先设置机器人的共享参数，类型，半径（0.15m）
     再修改半径参数（0.2m）
实现：
    ros::NodeHandle
        setParam(key,value)
    ros::param
        set(key,value)
*/

int main(int argc, char *argv[]){
    ros::init(argc,argv,"param_server");

    ros::NodeHandle nh;

    // 参数增
    // api 1:
    nh.setParam("type","huangche");
    nh.setParam("radius",0.15);
    // api 2:
    ros::param::set("type_param","hongche");
    ros::param::set("radius_param",0.15);


    // 参数改
    nh.setParam("radius",0.2);
    ros::param::set("radius_param",0.2);

    return 0;
}