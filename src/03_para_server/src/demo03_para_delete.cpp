#include "ros/ros.h"

/*
参数的删除
*/

int main(int argc, char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_server");

    ros::NodeHandle nh;

    // 删除参数
    // api 1:
    bool flag1 = nh.deleteParam("radius");
    if (flag1){
        ROS_INFO("删除参数成功");
    }else{
        ROS_INFO("删除参数失败");
    }
    // api 2:
    bool flag2 = ros::param::del("type");
    if(flag2){
        ROS_INFO("删除参数成功");
    }else{
        ROS_INFO("删除参数失败");
    }


    return 0;
}