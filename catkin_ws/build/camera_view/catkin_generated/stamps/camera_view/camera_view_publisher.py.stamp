#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge
import time

def camera_view_publisher():
    rospy.init_node('camera_view_publisher', anonymous=True)
    pub = rospy.Publisher('camera/image', Image, queue_size=10)
    bridge = CvBridge()
    rate = rospy.Rate(30)  # Targeting 30 Hz

    # Initialize the video capture with lower resolution
    cap = cv2.VideoCapture(0)
    
    # Set camera resolution (for example, 640x480)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

    # Check if the camera opened successfully
    if not cap.isOpened():
        rospy.logerr("Error: Could not open camera.")
        return
    else:
        print("Camera opened successfully!")

    # Initialize variables for FPS calculation
    frame_count = 0
    start_time = time.time()

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        
        if ret:
            # Calculate the current FPS
            frame_count += 1
            elapsed_time = time.time() - start_time
            
            if elapsed_time > 1.0:  # Update FPS every second
                fps = frame_count / elapsed_time
                frame_count = 0
                start_time = time.time()
            else:
                fps = 0  # If less than 1 second has passed

            # Draw FPS on the frame
            cv2.putText(frame, f'FPS: {fps:.2f}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

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
#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge
import time

def camera_view_publisher():
    rospy.init_node('camera_view_publisher', anonymous=True)
    pub = rospy.Publisher('camera/image', Image, queue_size=10)
    bridge = CvBridge()
    rate = rospy.Rate(30)  # Targeting 30 Hz

    # Initialize the video capture with lower resolution
    cap = cv2.VideoCapture(0)
    
    # Set camera resolution (for example, 640x480)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

    # Check if the camera opened successfully
    if not cap.isOpened():
        rospy.logerr("Error: Could not open camera.")
        return
    else:
        print("Camera opened successfully!")

    # Initialize variables for FPS calculation
    frame_count = 0
    start_time = time.time()

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        
        if ret:
            # Calculate the current FPS
            frame_count += 1
            elapsed_time = time.time() - start_time
            
            if elapsed_time > 1.0:  # Update FPS every second
                fps = frame_count / elapsed_time
                frame_count = 0
                start_time = time.time()
            else:
                fps = 0  # If less than 1 second has passed

            # Draw FPS on the frame
            cv2.putText(frame, f'FPS: {fps:.2f}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

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
#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Image
import cv2
from cv_bridge import CvBridge
import time

def camera_view_publisher():
    rospy.init_node('camera_view_publisher', anonymous=True)
    pub = rospy.Publisher('camera/image', Image, queue_size=10)
    bridge = CvBridge()
    rate = rospy.Rate(30)  # Targeting 30 Hz

    # Initialize the video capture with lower resolution
    cap = cv2.VideoCapture(0)
    
    # Set camera resolution (for example, 640x480)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

    # Check if the camera opened successfully
    if not cap.isOpened():
        rospy.logerr("Error: Could not open camera.")
        return
    else:
        print("Camera opened successfully!")

    # Initialize variables for FPS calculation
    frame_count = 0
    start_time = time.time()

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        
        if ret:
            # Calculate the current FPS
            frame_count += 1
            elapsed_time = time.time() - start_time
            
            if elapsed_time > 1.0:  # Update FPS every second
                fps = frame_count / elapsed_time
                frame_count = 0
                start_time = time.time()
            else:
                fps = 0  # If less than 1 second has passed

            # Draw FPS on the frame
            cv2.putText(frame, f'FPS: {fps:.2f}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2)

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
