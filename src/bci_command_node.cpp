// A simple ROS node implementing a command prompt that publishes the string that is entered.

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "bci_command_node");
  ros::NodeHandle n;

  ros::Publisher command_pub = n.advertise<std_msgs::String>("/command_publisher/bci_command", 1000);

  while (ros::ok())
  {
    std_msgs::String msg;
    string output;

    // Rescan and Quit are temporary for debug, they don't necessarily have to be implemented with BCI.
    cout << "Enter command (Left, Right, Confirm, Rescan, Quit): ";
    getline(cin, output);
    msg.data = output;

    ROS_DEBUG("Sending command %s...", msg.data.c_str());
    command_pub.publish(msg);

    if (output == "Quit") break;
  }


  return 0;
}
