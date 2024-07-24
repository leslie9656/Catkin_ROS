import rospy

def main():

    rospy.init_node("Listerner")

    # api 1:
    rospy.get_param("param1",0.5)

    # api 2:
    rospy.get_param_cached("param1",0.5)

    # api 3:
    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo(f"param name: {name}")

    # api 4:
    flag1 = rospy.has_param("param1")

    if flag1:
        rospy.loginfo("param1 exists")
    else:
        rospy.loginfo("param1 does not exist")

    # api 5:
    key = rospy.search_param("param1")

    rospy.loginfo(f"param1 key: {key}")

if "__name__" == "__main__":
    main()