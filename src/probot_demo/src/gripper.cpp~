#include<ros/ros.h>
#include<moveit/planning_scene_interface/planning_scene_interface.h>
#include<movei/move_group_interface/move_group_interface.h>
#include<tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc,char** argv)
{
    ros::init(argc,argv,"ur5_arm_pick_and_place");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();
    
    ros::WallDuration(1.0).sleep();
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    moveit::planning_interface::MoveGroupInterface group("manipulator");
    group.setPlanningTime(45.0);
    
    return 0;
}
