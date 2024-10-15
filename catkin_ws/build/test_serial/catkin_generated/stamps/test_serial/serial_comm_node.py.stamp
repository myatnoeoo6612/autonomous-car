# # #!/usr/bin/env python

# # import rospy
# # import serial
# # from geometry_msgs.msg import Twist

# # def callback(msg):
# #     # Extract linear and angular velocities
# #     linear_velocity = msg.linear.x
# #     steering_angle = msg.angular.z
    
# #     # Create a message string
# #     message = f"{linear_velocity},{steering_angle}\n"
# #     ser.write(message.encode())

# # def initialize_node():
# #     # Initialize the ROS node
# #     rospy.init_node('serial_comm_node', anonymous=True)
    
# #     # Set up the subscriber to the /cmd_vel topic
# #     rospy.Subscriber('/cmd_vel', Twist, callback)

# #     # Keep the node running
# #     rospy.spin()

# # if __name__ == '__main__':
# #     try:
# #         # Open the serial port (update the port name to match your system)
# #         ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
# #         initialize_node()
# #     except rospy.ROSInterruptException:
# #         pass
# #     finally:
# #         ser.close()
# #!/usr/bin/env python

# #!/usr/bin/env python

# import rospy
# import serial
# from geometry_msgs.msg import Twist

# # Cache previous velocity and angle
# previous_linear_velocity = None
# previous_steering_angle = None

# def callback(msg):
#     global previous_linear_velocity, previous_steering_angle

#     # Extract and round the linear and angular velocities
#     linear_velocity = msg.linear.x
#     steering_angle = msg.angular.z

#     # Only proceed if there's an actual change in the data
#     if linear_velocity != previous_linear_velocity or steering_angle != previous_steering_angle:
#         # Construct the message to send
#         message = f"{linear_velocity},{steering_angle}\n"
#         try:
#             ser.write(message.encode())
#             rospy.loginfo(f"Sent Data: Linear Velocity: {linear_velocity}, Steering Angle: {steering_angle}")
#         except serial.serialutil.SerialException as e:
#             rospy.logerr(f"Serial write failed: {e}")

#         # Update previous values
#         previous_linear_velocity = linear_velocity
#         previous_steering_angle = steering_angle

# def initialize_node():
#     # Initialize the ROS node
#     rospy.init_node('serial_comm_node', anonymous=True)
    
#     # Set up the subscriber to the /cmd_vel topic
#     rospy.Subscriber('/cmd_vel', Twist, callback)

#     rospy.loginfo("serial_comm_node has started and is waiting for data...")

#     # Keep the node running
#     rospy.spin()

# if __name__ == '__main__':
#     ser = None
#     try:
#         # Open the serial port (change '/dev/ttyACM0' to your port)
#         ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
#         initialize_node()
#     except Exception as e:
#         rospy.logerr(f"Failed to open serial port: {e}")
#     finally:
#         if ser and ser.is_open:
#             ser.close()


#!/usr/bin/env python

import rospy
import serial
import threading
from geometry_msgs.msg import Twist

# Cache previous velocity and angle
previous_linear_velocity = None
previous_steering_angle = None

# Serial port reading thread
def read_from_serial():
    global ser
    while not rospy.is_shutdown():
        if ser.in_waiting > 0:
            try:
                incoming_data = ser.readline().decode().strip()
                rospy.loginfo(f"Received from Serial: {incoming_data}")
            except serial.SerialException as e:
                rospy.logerr(f"Serial read failed: {e}")
            except UnicodeDecodeError as e:
                rospy.logerr(f"Decoding error: {e}")

def callback(msg):
    global previous_linear_velocity, previous_steering_angle

    # Extract and round the linear and angular velocities
    linear_velocity = msg.linear.x
    steering_angle = msg.angular.z

    # Only proceed if there's an actual change in the data
    if linear_velocity != previous_linear_velocity or steering_angle != previous_steering_angle:
        # Construct the message to send
        message = f"{linear_velocity},{steering_angle}\n"
        try:
            ser.write(message.encode())
            rospy.loginfo(f"Sent Data: Linear Velocity: {linear_velocity}, Steering Angle: {steering_angle}")
        except serial.serialutil.SerialException as e:
            rospy.logerr(f"Serial write failed: {e}")

        # Update previous values
        previous_linear_velocity = linear_velocity
        previous_steering_angle = steering_angle

def initialize_node():
    # Initialize the ROS node
    rospy.init_node('serial_comm_node', anonymous=True)
    
    # Set up the subscriber to the /cmd_vel topic
    rospy.Subscriber('/cmd_vel', Twist, callback)

    rospy.loginfo("serial_comm_node has started and is waiting for data...")

    # Start the serial reading thread
    thread = threading.Thread(target=read_from_serial)
    thread.daemon = True
    thread.start()

    # Keep the node running
    rospy.spin()

if __name__ == '__main__':
    ser = None
    try:
        # Open the serial port (change '/dev/ttyACM0' to your port)
        ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
        initialize_node()
    except Exception as e:
        rospy.logerr(f"Failed to open serial port: {e}")
    finally:
        if ser and ser.is_open:
            ser.close()
