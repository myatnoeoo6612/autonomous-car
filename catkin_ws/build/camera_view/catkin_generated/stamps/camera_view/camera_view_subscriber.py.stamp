#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge

def image_callback(data):
    bridge = CvBridge()
    cv_image = bridge.imgmsg_to_cv2(data, desired_encoding='bgr8')
    cv2.imshow("Camera View", cv_image)
    cv2.waitKey(30)

def camera_view_subscriber():
    rospy.init_node('camera_view_subscriber', anonymous=True)
    rospy.Subscriber('camera/image', Image, image_callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        camera_view_subscriber()
    except rospy.ROSInterruptException:
        cv2.destroyAllWindows()
