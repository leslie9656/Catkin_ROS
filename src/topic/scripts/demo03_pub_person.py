#! /usr/bin/env python
import rospy
from topic.msg import Person

def main():
    rospy.init_node("publisher")
    pub = rospy.Publisher("chatter", Person, queue_size=10)

    person = Person()
    person.name = "John Doe"
    person.age = 25
    person.height = 176
    rate = rospy.Rate(1)
    rospy.loginfo("Publishing person data...")
    while not rospy.is_shutdown():
        pub.publish(person)
        rospy.loginfo(f"data is {person.name}, height is {person.height}, age is {person.age}")
        rate.sleep()
        


if __name__ == "__main__":
    main()

