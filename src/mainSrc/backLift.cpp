#include "main.h"

//HELPER FUNCTIONS
void setBackLift(int power) {
  LiftBack.move_voltage(power);
}

//DRIVER CONTROL FUNCTIONS
void setBackLiftMotors() {
  int backLiftPower = 127 * (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
  setBackLift(backLiftPower);
}


//AUTONOMOUS

void BackLiftUp(double btarget) {
  int start_time = pros::millis();

  int current_time = 0;
  resetDriveEncoders();
  resetPID();

  pidSetTarget(btarget);

  while (true) {
    current_time = pros::millis();

    int travel =
        LiftBack.get_encoder_units();

    int voltage = pidCalculate(travel) * 12'000;
    voltage =
        std::clamp(voltage, last_voltage - dVoltage, last_voltage + dVoltage);

    setBackLift(voltage);

    last_voltage = voltage;

    if ((target > travel - targetRange) && (target < travel + targetRange))
      break;
    else if (current_time - start_time >
             max_time)
      break;

    pros::delay(20);
  }
  }
