#include "main.h"

//HELPER FUNCTIONS
void setFrontLift(int power) {
  LiftFrontLeft.move_voltage(power);
  LiftFrontRight.move_voltage(power);
}

//DRIVER CONTROL FUNCTIONS
void setFrontLiftMotors() {
  int liftPower = 127 * (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
  setFrontLift(liftPower);
}

//AUTON

void FrontLiftUp(double ftarget) {
  int startTime = pros::millis();

  int currentTime = 0;
  resetDriveEncoders();
  resetPID();

  pidSetTarget(ftarget);

  while (true) {
    currentTime = pros::millis();

    int travel =
        (LiftFrontLeft.get_encoder_units() + LiftFrontRight.get_encoder_units()) / 2;

    int voltage = pidCalculate(travel) * 12'000;
    voltage =
        std::clamp(voltage, last_voltage - dVoltage, last_voltage + dVoltage);

    setFrontLift(voltage);

    last_voltage = voltage;

    if ((target > travel - targetRange) && (target < travel + targetRange))
      break;
    else if (currentTime - startTime >
             max_time)
      break;

    pros::delay(20);
  }
  }
