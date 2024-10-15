
"use strict";

let home = require('./home.js')
let set_float_value = require('./set_float_value.js')
let set_height = require('./set_height.js')
let ResetFromSubState = require('./ResetFromSubState.js')
let SetByte = require('./SetByte.js')
let set_digital_output = require('./set_digital_output.js')
let SetString = require('./SetString.js')
let InsertTask = require('./InsertTask.js')
let set_odometry = require('./set_odometry.js')
let GetMotorsHeadingOffset = require('./GetMotorsHeadingOffset.js')
let set_ptz = require('./set_ptz.js')
let set_CartesianEuler_pose = require('./set_CartesianEuler_pose.js')
let SetNamedDigitalOutput = require('./SetNamedDigitalOutput.js')
let get_alarms = require('./get_alarms.js')
let SetMotorStatus = require('./SetMotorStatus.js')
let SetBuzzer = require('./SetBuzzer.js')
let GetPTZ = require('./GetPTZ.js')
let get_digital_input = require('./get_digital_input.js')
let set_modbus_register = require('./set_modbus_register.js')
let set_named_digital_output = require('./set_named_digital_output.js')
let SetTransform = require('./SetTransform.js')
let set_analog_output = require('./set_analog_output.js')
let SetMotorPID = require('./SetMotorPID.js')
let axis_record = require('./axis_record.js')
let ack_alarm = require('./ack_alarm.js')
let SetMotorMode = require('./SetMotorMode.js')
let SetLaserMode = require('./SetLaserMode.js')
let SetElevator = require('./SetElevator.js')
let get_mode = require('./get_mode.js')
let QueryAlarms = require('./QueryAlarms.js')
let GetBool = require('./GetBool.js')
let SetEncoderTurns = require('./SetEncoderTurns.js')
let get_modbus_register = require('./get_modbus_register.js')
let GetPOI = require('./GetPOI.js')
let set_mode = require('./set_mode.js')
let enable_disable = require('./enable_disable.js')

module.exports = {
  home: home,
  set_float_value: set_float_value,
  set_height: set_height,
  ResetFromSubState: ResetFromSubState,
  SetByte: SetByte,
  set_digital_output: set_digital_output,
  SetString: SetString,
  InsertTask: InsertTask,
  set_odometry: set_odometry,
  GetMotorsHeadingOffset: GetMotorsHeadingOffset,
  set_ptz: set_ptz,
  set_CartesianEuler_pose: set_CartesianEuler_pose,
  SetNamedDigitalOutput: SetNamedDigitalOutput,
  get_alarms: get_alarms,
  SetMotorStatus: SetMotorStatus,
  SetBuzzer: SetBuzzer,
  GetPTZ: GetPTZ,
  get_digital_input: get_digital_input,
  set_modbus_register: set_modbus_register,
  set_named_digital_output: set_named_digital_output,
  SetTransform: SetTransform,
  set_analog_output: set_analog_output,
  SetMotorPID: SetMotorPID,
  axis_record: axis_record,
  ack_alarm: ack_alarm,
  SetMotorMode: SetMotorMode,
  SetLaserMode: SetLaserMode,
  SetElevator: SetElevator,
  get_mode: get_mode,
  QueryAlarms: QueryAlarms,
  GetBool: GetBool,
  SetEncoderTurns: SetEncoderTurns,
  get_modbus_register: get_modbus_register,
  GetPOI: GetPOI,
  set_mode: set_mode,
  enable_disable: enable_disable,
};
