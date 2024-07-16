#ROS架构
## 从系统架构：  
- OS 层： 意义上的操作系统  
- 中间层： ROS封装的关于机器人开发的中间件：通信系统，开发实现库  
- 应用层： 功能包  
## 从自身结构：
- 文件系统：ROS源代码的组织形式  
```
    -catkin_ws  
     |-build 编译空间：存放CMake和catkin的缓存信息，配置信息和其他中间文件。
     |-devel 开发空间，用于存放编译后生成的目标文件，包括头文件，动态&静态连接库，可执行文件等。 
     |-src  源码
       |-CMakeLists.txt 编译的基本配置
       |-pkg_1  
       |-pkg_2 功能包
         |-CMakeLists.txt 配置编译规则，比如源文件，依赖项，目标文件
         |-package.xml 包信息
         |-scripts 存储python文件
         |-src 存储cpp文件
         |-include 头文件
         |-msg 消息通信格式文件
         |-srv服务通信格式文件
         |-action 动作格式文件
         |-launch 可一次性运行多个节点
         |-config 配置信息
    
```  
- 计算图：**rqt_graph** or **rosrun rqt_graph rqt_graph**
- 开源社区

# ROS文件系统的相关命令
**ros的内置Linux语言**
## 执行
```
roscore 
启动ros master，ros参数服务器，ros日志节点

rosrun 包名 节点名

roslaunch 包名 launch文件名

```
## 增
```
catkin_create_pkg 自定义包名 依赖包
sudo apt install xxx
```

## 删
```
sudo apt purge xxx
```
## 查
```
rospack list 列出所有包
rosopack find 包名 查抄包是否存在
roscd 包名 进入包
rosls 包名 列出包下的文件
apt search xxx 搜索包

```
## 改
```
rosed 包名 文件名 修改功能包文件
```

# ROS通信机制
## 话题通信（发布订阅模式）
- 1.发布方
- 2.订阅方
- 3.数据  
**需要注意的是，话题名称必须一致，不然就因为话题不一致，导致话题连接失败**  
PS：  
- 回调函数spin() 不立刻实现，等待一个消息提示之后，函数实现
- 话题通信自定义msg  
  - ros自带的msg无法满足复杂的数据类型，需要自己实现一个msg文件。  
  - 可以使用的数据类型： int float string time duration 数组  
  - ros还有一种特殊类型：header，包含时间戳和ros中常用的坐标帧信息。
  - 实现：
    - 编写msg文件
    - 配置package.xml
    - 配置CMakeList.txt
    - 编译，生成中间文件（cpp->devel/include/包名/xxx.h  python->devel/lib/python3/msg）
## 服务通信（请求响应模式）

## 参数服务器（参数共享模式）
