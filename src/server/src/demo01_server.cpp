#include "ros/ros.h"
#include "server/AddInts.h"


bool doNums(server::AddInts::Request& request,
            server::AddInts::Response &response){
    /*
    request: 请求对象
    response：响应对象
    */

   //1.处理请求
   int num1 = request.num1;
   int num2 = request.num2;
   ROS_INFO("num1: %d, num2: %d", num1,num2);

   //2.组织响应
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("sum: %d",sum);

    return true;
}

int main(int argc, char *argv[]){

    setlocale(LC_ALL, "");
    
    ros::init(argc, argv,"server");
    ROS_INFO("服务器启动");
    ros::NodeHandle nh;

    //和topic不同，这里需要创建服务对象，并且处理请求并产生响应。
    ros::ServiceServer server = nh.advertiseService("addInts",doNums);
    
    ros::spin();

    return 0;
}