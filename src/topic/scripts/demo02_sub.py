#! /usr/bin/env python

import rospy
from std_msgs.msg import String


def doMsg(msg):
    rospy.loginfo(f"my message is {msg.data}")


def main():
    
    rospy.init_node("subscriber")

    sub = rospy.Subscriber("chatter",String,doMsg,queue_size=10)
    
    rospy.spin()

if __name__ == '__main__':
    main()