#include "ros/ros.h"

/*
参数查询
实现：


*/

int main(int argc, char *argv[]){

    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_server");

    ros::NodeHandle nh;

    // 参数查询
    // api 1:
    double radius = nh.param("radius",0.5);     // 0.5是默认值
    ROS_INFO("radius = %.2f",radius);

    // api 2:
    // 查询参数，如果查询不到，返回false
    double raduis2 = 0.0;
    bool result1 = nh.getParam("radius",raduis2);    //将查询结果存入raduis2，返回值是bool类型，true表示查询成功
    if(result1){
        ROS_INFO("radius2 = %.2f",raduis2);
    }

    //api 3:
    // 和api2类似，但是会将查询结果缓存，提高查询效率，性能上提升
    double radius3 = 0.0;
    bool result2 = nh.getParamCached("radius",radius3);    //将查询结果存入raduis3，返回值是bool类型，true表示查询成功
    if(result2){
        ROS_INFO("radius3 = %.2f",radius3);
    }

    // api 4:
    // 获取所有参数的名称
    std::vector<std::string> names;
    nh.getParamNames(names);
    int count = 0;
    for (auto &&name : names){
        ROS_INFO("遍历到的元素%d = %s",count, name.c_str());
        count++;
    } 

    // api 5:
    // 判断参数是否存在
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radius000");
    ROS_INFO("flag1 = %d, flag2 = %d",flag1,flag2);

    // api 6:
    // searchParam 用于搜索参数的名称
    std::string key;
    nh.searchParam("radiusxxx",key);   // key是搜索到的参数名称,如果搜索不到，key为空字符串
    ROS_INFO("key = %s",key.c_str());

    // api 7:
    ros::param::get("radius",radius);
    ROS_INFO("radius = %.2f",radius);
    return 0;
}