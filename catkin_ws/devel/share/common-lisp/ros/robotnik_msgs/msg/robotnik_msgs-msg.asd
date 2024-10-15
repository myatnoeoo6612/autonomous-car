
(cl:in-package :asdf)

(defsystem "robotnik_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "AlarmSensor" :depends-on ("_package_AlarmSensor"))
    (:file "_package_AlarmSensor" :depends-on ("_package"))
    (:file "Alarms" :depends-on ("_package_Alarms"))
    (:file "_package_Alarms" :depends-on ("_package"))
    (:file "Axis" :depends-on ("_package_Axis"))
    (:file "_package_Axis" :depends-on ("_package"))
    (:file "BatteryDockingStatus" :depends-on ("_package_BatteryDockingStatus"))
    (:file "_package_BatteryDockingStatus" :depends-on ("_package"))
    (:file "BatteryDockingStatusStamped" :depends-on ("_package_BatteryDockingStatusStamped"))
    (:file "_package_BatteryDockingStatusStamped" :depends-on ("_package"))
    (:file "BatteryStatus" :depends-on ("_package_BatteryStatus"))
    (:file "_package_BatteryStatus" :depends-on ("_package"))
    (:file "BatteryStatusStamped" :depends-on ("_package_BatteryStatusStamped"))
    (:file "_package_BatteryStatusStamped" :depends-on ("_package"))
    (:file "BoolArray" :depends-on ("_package_BoolArray"))
    (:file "_package_BoolArray" :depends-on ("_package"))
    (:file "Cartesian_Euler_pose" :depends-on ("_package_Cartesian_Euler_pose"))
    (:file "_package_Cartesian_Euler_pose" :depends-on ("_package"))
    (:file "Data" :depends-on ("_package_Data"))
    (:file "_package_Data" :depends-on ("_package"))
    (:file "ElevatorAction" :depends-on ("_package_ElevatorAction"))
    (:file "_package_ElevatorAction" :depends-on ("_package"))
    (:file "ElevatorStatus" :depends-on ("_package_ElevatorStatus"))
    (:file "_package_ElevatorStatus" :depends-on ("_package"))
    (:file "Interfaces" :depends-on ("_package_Interfaces"))
    (:file "_package_Interfaces" :depends-on ("_package"))
    (:file "InverterStatus" :depends-on ("_package_InverterStatus"))
    (:file "_package_InverterStatus" :depends-on ("_package"))
    (:file "LaserMode" :depends-on ("_package_LaserMode"))
    (:file "_package_LaserMode" :depends-on ("_package"))
    (:file "LaserStatus" :depends-on ("_package_LaserStatus"))
    (:file "_package_LaserStatus" :depends-on ("_package"))
    (:file "MotorHeadingOffset" :depends-on ("_package_MotorHeadingOffset"))
    (:file "_package_MotorHeadingOffset" :depends-on ("_package"))
    (:file "MotorPID" :depends-on ("_package_MotorPID"))
    (:file "_package_MotorPID" :depends-on ("_package"))
    (:file "MotorStatus" :depends-on ("_package_MotorStatus"))
    (:file "_package_MotorStatus" :depends-on ("_package"))
    (:file "MotorsStatus" :depends-on ("_package_MotorsStatus"))
    (:file "_package_MotorsStatus" :depends-on ("_package"))
    (:file "MotorsStatusDifferential" :depends-on ("_package_MotorsStatusDifferential"))
    (:file "_package_MotorsStatusDifferential" :depends-on ("_package"))
    (:file "OdomCalibrationStatus" :depends-on ("_package_OdomCalibrationStatus"))
    (:file "_package_OdomCalibrationStatus" :depends-on ("_package"))
    (:file "OdomCalibrationStatusStamped" :depends-on ("_package_OdomCalibrationStatusStamped"))
    (:file "_package_OdomCalibrationStatusStamped" :depends-on ("_package"))
    (:file "OdomManualCalibrationStatus" :depends-on ("_package_OdomManualCalibrationStatus"))
    (:file "_package_OdomManualCalibrationStatus" :depends-on ("_package"))
    (:file "OdomManualCalibrationStatusStamped" :depends-on ("_package_OdomManualCalibrationStatusStamped"))
    (:file "_package_OdomManualCalibrationStatusStamped" :depends-on ("_package"))
    (:file "Pose2DArray" :depends-on ("_package_Pose2DArray"))
    (:file "_package_Pose2DArray" :depends-on ("_package"))
    (:file "Pose2DStamped" :depends-on ("_package_Pose2DStamped"))
    (:file "_package_Pose2DStamped" :depends-on ("_package"))
    (:file "PresenceSensor" :depends-on ("_package_PresenceSensor"))
    (:file "_package_PresenceSensor" :depends-on ("_package"))
    (:file "PresenceSensorArray" :depends-on ("_package_PresenceSensorArray"))
    (:file "_package_PresenceSensorArray" :depends-on ("_package"))
    (:file "QueryAlarm" :depends-on ("_package_QueryAlarm"))
    (:file "_package_QueryAlarm" :depends-on ("_package"))
    (:file "Register" :depends-on ("_package_Register"))
    (:file "_package_Register" :depends-on ("_package"))
    (:file "Registers" :depends-on ("_package_Registers"))
    (:file "_package_Registers" :depends-on ("_package"))
    (:file "ReturnMessage" :depends-on ("_package_ReturnMessage"))
    (:file "_package_ReturnMessage" :depends-on ("_package"))
    (:file "RobotnikMotorsStatus" :depends-on ("_package_RobotnikMotorsStatus"))
    (:file "_package_RobotnikMotorsStatus" :depends-on ("_package"))
    (:file "SafetyModuleStatus" :depends-on ("_package_SafetyModuleStatus"))
    (:file "_package_SafetyModuleStatus" :depends-on ("_package"))
    (:file "SetElevatorAction" :depends-on ("_package_SetElevatorAction"))
    (:file "_package_SetElevatorAction" :depends-on ("_package"))
    (:file "SetElevatorActionFeedback" :depends-on ("_package_SetElevatorActionFeedback"))
    (:file "_package_SetElevatorActionFeedback" :depends-on ("_package"))
    (:file "SetElevatorActionGoal" :depends-on ("_package_SetElevatorActionGoal"))
    (:file "_package_SetElevatorActionGoal" :depends-on ("_package"))
    (:file "SetElevatorActionResult" :depends-on ("_package_SetElevatorActionResult"))
    (:file "_package_SetElevatorActionResult" :depends-on ("_package"))
    (:file "SetElevatorFeedback" :depends-on ("_package_SetElevatorFeedback"))
    (:file "_package_SetElevatorFeedback" :depends-on ("_package"))
    (:file "SetElevatorGoal" :depends-on ("_package_SetElevatorGoal"))
    (:file "_package_SetElevatorGoal" :depends-on ("_package"))
    (:file "SetElevatorResult" :depends-on ("_package_SetElevatorResult"))
    (:file "_package_SetElevatorResult" :depends-on ("_package"))
    (:file "State" :depends-on ("_package_State"))
    (:file "_package_State" :depends-on ("_package"))
    (:file "StringArray" :depends-on ("_package_StringArray"))
    (:file "_package_StringArray" :depends-on ("_package"))
    (:file "StringStamped" :depends-on ("_package_StringStamped"))
    (:file "_package_StringStamped" :depends-on ("_package"))
    (:file "SubState" :depends-on ("_package_SubState"))
    (:file "_package_SubState" :depends-on ("_package"))
    (:file "alarmmonitor" :depends-on ("_package_alarmmonitor"))
    (:file "_package_alarmmonitor" :depends-on ("_package"))
    (:file "alarmsmonitor" :depends-on ("_package_alarmsmonitor"))
    (:file "_package_alarmsmonitor" :depends-on ("_package"))
    (:file "encoders" :depends-on ("_package_encoders"))
    (:file "_package_encoders" :depends-on ("_package"))
    (:file "inputs_outputs" :depends-on ("_package_inputs_outputs"))
    (:file "_package_inputs_outputs" :depends-on ("_package"))
    (:file "named_input_output" :depends-on ("_package_named_input_output"))
    (:file "_package_named_input_output" :depends-on ("_package"))
    (:file "named_inputs_outputs" :depends-on ("_package_named_inputs_outputs"))
    (:file "_package_named_inputs_outputs" :depends-on ("_package"))
    (:file "ptz" :depends-on ("_package_ptz"))
    (:file "_package_ptz" :depends-on ("_package"))
  ))