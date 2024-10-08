#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge

def camera_view_publisher():
    rospy.init_node('camera_view_publisher', anonymous=True)
    pub = rospy.Publisher('camera/image', Image, queue_size=10)
    bridge = CvBridge()
    rate = rospy.Rate(10)  # 10 Hz

    cap = cv2.VideoCapture(0)  # Use the default camera

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        
        if ret:
            # Convert OpenCV image to ROS Image message
            image_msg = bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            pub.publish(image_msg)
        
        rate.sleep()

    # Release the camera when done
    cap.release()

if __name__ == '__main__':
    try:
        camera_view_publisher()
    except rospy.ROSInterruptException:
        pass
