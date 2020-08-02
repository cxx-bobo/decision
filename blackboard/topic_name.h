#ifndef TOPIC_NAME_H_
#define TOPIC_NAME_H_

#include <string>

namespace robort_decision{
class Topic{
    private:
    // 信息交互话题名
    std::string local_name;
    std::string remote_name;

    std::string pub_robot_info;
    std::string pub_punish_info;
    std::string pub_status;

    std::string sub_robot_info;
    std::string sub_punish_info;
    std::string sub_status;

    // 裁判系统话题名称
        // TODO

    public:
    Topic(const int id){
        if(1 == id){
            local_name = "robort01";
            remote_name = "robort02";
        }
        else{
            local_name = "robort02";
            remote_name = "robort01";
        }
        pub_robot_info = local_name + "/" + "robot_info";
        pub_punish_info = local_name + "/" + "robot_punish";
        pub_status = local_name + "/" + "status";
        sub_robot_info = remote_name + "/" + "robot_info";
        sub_punish_info = remote_name + "/" + "robort_punish";
        sub_status = remote_name + "/" + "status";
    }
    ~Topic() = default;

    std::string RobotInfoSub(){
        return sub_robot_info;
    }

    std::string PunishInfoSub(){
        return sub_punish_info;
    }

    std::string  StatusSub(){
        return sub_status;
    }

    std::string RobotInfoPub(){
        return pub_robot_info;
    }

    std::string PunishInfoPub(){
        return pub_punish_info;
    }

    std::string StatusPub(){
        return pub_status;
    }

};//Topic
}// robort_decision
#endif //TOPIC_NAME_H_