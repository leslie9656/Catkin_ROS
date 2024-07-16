#! /usr/bin/env python

import rospy
from std_msgs.msg import String


def main():
    rospy.init_node("Publisher")   #传入节点名称

    pub = rospy.Publisher("chatter",String,queue_size=10)

    msg = String()

    rospy.sleep(3)
    while not rospy.is_shutdown():
        msg.data = "hello"
        pub.publish(msg)
        rospy.spin()


if __name__ == '__main__':
    main()
    