#include <iostream>
#include "ros/ros.h"
#include <cmath>
#include <string>
#include <vector>
#include <control.h>
#include <localization.h>
#include "scout_msgs/ScoutStatus.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include <motion_planner.h>
#include <tf/transform_broadcaster.h>
#include <scout.h>
using namespace std;

Local local;
Control control;
MotionPlanner motion;
Scout* scout = new Scout();
bool egoTopicFlag = false;

void egoTopicCallback(const scout_msgs::ScoutStatus::ConstPtr& msg) {
    egoTopicFlag = true;
    cout << msg->linear_velocity << "\n";
    cout << "ll" << endl;
    scout->setLinVel(msg->linear_velocity);
    scout->setAngVel(msg->angular_velocity);
}

void LiDARCallback(const sensor_msgs::Imu::ConstPtr& msg){ // heading
    //현재 scout class안에 있는 ego 값들을 전부 바꿔줘야 함. 
    //scout.setPosition_x(msg->linear_acceleration.x);
    //scout.setPosition_y(msg->linear_acceleration.y);
    // ego.y = msg->linear_acceleration.y;
    // heading 
    // cout << "LiDARCallback" << endl;
    tf::Quaternion q(msg->orientation.x, msg->orientation.y, msg->orientation.z, msg->orientation.w );
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    yaw = - (yaw * (180 / M_PI));
    scout->setHeading(fmod(yaw, 360.0));
    if (scout->getHeading() < 0){
        scout->setHeading(scout->getHeading() + 360);
    }
}

void LiDARPoseCallback(const nav_msgs::Odometry::ConstPtr& msg){
    // 현재 scout 위치
    scout->setPosition_x(msg->pose.pose.position.x);
    //cout << scout.getPosition_x() << endl;
    scout->setPosition_y(msg->pose.pose.position.y);
}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "master_node");
    ros::NodeHandle nh;
    geometry_msgs::Twist ctrl_cmd_msg; // 횡제어
    ros::Publisher ctrl_cmd_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Subscriber lidar_hdg_sub = nh.subscribe("/ouster/imu", 10, LiDARCallback); // heading
    ros::Subscriber ego_topic_sub = nh.subscribe("/scout_status", 10, egoTopicCallback); 
    ros::Subscriber lidar_pose_sub = nh.subscribe("/Odometry", 10, LiDARPoseCallback);
    local.readCSV();

    while (ros::ok())
    {   
        local.findClosestWaypoint(scout); // 현재 스카우트 위치 인덱스 저장 
        //cout << "getPosition_idx :: " << scout->getPosition_idx() << endl;
        motion.find_local_path(local.getGP(), scout); // 현재 local path 중 
        control.PurePursuit(motion.self_path, scout);
        ctrl_cmd_msg.linear.x = control.LongitudinalController();
        ctrl_cmd_msg.angular.z = control.LateralController(scout);
        ctrl_cmd_pub.publish(ctrl_cmd_msg);
        // egoTopicFlag = false;

        ros::spinOnce();
    }

    return 0;
}