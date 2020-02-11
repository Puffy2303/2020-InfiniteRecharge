#pragma once

#include <vector>

#include "controllers/Controllers.h"

#define __CONTROLMAP_USING_JOYSTICK__ false

struct ControlMap {
  static void InitSmartControllerGroup(wml::controllers::SmartControllerGroup &contGroup);
  // ---------------- Defined Ports ------------------

  // Controllers
  static const int XboxController1Port, XboxController2Port;
  static const int JoyController1Port, JoyController2Port, JoyController3Port;

  static const int Driver = 1;
  static const int CoDriver = 2;
  static const int override = 3;

  static const double joyDeadzone;
  static const double xboxDeadzone;
  static const double triggerDeadzone;

  // Drive System
  static const int DriveMAXportFL, DriveMAXportFR, DriveMAXportBL, DriveMAXportBR;
  static const int ChangeGearPort1, ChangeGearPort2;
  static const int Shift2PTOPort1, Shift2PTOPort2;
  static const double ChangeGearTime;
  static const double MaxDrivetrainSpeed;
  static const double MaxDrivetrainAcceleration;
  static const double DriveTestCaseRotations;

  // Turret
  static const bool TuneTurretPID;
  static const bool TuneAnglePID;
  static const int TurretFlyWheelPort, TurretRotationPort, TurretAnglePort, TurretFlyWheelPort2;
  static const int TurretLeftLimitPort, TurretRightLimitPort, TurretAngleDownLimitPort;
  static const bool TurretLeftLimitInvert, TurretRightLimitInvert, TurretAngleDownLimitInvert;
  static const double TurretDistanceSetpoint1, TurretDistanceSetpoint2, TurretDistanceSetpoint3;
  static const double TurretZeroTimeoutSeconds;
  static const double TurretEncoderSafeZone;
  static const double MaxTurretSpeed, MaxTurretAngularSpeed, FlyWheelVelocity;
  static const double TurretEncoderRotations;
  static const double MaxAngleEncoderRotations;
  static const double TurretRatio;

  // Y Axis Setpoints
  static const double AngleSetpoint1;
  static const double AngleSetpoint2;
  static const double AngleSetpoint3;
  static const double AngleSetpoint4;
  static const double AngleSetpoint5;
  static const double AngleSetpoint6;
  static const double AngleSetpoint7;
  static const double AngleSetpoint8;
  static const double AngleSetpoint9;
  static const double AngleSetpoint10;

  // Intake
  static const int IntakeMotorPort;
  static const int IntakeDownPort1, IntakeDownPort2;
  static const double PannelActuationTime;
  static const double IntakeDownActuationTime;

  // MagLoader
  static const int MagLoaderMotorPort;
  static const int StartMagLimitPort, Position1LimitPort, Position5LimitPort;
  static const double MagTestCaseRotations;
  //static const double ManualMag;

  //Control Pannel
  static const int ControlPannelPort;
  static const int ControlPannelUpPort;
  static const int ControlPannelUpSolPort1;
  static const int ControlPannelUpSolPort2;
  static const double ControlPannelActuationTime;
  static const bool ControlClimb;

  // Climber
  static const int ClimberActuatorPort1, ClimberActuatorPort2;
  static const double ClimberActuationTime;
  static const int Shift1PTOPort, Shift2PTOPort;
  static const int ClimberMotor1Port;
  static const double LiftMaxSpeed;
  static const double ShiftPTOActuationTime;


  // Control System
  static const int PressureSensorPort;
  static const int CompressorPort;
  static const int CamFOV;

  // --------------- Defined Buttons -----------------

  // Turret PID Tuner
  static const wml::controllers::tButton kpUP, kpDOWN;
  static const wml::controllers::tButton kiUP, kiDOWN;
  static const wml::controllers::tButton kdUP, kdDOWN;

  // Drivetrain
  #if __CONTROLMAP_USING_JOYSTICK__
  static const wml::controllers::tAxis DrivetrainForward, DrivetrainTurn;
  #else
  static const wml::controllers::tAxis DrivetrainLeft, DrivetrainRight;
  #endif
  static const wml::controllers::tButton ReverseDrivetrain;
  static const wml::controllers::tButton ShiftGears;
  static const wml::controllers::tButton Defence;

  // Turret
  #if __CONTROLMAP_USING_JOYSTICK__
  //@TODO
  #else
  static const wml::controllers::tAxis TurretAutoAimAxis;
  static const wml::controllers::tButton TurretAutoAim;

  static const wml::controllers::tAxis TurretManualRotate;
  static const wml::controllers::tAxis TurretManualAngle;
  static const wml::controllers::tAxis TurretFlyWheelSpinUp;
  static const wml::controllers::tButton TurretFire; // Might get rid of, if i automate Max speed of flywheel to fire.
  #endif


  // Intake
  #if __CONTROLMAP_USING_JOYSTICK__

  #else
  static const wml::controllers::tAxis Intake;
  static const wml::controllers::tAxis Outake;
  static const wml::controllers::tButton DownIntake;
  #endif

  //Control Pannel
  #if __CONTROLMAP_USING_JOYSTICK__

  #else 
  static const wml::controllers::tPOV ControlPannelUp;
  static const wml::controllers::tPOV SpinControlPannelLeft;
  static const wml::controllers::tPOV SpinControlPannelRight;
  static const wml::controllers::tPOV ControlPannelDown;

  #endif

  // MagLoader
  static const wml::controllers::tPOV ShiftMagazinePOV;

  static const wml::controllers::tButton ShiftUpMagazine;
  static const wml::controllers::tButton ShiftDownMagazine;
  static const wml::controllers::tButton ManualMag;
  //Climber
  #if __CONTROLMAP_USING_JOYSTICK__

  #else
  static const wml::controllers::tAxis ClimberControl;
  static const wml::controllers::tButton ClimberUp;
  static const wml::controllers::tButton ClimberDown;
  static const wml::controllers::tButton Shift2PTO; // Toggle
  #endif

  //override buttons 
  #if __CONTROLMAP_USING_JOYSTICK__

  #else
  static const wml::controllers::tButton R1;
  static const wml::controllers::tButton R2;
  static const wml::controllers::tButton R3;
  static const wml::controllers::tButton G1;
  static const wml::controllers::tButton G2;
  static const wml::controllers::tButton G3;
  #endif

};