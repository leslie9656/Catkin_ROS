#include "ros/ros.h"
#include "server/AddInts.h"


/*
若要实现参数的动态提交：
格式：rosrun xxxx xxx 12 1234
此时 argc为3， argv为 xxx 12 1234 
节点执行时，需要获取命令中的参数，并组织进request
*/


int main(int argc, char *argv[]){

    // 优化实现，获取命令中参数
    if (argc != 3){
        ROS_ERROR("Wrong number of arguments");
        return 1;
    }

    setlocale(LC_ALL, "");
    
    ros::init(argc, argv,"client");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<server::AddInts>("addInts");

    //提交请求并处理响应
    server::AddInts ai;
    //组织请求
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    //处理响应
    bool flag = client.call(ai);
    if (flag) {
        ROS_INFO("Sum: %d", ai.response.sum);
    } else {
        ROS_ERROR("Failed to call service AddInts");
    }

    ros::spin();
    return 0;
}