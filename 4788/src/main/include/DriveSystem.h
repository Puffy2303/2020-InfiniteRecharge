#pragma once 

#include "controllers/Controllers.h"
#include "strategy/Strategy.h"
#include "RobotMap.h"
#include "Drivetrain.h"


// Class that Runs In Manual Drive e.g Human Drivers
class DrivetrainManual : public wml::Strategy {
  public:
    DrivetrainManual(std::string name, wml::Drivetrain &drivetrain, wml::actuators::DoubleSolenoid &ChangeGears, wml::controllers::SmartControllerGroup &contGroup);

    void OnUpdate(double dt) override;

  private:
    wml::Drivetrain &_drivetrain;
    wml::actuators::BinaryActuator &_ChangeGears;
    wml::controllers::SmartControllerGroup &_contGroup;
    double leftSpeed = 0, rightSpeed = 0;
    double currentSpeed;
};

// Class that Runs in Autonomous
class DrivetrainAuto : public wml::Strategy {
  public:
    DrivetrainAuto(wml::Drivetrain &drivetrain, wml::control::PIDGains gains);

    void OnUpdate(double dt) override;

  private:
    wml::Drivetrain &_drivetrain;
    wml::control::PIDController _pid;
    double leftSpeed = 0, rightSpeed = 0;
    double currentSpeed;
};

// Class that Runs in Test Mode
class DrivetrainTest : public wml::Strategy {
  public:
    DrivetrainTest(wml::Drivetrain &drivetrain, wml::control::PIDGains gains);

    void OnUpdate(double dt) override;

  private:
    wml::Drivetrain &_drivetrain;
    wml::control::PIDController _pid;
    double leftSpeed = 0, rightSpeed = 0;

    bool drivetest = true;

    bool leftFwdTest = true;
    bool rightFwdTest = true;
    bool leftRevTest = true;
    bool rightRevTest = true;
};