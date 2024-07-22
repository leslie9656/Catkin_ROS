#! /usr/bin/env python
import rospy
from server.srv import AddInts,AddIntsRequest,AddIntsResponse
import sys
def main():
    """
    客户端：组织并提交请求，处理服务端响应。

    优化实现：可以在执行节点时，动态传入参数
    """
    # 首先判断参数长度
    if len(sys.argv) != 3 :
        rospy.logerror("wrong number of arguments")
        sys.exit(1)
    
    # 解析并获取参数
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])

    rospy.init_node("client")
    # 创建客户端对象
    client = rospy.ServiceProxy("addInts",AddInts)
    # 组织请求数据，并发布请求

    """
    解决客户端先于服务端启动
    """
    # 1. 等待服务器启动
    # client.wait_for_service()

    # or
    rospy.wait_for_service("addInts")
    response = client.call(num1,num2)

    # 处理并打印服务端的响应
    rospy.loginfo(f"客户端得到的结果: sum {response.sum}")

    rospy.spin()


if __name__ == "__main__":
    main()