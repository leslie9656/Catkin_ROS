# 指定解释器
#！/usr/bin/env python

#导包
import rospy
# 编写主入口
if __name__ == "__main__":
    # 初始化ros节点
    rospy.init_node('hello_world_p')
    # 输出日志
    rospy.loginfo('Hello, world!')
    # 循环执行，ros节点需要持续运行
    # rospy.spin()