# 1. ROS架构
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

# 2. ROS文件系统的相关命令
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

# 3. ROS通信机制
## 话题通信（发布订阅模式）
- 1.ROS Master
- 2.发布方
- 3.订阅方
- 4.数据  
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
和话题通信不同，服务通信更适用于对实时性有要求，具有一定逻辑处理的应用场景。  
**依赖于请求响应的模式。**  
- 1.ROS Master 管理者
- 2.Server 服务端
- 3.Client 客户端
- 4.数据载体  

- 流程：
  - master根据话题，实现Server和Client的连接。Client发起，Server产生响应。
- PS：
  - 1.保证顺序，客户端发起请求时，服务端需要已经启动。 
  - 2.客户端和服务端都可以存在多个。
  - 3.服务通信自定义srv，包含两个部分：请求部分+响应部分,两个部分用---分割
- 优化： 动态传入参数
- 可能出现的问题： 客户端先于服务端启动，会抛出异常
- 我们需要客户端先于服务端启动时，处于挂起状态而不是抛出异常，等服务端启动后，客户端还能照常进行
- 解决：
- 方案1.client.wait_for_service()
- 方案2.rospy.wait_for_service("话题名称")
## 参数服务器（参数共享模式）
- 1.ROS MASTER 管理者
- 2.Talker 设置者
- 3.Listener 调用方
- 流程： 设置方提交参数，交给管理者，管理者用参数列表保存参数；调用方发送请求；管理者查找参数，发送给调用方
- Listener通过RPC协议向参数服务器发送请求，因此参数服务器并不是为了高性能准备的，最好用来储存静态的非二进制的简单数据。  
- 参数服务器新增（修改）参数  
  见例子   
- 参数服务器获取参数  
  见例子  
- 参数服务器删除参数  
  见例子  

## 常用命令
- rosnode:操作节点
```
rosnode ping    测试到节点的连接状态
rosnode list    列出活动节点
rosnode info    打印节点信息
rosnode machine    列出指定设备上节点
rosnode kill    杀死某个节点
rosnode cleanup    清除不可连接的节点（僵尸节点）
```

- rostopic:操作话题
```
rostopic bw     显示主题使用的带宽
rostopic delay  显示带有 header 的主题延迟
rostopic echo   打印消息到屏幕
rostopic find   根据类型查找主题
rostopic hz     显示主题的发布频率
rostopic info   显示主题相关信息
rostopic list   显示所有活动状态下的主题
rostopic pub    将数据发布到主题
rostopic type   打印主题类型
```

- rosservice:操作服务
```
rosmsg show    显示消息描述
rosmsg info    显示消息信息
rosmsg list    列出所有消息
rosmsg md5    显示 md5 加密后的消息
rosmsg package    显示某个功能包下的所有消息
rosmsg packages    列出包含消息的功能包
```

- rosmsg:操作msg消息
```
rosservice args 打印服务参数
rosservice call    使用提供的参数调用服务
rosservice find    按照服务类型查找服务
rosservice info    打印有关服务的信息
rosservice list    列出所有活动的服务
rosservice type    打印服务类型
rosservice uri    打印服务的 ROSRPC uri
```

- rossrv:操作srv消息
```
rossrv show    显示服务消息详情
rossrv info    显示服务消息相关信息
rossrv list    列出所有服务信息
rossrv md5    显示 md5 加密后的服务消息
rossrv package    显示某个包下所有服务消息
rossrv packages    显示包含服务消息的所有包
```

- rosparam:操作参数
```
rosparam set    设置参数
rosparam get    获取参数
rosparam load    从外部文件加载参数
rosparam dump    将参数写出到外部文件
rosparam delete    删除参数  
rosparam list    列出所有参数  
```

## 话题通信和服务通信的异同
### 同
- 1. 都需要 发布 一个接收  
- 2. 都需要话题名称  
- 3. 都需要数据载体  
### 异
- 1. 话题通信是异步的，启动无顺序，节点可以多对多  
- 2. 服务通信是同步的，启动有顺序，节点可以一对多（一个server）  
- 3. 数据载体内容不同  

# 4. ROS通信机制进阶
## 常用API （cpp）
```
# 初始化
 /*
 * 该函数可以解析并使用节点启动时传入的参数(通过参数设置节点名称、命名空间...) 
 *
 * 该函数有多个重载版本，如果使用NodeHandle建议调用该版本。 
 *
 * \param argc 参数个数
 * \param argv 参数列表
 * \param name 节点名称，需要保证其唯一性，不允许包含命名空间
 * \param options 节点启动选项，被封装进了ros::init_options
 *
 */
ros::init(argc,argv,"topic_name",ros::init_options::AnonymousName)

# 话题和服务通信
## 发布对象
/**
* \brief 根据话题生成发布对象
*
* 在 ROS master 注册并返回一个发布者对象，该对象可以发布消息
*
* 使用示例如下:
*
*   ros::Publisher pub = handle.advertise<std_msgs::Empty>("my_topic", 1);
*
* \param topic 发布消息使用的话题
*
* \param queue_size 等待发送给订阅者的最大消息数量
*
* \param latch (optional) 如果为 true,该话题发布的最后一条消息将被保存，并且后期当有订阅者连接时会将该消息发送给订阅者
*
* \return 调用成功时，会返回一个发布对象
*
*
*/

## 订阅对象
/**
   * \brief 生成某个话题的订阅对象
   *
   * 该函数将根据给定的话题在ROS master 注册，并自动连接相同主题的发布方，每接收到一条消息，都会调用回调
   * 函数，并且传入该消息的共享指针，该消息不能被修改，因为可能其他订阅对象也会使用该消息。
   * 
   * 使用示例如下:

void callback(const std_msgs::Empty::ConstPtr& message)
{
}

ros::Subscriber sub = handle.subscribe("my_topic", 1, callback);

   *
* \param M [template] M 是指消息类型
* \param topic 订阅的话题
* \param queue_size 消息队列长度，超出长度时，头部的消息将被弃用
* \param fp 当订阅到一条消息时，需要执行的回调函数
* \return 调用成功时，返回一个订阅者对象，失败时，返回空对象
* 

void callback(const std_msgs::Empty::ConstPtr& message){...}
ros::NodeHandle nodeHandle;
ros::Subscriber sub = nodeHandle.subscribe("my_topic", 1, callback);
if (sub) // Enter if subscriber is valid
{
...
}

*/ 


```