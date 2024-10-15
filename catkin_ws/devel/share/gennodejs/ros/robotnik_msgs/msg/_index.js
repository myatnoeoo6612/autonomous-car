
"use strict";

let InverterStatus = require('./InverterStatus.js');
let OdomManualCalibrationStatusStamped = require('./OdomManualCalibrationStatusStamped.js');
let ReturnMessage = require('./ReturnMessage.js');
let ElevatorStatus = require('./ElevatorStatus.js');
let named_input_output = require('./named_input_output.js');
let BoolArray = require('./BoolArray.js');
let Pose2DArray = require('./Pose2DArray.js');
let MotorsStatus = require('./MotorsStatus.js');
let BatteryStatusStamped = require('./BatteryStatusStamped.js');
let AlarmSensor = require('./AlarmSensor.js');
let Alarms = require('./Alarms.js');
let Axis = require('./Axis.js');
let BatteryStatus = require('./BatteryStatus.js');
let StringArray = require('./StringArray.js');
let StringStamped = require('./StringStamped.js');
let Pose2DStamped = require('./Pose2DStamped.js');
let LaserStatus = require('./LaserStatus.js');
let SafetyModuleStatus = require('./SafetyModuleStatus.js');
let alarmsmonitor = require('./alarmsmonitor.js');
let OdomCalibrationStatus = require('./OdomCalibrationStatus.js');
let MotorPID = require('./MotorPID.js');
let Data = require('./Data.js');
let encoders = require('./encoders.js');
let OdomCalibrationStatusStamped = require('./OdomCalibrationStatusStamped.js');
let Interfaces = require('./Interfaces.js');
let LaserMode = require('./LaserMode.js');
let MotorsStatusDifferential = require('./MotorsStatusDifferential.js');
let PresenceSensorArray = require('./PresenceSensorArray.js');
let State = require('./State.js');
let inputs_outputs = require('./inputs_outputs.js');
let ptz = require('./ptz.js');
let Register = require('./Register.js');
let alarmmonitor = require('./alarmmonitor.js');
let RobotnikMotorsStatus = require('./RobotnikMotorsStatus.js');
let Cartesian_Euler_pose = require('./Cartesian_Euler_pose.js');
let PresenceSensor = require('./PresenceSensor.js');
let OdomManualCalibrationStatus = require('./OdomManualCalibrationStatus.js');
let Registers = require('./Registers.js');
let BatteryDockingStatus = require('./BatteryDockingStatus.js');
let ElevatorAction = require('./ElevatorAction.js');
let BatteryDockingStatusStamped = require('./BatteryDockingStatusStamped.js');
let MotorHeadingOffset = require('./MotorHeadingOffset.js');
let QueryAlarm = require('./QueryAlarm.js');
let named_inputs_outputs = require('./named_inputs_outputs.js');
let SubState = require('./SubState.js');
let MotorStatus = require('./MotorStatus.js');
let SetElevatorActionFeedback = require('./SetElevatorActionFeedback.js');
let SetElevatorActionGoal = require('./SetElevatorActionGoal.js');
let SetElevatorActionResult = require('./SetElevatorActionResult.js');
let SetElevatorGoal = require('./SetElevatorGoal.js');
let SetElevatorResult = require('./SetElevatorResult.js');
let SetElevatorFeedback = require('./SetElevatorFeedback.js');
let SetElevatorAction = require('./SetElevatorAction.js');

module.exports = {
  InverterStatus: InverterStatus,
  OdomManualCalibrationStatusStamped: OdomManualCalibrationStatusStamped,
  ReturnMessage: ReturnMessage,
  ElevatorStatus: ElevatorStatus,
  named_input_output: named_input_output,
  BoolArray: BoolArray,
  Pose2DArray: Pose2DArray,
  MotorsStatus: MotorsStatus,
  BatteryStatusStamped: BatteryStatusStamped,
  AlarmSensor: AlarmSensor,
  Alarms: Alarms,
  Axis: Axis,
  BatteryStatus: BatteryStatus,
  StringArray: StringArray,
  StringStamped: StringStamped,
  Pose2DStamped: Pose2DStamped,
  LaserStatus: LaserStatus,
  SafetyModuleStatus: SafetyModuleStatus,
  alarmsmonitor: alarmsmonitor,
  OdomCalibrationStatus: OdomCalibrationStatus,
  MotorPID: MotorPID,
  Data: Data,
  encoders: encoders,
  OdomCalibrationStatusStamped: OdomCalibrationStatusStamped,
  Interfaces: Interfaces,
  LaserMode: LaserMode,
  MotorsStatusDifferential: MotorsStatusDifferential,
  PresenceSensorArray: PresenceSensorArray,
  State: State,
  inputs_outputs: inputs_outputs,
  ptz: ptz,
  Register: Register,
  alarmmonitor: alarmmonitor,
  RobotnikMotorsStatus: RobotnikMotorsStatus,
  Cartesian_Euler_pose: Cartesian_Euler_pose,
  PresenceSensor: PresenceSensor,
  OdomManualCalibrationStatus: OdomManualCalibrationStatus,
  Registers: Registers,
  BatteryDockingStatus: BatteryDockingStatus,
  ElevatorAction: ElevatorAction,
  BatteryDockingStatusStamped: BatteryDockingStatusStamped,
  MotorHeadingOffset: MotorHeadingOffset,
  QueryAlarm: QueryAlarm,
  named_inputs_outputs: named_inputs_outputs,
  SubState: SubState,
  MotorStatus: MotorStatus,
  SetElevatorActionFeedback: SetElevatorActionFeedback,
  SetElevatorActionGoal: SetElevatorActionGoal,
  SetElevatorActionResult: SetElevatorActionResult,
  SetElevatorGoal: SetElevatorGoal,
  SetElevatorResult: SetElevatorResult,
  SetElevatorFeedback: SetElevatorFeedback,
  SetElevatorAction: SetElevatorAction,
};
