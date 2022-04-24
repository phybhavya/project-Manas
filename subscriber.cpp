#include "ros/ros.h"
#include "std_msgs/String.h"
#include<std_msgs/Int8.h>
int dkey ;
void CALL_BACK_FUNCTION(const std_msgs::String::ConstPtr& msg)
  {
    ROS_INFO("The message thst we recieved was : %s", msg->data.c_str());
    std::string emsg = msg->data.c_str();
    std::int8_t len = emsg.length();
    std::string decrypt;
      for (int i=0;i<len;i++)
      {
          if (isupper(emsg[i]))
              decrypt = decrypt + char((int(emsg[i])+26-dkey-65)%26 +65);
          else
              decrypt = decrypt + char((int(emsg[i])+26-dkey-97)%26 +97);
      }
    std::cout<<"The decrypted message is :"<<decrypt;
    
  }
void CALL_BACK_int(const std_msgs::Int8::ConstPtr& msg_1)
  {
    ROS_INFO("The key is : %d", msg_1->data);
    dkey = msg_1->data;
  }
int main(int argc, char **argv)
  {
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle n;
    ros:: Subscriber key = n.subscribe("ekey",1000,CALL_BACK_int);
    ros:: Subscriber message = n.subscribe("emessage",1000,CALL_BACK_FUNCTION);
    ros::spin();
    
    return 0;
  }