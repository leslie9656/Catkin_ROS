import rospy

def main():
    
    rospy.init_node("Talker")
    
    # 设置参数
    rospy.set_param("param1",1)
    rospy.set_param("param2","huangche")
    


if __name__ == "__main__":
    main()