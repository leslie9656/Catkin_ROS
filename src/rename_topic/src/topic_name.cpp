#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc,char * argv[]){

    setlocale(LC_ALL,"");

    ros::init(argc,argv,"topic_name");
    ros::NodeHandle nh;

    //核心:设置不同类型的话题
    //1.全局话题
    ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",1000);
    // or
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/rename/chatter",1000);

    //2.相对话题
    ros::Publisher pub = nh.advertise<std_msgs::String>("rename/chatter",1000);

    //3.私有话题 需要创建特定的 nh
    // 如果私有的nh创建的话题以/开头,这时就变成全局的.
    ros::NodeHandle nh("~");

    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    // or
    ros::Publisher pub = nh.advertise<std_msgs::String>("rename/chatter",1000);

    return 0;
}