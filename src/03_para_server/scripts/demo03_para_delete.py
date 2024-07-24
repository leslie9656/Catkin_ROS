import rospy

def main():
    rospy.init_node("delete_param")
    # 删除参数
    try:
        rospy.delete_param("param1")
        rospy.delete_param("param2")
    except Exception as e:
        rospy.loginfo(f"delete param failed: {e}")

if __name__ ==  "__main__":
    main()