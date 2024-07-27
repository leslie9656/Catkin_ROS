#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  setlocale(LC_ALL,"");
  // 初始化ros节点
  /*
  作用：初始化ros节点

  Args:
    1. argc     封装实参个数（n+1）
    2. argv     封装实参的数组
    3. name     为节点命名（唯一性）
    4. options  节点启动选项
  Return:
    None
  使用：
    1.argc和argv的使用
    如果按照ros中的特定格式传入实参，那么ros可以加以使用，比如用来设置全局参数，给节点命名...
    rosrun API_cpp demo01_cpp_API _length:=2
    2. options 的使用
    节点需要保证唯一性，那么同一节点就不能重复启动。
    需求:特定场景下，需要一个节点多次启动且正常运行。
    解决:当创建ros节点时，加上ros::init_options::AnonymousName
  */
  ros::init(argc, argv, "demo01_cpp_API",ros::init_options::AnonymousName);
  // 创建节点句柄
  ros::NodeHandle nh;
  
  // 创建发布者对象
  /*
    模板： 被发布对象的类型
    Args:
      1. 话题名称
      2. 队列长度
      3. latch（options）: 若设置为True，会保存发布方的最后一条消息，并且新的订阅对象连接到发布方时，
                           发布方会将这条信息发送给订阅者
  */
  ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10,true);

    std_msgs::String msg;
    //设置发布频率10Hz.

    ros::Rate rate(10);
    int count = 0;

    //休眠3秒    
    ros::Duration(3).sleep();


    ros::Time right_now = ros::Time::now();
    ROS_INFO("Time is %.2f",right_now.toSec());
    ROS_INFO("Time is %d", right_now.sec);
    ROS_INFO("==========================================");
    ros::Duration du(5);
    du.sleep();

    ros::Time end = ros::Time::now();
    ROS_INFO("result: %.2f",end.toSec());



    while (ros::ok()) {
        // msg.data = "Hello ROS";
        count++;
        std::stringstream ss;

        ss << "Hello ROS " << count;    //字符串拼接
        msg.data = ss.str();
        if (count<=10){
          pub.publish(msg);
          ROS_INFO("发布的数据：%s",ss.str().c_str());          
        }
        

        rate.sleep();
        ros::spinOnce();
        ROS_INFO("一轮回调结束");
    }
}