import rospy
from topic.msg import Person


def callback(p):
    rospy.loginfo(f"Received person data: {p.name}, {p.age}, {p.height}")

def main():
    rospy.init_node("subscriber")
    sub = rospy.Subscriber("chatter", Person, callback)
    
    rospy.spin()

if __name__ == "__main__":
    main()