# import roslib
# import rospy
# from ackermann_msgs.msg import AckermannDriveStamped
# from std_msgs.msg import Float64
# import sys, select, termios, tty

# try:
#     import thread
# except ImportError:
#     # For python3 compatibility
#     import _thread
# from numpy import clip

# control_keys = {
#     'up'    : '\x41',
#     'down'  : '\x42',
#     'right' : '\x43',
#     'left'  : '\x44',
#     'space' : '\x20',
#     'tab'   : '\x09'}

# # Modify key bindings for desired increments
# key_bindings = {
#     '\x41' : ( 0.3 , 0.0),   # Up arrow: Increase speed by 0.3 m/s
#     '\x42' : (-0.3 , 0.0),   # Down arrow: Decrease speed by 0.3 m/s
#     '\x43' : ( 0.0 ,-0.18),  # Right arrow: Decrease steering angle by 0.18 rad
#     '\x44' : ( 0.0 , 0.18),  # Left arrow: Increase steering angle by 0.18 rad
#     '\x20' : ( 0.0 , 0.0),   # Space: Brake (speed and steering to 0)
#     '\x09' : ( 0.0 , 0.0)}   # Tab: Align wheels (steering to 0)

# class AckermannDriveKeyop:

#     def __init__(self, args):
#         # Set max speed and steering angle values
#         max_speed = 2.0
#         max_steering_angle = 0.9

#         if len(args) > 2:
#             cmd_topic = '/' + args[2]
#         else:
#             cmd_topic = 'ackermann_cmd'

#         # Define speed and steering angle ranges
#         self.speed_range = [-float(max_speed), float(max_speed)]
#         self.steering_angle_range = [-float(max_steering_angle),
#                                      float(max_steering_angle)]

#         self.speed = 0
#         self.steering_angle = 0
#         self.motors_pub = rospy.Publisher(
#             cmd_topic, AckermannDriveStamped, queue_size=1)
#         rospy.Timer(rospy.Duration(1.0/5.0), self.pub_callback, oneshot=False)
#         self.print_state()
#         self.key_loop()

#     def pub_callback(self, event):
#         ackermann_cmd_msg = AckermannDriveStamped()
#         ackermann_cmd_msg.drive.speed = self.speed
#         ackermann_cmd_msg.drive.steering_angle = self.steering_angle
#         self.motors_pub.publish(ackermann_cmd_msg)

#     def print_state(self):
#         sys.stderr.write('\x1b[2J\x1b[H')
#         rospy.loginfo('\x1b[1M\r*********************************************')
#         rospy.loginfo('\x1b[1M\rUse arrows to change speed and steering angle')
#         rospy.loginfo('\x1b[1M\rUse space to brake and tab to align wheels')
#         rospy.loginfo('\x1b[1M\rPress <ctrl-c> or <q> to exit')
#         rospy.loginfo('\x1b[1M\r*********************************************')
#         rospy.loginfo('\x1b[1M\r'
#                       '\033[34;1mSpeed: \033[32;1m%0.2f m/s, '
#                       '\033[34;1mSteer Angle: \033[32;1m%0.2f rad\033[0m',
#                       self.speed, self.steering_angle)

#     def get_key(self):
#         tty.setraw(sys.stdin.fileno())
#         select.select([sys.stdin], [], [], 0)
#         key = sys.stdin.read(1)
#         termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
#         return key

#     def key_loop(self):
#         self.settings = termios.tcgetattr(sys.stdin)
#         while 1:
#             key = self.get_key()
#             if key in key_bindings.keys():
#                 if key == control_keys['space']:
#                     self.speed = 0.0
#                 elif key == control_keys['tab']:
#                     self.steering_angle = 0.0
#                 else:
#                     self.speed = self.speed + key_bindings[key][0]
#                     self.steering_angle = \
#                             self.steering_angle + key_bindings[key][1]
#                     self.speed = clip(
#                         self.speed, self.speed_range[0], self.speed_range[1])
#                     self.steering_angle = clip(
#                         self.steering_angle,
#                         self.steering_angle_range[0],
#                         self.steering_angle_range[1])
#                 self.print_state()
#             elif key == '\x03' or key == '\x71':  # ctr-c or q
#                 break
#             else:
#                 continue
#         self.finalize()

#     def finalize(self):
#         rospy.loginfo('Halting motors, aligning wheels and exiting...')
#         self.settings = termios.tcgetattr(sys.stdin)
#         ackermann_cmd_msg = AckermannDriveStamped()
#         ackermann_cmd_msg.drive.speed = 0
#         ackermann_cmd_msg.drive.steering_angle = 0
#         self.motors_pub.publish(ackermann_cmd_msg)
#         sys.exit()

# if __name__ == '__main__':
#     rospy.init_node('ackermann_drive_keyop_node')
#     keyop = AckermannDriveKeyop(sys.argv[1:len(sys.argv)])


import roslib
import rospy
from ackermann_msgs.msg import AckermannDriveStamped
from std_msgs.msg import Float64
import sys, select, termios, tty

try:
    import thread
except ImportError:
    # For python3 compatibility
    import _thread
from numpy import clip
import math

control_keys = {
    'up'    : '\x41',
    'down'  : '\x42',
    'right' : '\x43',
    'left'  : '\x44',
    'space' : '\x20',
    'tab'   : '\x09'}

# Modify key bindings for desired increments
key_bindings = {
    '\x41' : ( 0.3 , 0.0),   # Up arrow: Increase speed by 0.3 m/s
    '\x42' : (-0.3 , 0.0),   # Down arrow: Decrease speed by 0.3 m/s
    '\x43' : ( 0.0 ,-0.18),  # Right arrow: Decrease steering angle by 0.18 rad
    '\x44' : ( 0.0 , 0.18),  # Left arrow: Increase steering angle by 0.18 rad
    '\x20' : ( 0.0 , 0.0),   # Space: Brake (speed and steering to 0)
    '\x09' : ( 0.0 , 0.0)}   # Tab: Align wheels (steering to 0)

class AckermannDriveKeyop:

    def __init__(self, args):
        # Set max speed and steering angle values
        max_speed = 2.0
        max_steering_angle = 0.9

        if len(args) > 2:
            cmd_topic = '/' + args[2]
        else:
            cmd_topic = 'ackermann_cmd'

        # Define speed and steering angle ranges
        self.speed_range = [-float(max_speed), float(max_speed)]
        self.steering_angle_range = [-float(max_steering_angle),
                                     float(max_steering_angle)]

        self.speed = 0
        self.steering_angle = 0
        self.wheel_diameter = 0.065  # Wheel diameter in meters
        self.motors_pub = rospy.Publisher(
            cmd_topic, AckermannDriveStamped, queue_size=1)
        rospy.Timer(rospy.Duration(1.0/5.0), self.pub_callback, oneshot=False)
        self.print_state()
        self.key_loop()

    def pub_callback(self, event):
        ackermann_cmd_msg = AckermannDriveStamped()
        ackermann_cmd_msg.drive.speed = self.speed
        ackermann_cmd_msg.drive.steering_angle = self.steering_angle

        # Convert speed from m/s to RPM
        rpm = self.speed_to_rpm(self.speed)
        rospy.loginfo("Publishing speed: %0.2f m/s (%0.2f RPM), steering_angle: %0.2f rad",
                      self.speed, rpm, self.steering_angle)

        self.motors_pub.publish(ackermann_cmd_msg)

    def speed_to_rpm(self, speed):
        # Calculate the circumference of the wheel
        circumference = math.pi * self.wheel_diameter
        # Convert speed to RPS (Revolutions Per Second)
        rps = speed / circumference
        # Convert RPS to RPM (Revolutions Per Minute)
        rpm = rps * 60
        return rpm

    def print_state(self):
        sys.stderr.write('\x1b[2J\x1b[H')
        rospy.loginfo('\x1b[1M\r*********************************************')
        rospy.loginfo('\x1b[1M\rUse arrows to change speed and steering angle')
        rospy.loginfo('\x1b[1M\rUse space to brake and tab to align wheels')
        rospy.loginfo('\x1b[1M\rPress <ctrl-c> or <q> to exit')
        rospy.loginfo('\x1b[1M\r*********************************************')
        rospy.loginfo('\x1b[1M\r'
                      '\033[34;1mSpeed: \033[32;1m%0.2f m/s, '
                      '\033[34;1mSteer Angle: \033[32;1m%0.2f rad\033[0m',
                      self.speed, self.steering_angle)

    def get_key(self):
        tty.setraw(sys.stdin.fileno())
        select.select([sys.stdin], [], [], 0)
        key = sys.stdin.read(1)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key

    def key_loop(self):
        self.settings = termios.tcgetattr(sys.stdin)
        while 1:
            key = self.get_key()
            if key in key_bindings.keys():
                if key == control_keys['space']:
                    self.speed = 0.0
                elif key == control_keys['tab']:
                    self.steering_angle = 0.0
                else:
                    self.speed = self.speed + key_bindings[key][0]
                    self.steering_angle = \
                            self.steering_angle + key_bindings[key][1]
                    self.speed = clip(
                        self.speed, self.speed_range[0], self.speed_range[1])
                    self.steering_angle = clip(
                        self.steering_angle,
                        self.steering_angle_range[0],
                        self.steering_angle_range[1])
                self.print_state()
            elif key == '\x03' or key == '\x71':  # ctr-c or q
                break
            else:
                continue
        self.finalize()

    def finalize(self):
        rospy.loginfo('Halting motors, aligning wheels and exiting...')
        self.settings = termios.tcgetattr(sys.stdin)
        ackermann_cmd_msg = AckermannDriveStamped()
        ackermann_cmd_msg.drive.speed = 0
        ackermann_cmd_msg.drive.steering_angle = 0
        self.motors_pub.publish(ackermann_cmd_msg)
        sys.exit()

if __name__ == '__main__':
    rospy.init_node('ackermann_drive_keyop_node')
    keyop = AckermannDriveKeyop(sys.argv[1:len(sys.argv)])
