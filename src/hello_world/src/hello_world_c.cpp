// 包含 ros 头文件
# include "ros/ros.h"
// 编写main函数
int main(int argc, char *argv[]){

    //初始化ros节点
    ros::init(argc, argv,"hello_world");
    //输入日志
    ROS_INFO("Hello World");
    return 0;
}