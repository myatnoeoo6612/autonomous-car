#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist
import random

def talker():
    rospy.init_node('test_publisher_node', anonymous=True)
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    rate = rospy.Rate(100)  # 1 Hz

    while not rospy.is_shutdown():
        twist = Twist()
        twist.linear.x = 1.5  # Random linear velocity
        twist.angular.z = -0.54  # Random steering angle

        rospy.loginfo(f"Publishing Linear: {twist.linear.x}, Angular: {twist.angular.z}")
        pub.publish(twist)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

