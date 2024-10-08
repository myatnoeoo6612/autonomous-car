#!/usr/bin/env python

# Import required libraries
import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge
import time

# Global variables for FPS calculation
frame_count = 0
start_time = time.time()

def image_callback(data):
    global frame_count, start_time
    bridge = CvBridge()
    cv_image = bridge.imgmsg_to_cv2(data, desired_encoding='bgr8')

    # Calculate FPS
    frame_count += 1
    elapsed_time = time.time() - start_time

    if elapsed_time > 1.0:  # Update FPS every second
        fps = frame_count / elapsed_time
        frame_count = 0  # Reset count for the next second
        start_time = time.time()
    else:
        fps = 0  # Set 0 if less than 1 second has passed

    # Draw FPS on the image
    cv2.putText(cv_image, f'FPS: {fps:.2f}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

    # Display the image with FPS
    cv2.imshow("Camera View", cv_image)
    cv2.waitKey(1)  # Use a small delay to allow window to refresh

def camera_view_subscriber():
    # Initialize the ROS node
    rospy.init_node('camera_view_subscriber', anonymous=True)
    rospy.Subscriber('camera/image', Image, image_callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        camera_view_subscriber()
    except rospy.ROSInterruptException:
        cv2.destroyAllWindows()
