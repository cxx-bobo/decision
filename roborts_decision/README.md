# robots_decision
## 软件功能介绍
- 此部分
## 软件效果展示。需要体现整体项目的创新性和优势,结合可视化数据(例如视频网址,gif 图,测试图表等)对最终效果进行展示与定量分析
## 依赖工具、软硬件环境
## 编译、安装方式
## 文件目录结构及文件用途说明
>pictures
>roborts_decision
>>action_node
>>>BackAwayAction.h<br />
BackBootArea.h<br />
ChaseAction.h<br />
ChassisLimited.h<br />
DeckChaseAction.h<br />
DefendAction.h<br />
EscapeAction.h<br />
FollowAction.h<br />
>>>FrozeAction.h<br />
>>>GainBloodAction.h<br />
>>>GainBulletAction.h<br />
>>>GimbalLimited.h<br />
>>>readme.md<br />
>>>SearchAction.h<br />
>>>TurnToDetectedDirection.h<br />
>>>WaitBuffRefresh.h<br />
<br />
>>behavior_test.cpp<br />
>>blackboard<br />
>>>blackboard.h<br />
>>>topic_name.h<br />
>>CMakeLists.txt<br />
   ***
>>config<br />
>>>buffposition.yaml<br />
>>>decision.prototxt<br />
>>>decision.yaml<br />
>>>topic_name.prototxt<br />
***
>>executor<br />
>>>chassis_executor.cpp<br />
>>>chassis_executor.h<br />
>>>gimbal_executor.cpp<br />
>>>gimbal_executor.h<br />
***
>>icra_decision_node.cpp<br />
>>include<br />
>>>goal_factory.h<br />
>>>redme.md<br />
***
>>package.xml<br />
>>README.md<br />
***
>roborts_msgs<br />
>>action<br />
>>CMakeLists.txt<br />
>>msg<br />
>>package.xml<br />
>>srv

## 软件与硬件的系统框图,数据流图
## 原理介绍与理论支持分析
## 软件架构或层级图--------------------------------------?
## ~~代码规范------~~
## 是否存在开源协议--------------------------------------？
## ~~函数、变量命名是否规范、统一------~~
## ~~关键功能函数、变量是否存在清晰的注释------~~
## 整体可编译可运行,容易测试,包含不同情况下的测试脚本或涵盖集成测试
## ~~是否遵循某种设计模式------~~
## ~~开源与分享,截止到评选日的开源影响力(star 数)------~~
