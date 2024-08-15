#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
/*
    订阅发布的坐标系相对关系，传入一个座标点，调用tf实现转换。
    流程：
        1. 包含头文件
        2. 编码，初始化
        3. 订阅对象
        4. 组织一个座标点
        5. 转换算法
        6. 输出
*/

int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    geometry_msgs::PointStamped ps;
    ps.header.frame_id = "laser";
    ps.header.stamp = ros::Time::now();

    ps.point.x = 2.0;
    ps.point.y = 3.0;
    ps.point.z = 5.0;

    //增加休眠
    ros::Duration(2).sleep();

    ros::Rate rate(10);

    while(ros::ok()){

        // 核心代码 将ps转换成相对于baselink的座标点
        geometry_msgs::PointStamped ps_out;
        ps_out=buffer.transform(ps,"base_link");

        ROS_INFO("转换后的坐标值：(%.2f,%.2f,%.2f)",ps.point.x,ps.point.y,ps.point.z);
        rate.sleep();
        ros::spinOnce();
    }





    return 0;
}