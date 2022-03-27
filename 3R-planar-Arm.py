# this is done by analytical method of 3r planar arm
import math
import matplotlib as pyplot
a1 = float( input (" input the length of the arm 1"))# length of arm1
a2 = float(input (" input the length of the arm 2"))# length of arm2
a3 = float(input (" input the length of the arm 3"))# length of arm3
pos_x = float(input (" give desired x coordinate of the end effector"))# the final position in x coordinate
pos_y = float(input (" give desired y coordinate of the end effector"))# the final position in y coordinate
phidegree = float(input ("give the total angle of the arms that can be turned"))# total angle that arm can be turned
# finding the coordinates of wrist or end point of arm 2
phi = phidegree*3.148/180 #converting it into radians
wx =  pos_x - a3*math.cos(phi)# finding the x coordinates of wrist or end point of arm 2
wy = pos_y -a3*math.sin(phi)# finding the y coordinates of wrist or end point of arm 2
c2 = (wx*wx + wy*wy -a1*a1 - a2*a2)/(2*a1*a2) # finding the angle of second arm. if the cos value of angle doesnt is lesser than 1 it means that it can achieve the position if not then the position is notachievable by the arm
# we will be finding two values of each angles cause the position can be achieved by 2 ways
if c2<=1:
    s2_1 = math.sqrt(1- c2*c2)#sin values of 2nd angle by 1st way
    s2_2 = math.sqrt (1-c2*c2)#sin values of 2nd angle by 2nd way
    theta2_1 = math.atan2(s2_1, c2)#angle of 2nd angle by 1st method
    theta2_2 = math.atan2(s2_2,c2)#angle of 2nd angle by 1st method
    denom_1 = a1*a1 + a2*a2 +2*a1*a2*math.cos(theta2_1)# denominator created for the calculation of the theta 1
    denom_2 = a1*a1 + a2*a2 +2*a1*a2*math.cos(theta2_2)# denominator created for the calculation of the theta 1
    s1_1 =(wy*(a1 + a2*math.cos(theta2_1)) - a2*math.sin(theta2_1)*wx)/denom_1# finding the sin of theta1 of 1st method 
    s1_2 =(wy*(a1+a2*math.cos(theta2_2)) - a2*math.sin(theta2_2)*wx)/denom_2 # finding the sin of theta1 of 2nd method 
    c1_1 = (wx*(a1+a2*math.cos(theta2_1)) + a2*math.sin(theta2_1)*wy)/denom_1# finding the cos of theta1 of 1st method 
    c1_2 = (wx*(a1+a2*math.cos(theta2_1)) + a2*math.sin(theta2_2)*wy)/denom_2# finding the cos of theta1 of 2nd method 
    theta1_1 = math.atan2(s1_1, c1_1) #first solution
    theta1_2 = math.atan2(s1_2, c1_2) #second solution
    theta3_1 = phi - theta1_1 - theta2_1 #calulting the angle of theta3 by first method
    theta3_2 = phi - theta1_2 - theta2_2 #calculating the angle of theta3 by second method
    print("the value of theta1_1: " ,theta1_1,  "the value of theta2_1: ", theta2_1 , "the value of theta3_1: " ,theta3_1)
    print("the value of theta1_2: ", theta1_2 , "the value of theta2_2: " ,theta2_2 , "the value of theta3_2: " ,theta3_2)
else: print("it cannot exist")

