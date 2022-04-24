#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string.h> 
#include<std_msgs/Int8.h>

int main (int argc,char **argv){

    ros::init(argc,argv,"publisher");
    ros:: NodeHandle n;//initalized a node

    ros::Publisher encryption =n.advertise<std_msgs::String>("emessage", 1000);
    ros::Publisher key = n.advertise<std_msgs::Int8>("ekey",1000);
    ros::Rate loop_rate(10);
    while (ros::ok()){
    
        std_msgs::String result;
        std_msgs::Int8 ekey;
        std::string message;
        std::string result_t;
        ekey.data = 6;
        message = "bhavya" ;
        std::int64_t len;
        std::int64_t key_t = ekey.data;
        len = message.length();
        std::cout<<len<<"\n";
        for (int i=0;i<len;i++){
          if (isupper(message[i]))
              result_t =result_t + char((int(message[i])+key_t-65)%26 +65);
          else
              result_t = result_t + char((int(message[i])+key_t-97)%26 +97);
          }
      std::cout <<result_t<<"\n";
    
      result.data = result_t;

     encryption.publish(result);
    key.publish(ekey);
    ros::spinOnce();
    loop_rate.sleep();

  }
 return 0;
}