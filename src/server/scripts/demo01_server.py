#! /usr/bin/env python

import rospy
from server.srv import AddInts,AddIntsRequest,AddIntsResponse


def doNums(request):
    """
    处理客户端的AddIntsRequest消息。
    参数：封装了请求数据
    返回值：响应数据
    """
    # 解析提交的数
    num1 = request.num1
    num2 = request.num2

    # 计算并返回结果
    sum = num1 + num2

    # 将结果封装进响应
    response = AddIntsResponse()
    response.sum = sum

    rospy.loginfo(f"服务器解析的数据: num1 {num1}, num2 {num2}, sum {sum}")
    return response

    

def main():
    """
    服务端：解析客户端请求，产生响应。
    """
    rospy.init_node("server")

    # 创建服务端对象
    server = rospy.Service("addInts",AddInts,doNums)
    rospy.loginfo("服务器启动")
    rospy.spin()
if __name__ == "__main__":
    main()
