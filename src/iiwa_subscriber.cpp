#include <ros/ros.h>
#include <iiwa_msgs/JointPosition.h>
#include <sensor_msgs/JointState.h>

ros::Publisher pub;

// Callback function that coverts data to sensor msgs; called when new msg arrives
void iiwa_pub_simCallback(const iiwa_msgs::JointPosition::ConstPtr &msg){

    sensor_msgs::JointState j;

    j.header = msg->header;

    // This loop puts strings into sensor_msgs/JointState name vector
    for (int i = 1; i <= 7 ; i++){
        j.name.push_back("iiwa_joint_" + std::to_string(i));
    }

    j.position.push_back(msg->position.a1);
    j.position.push_back(msg->position.a2);
    j.position.push_back(msg->position.a3);
    j.position.push_back(msg->position.a4);
    j.position.push_back(msg->position.a5);
    j.position.push_back(msg->position.a6);
    j.position.push_back(msg->position.a7);

    pub.publish(j);
}

int main(int argc, char **argv){

    ros::init(argc, argv, "iiwa_sub_sim");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("iiwa_msgs_topic", 1000, iiwa_pub_simCallback);

    pub = n.advertise<sensor_msgs::JointState>("/iiwa/joint_states", 10);

    ros::spin();

    return 0;
}
