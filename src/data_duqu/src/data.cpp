
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include<string>
#include "ros/ros.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>


using namespace std; 
void jointstatesCallback(const sensor_msgs::JointStateConstPtr& msg,std::string topicName)
{
  float pos[7],vel[7];
  //pos=msg->position;
  pos[0]=msg->position[0];
  pos[1]=msg->position[1];
  pos[2]=msg->position[2];
  pos[3]=msg->position[3];
  pos[4]=msg->position[4];
  pos[5]=msg->position[5];
  pos[6]=msg->position[6];
  vel[0]=msg->velocity[0];
  vel[1]=msg->velocity[1];
  vel[2]=msg->velocity[2];
  vel[3]=msg->velocity[3];
  vel[4]=msg->velocity[4];
  vel[5]=msg->velocity[5];
  vel[6]=msg->velocity[6];
  ROS_INFO("I heard: [%f] [%f] [%f] [%f] [%f] [%f] [%f] ",pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],pos[6]);
  ROS_INFO("I heard: [%f] [%f] [%f] [%f] [%f] [%f] [%f] ",vel[0],vel[1],vel[2],vel[3],vel[4],vel[5],vel[6]);
  std::cout<<pos<<std::endl;
  FILE *fp ;
  
  const char * abc=topicName.data();

  fp = fopen(abc, "w" ) ;
  for(int i=0;i<7;i++)
  {
    fprintf(fp, "%.10f", pos[i] ) ;
    fprintf( fp, "," ) ;
    
  }
   
  fprintf( fp, "\n" ) ;
  for(int i=0;i<7;i++)
  {
    fprintf(fp, "%.10f", vel[i] ) ;
    fprintf( fp, "," ) ;
    
  }
  fprintf( fp, "\n" ) ;
  fclose( fp ) ;
  
}
void jishi()
{
    for(int i=1000;i>0;i--)
    {}
}

void writedata(int i)
{
    ros::NodeHandle n;

    string inputstring= to_string(i) + ".txt";
    ros::Subscriber sub = n.subscribe<sensor_msgs::JointState>("/joint_states", 1000, boost::bind(&jointstatesCallback, _1, inputstring));
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");
  
  ros::NodeHandle n;
  
  // int t=3;
  
  // std::string f_str=to_string(t);
  // string inputstring=f_str+".txt";
  // ros::Subscriber sub1 = n.subscribe<sensor_msgs::JointState>("/joint_states", 1000, boost::bind(&jointstatesCallback, _1, inputstring));

  // t=4;
  //  f_str=to_string(t);
  //  inputstring=f_str+".txt";
  // ros::Subscriber sub2 = n.subscribe<sensor_msgs::JointState>("/joint_states", 1000, boost::bind(&jointstatesCallback, _1, inputstring));

     ros::Subscriber sub1[1000];
    //std::string f_str="";
    //string inputstring="";

    for(int t=1;t<10;t++)
    {     
        // std::string f_str=to_string(t);
        // string inputstring=f_str+".txt";

        //  sub1[t-1] = n.subscribe<sensor_msgs::JointState>("/joint_states", 1000, boost::bind(&jointstatesCallback, _1, inputstring));
        // // jishi();

        thread tt(writedata, t);
        sleep(500);
        tt.detach();
        //sleep(1000);
    }
  
 
  
 
  ros::spin();
  
  
 
  return 0;
}
