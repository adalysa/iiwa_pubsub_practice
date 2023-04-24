#include <ros/ros.h>
#include <iiwa_msgs/JointPosition.h>

int main (int argc, char **argv)
{
    ros::init (argc, argv, "iiwa_pub_sim");

    ros::NodeHandle n;

    ros::Publisher iiwa_pub_sim = n.advertise<iiwa_msgs::JointPosition>("iiwa_msgs_topic", 1000);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        iiwa_msgs::JointPosition joint_positions_sim;

        //tester data
        joint_positions_sim.position.a1 = 1;
        joint_positions_sim.position.a2 = 2;
        joint_positions_sim.position.a3 = 3;
        joint_positions_sim.position.a4 = 4;
        joint_positions_sim.position.a5 = 5;
        joint_positions_sim.position.a6 = 6;
        joint_positions_sim.position.a7 = 7;

        iiwa_pub_sim.publish(joint_positions_sim);

        ros::spinOnce();

        loop_rate.sleep();

    }
  return 0;
}
