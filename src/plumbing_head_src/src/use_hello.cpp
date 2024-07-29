#include "ros/ros.h"
#include "plumbing_head_src/hello.h"


/* 
自定义源文件导入
*/
int main(int argc, char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_src");

    hello_ns::MyHello myhello;
    myhello.run();
    return 0;
}