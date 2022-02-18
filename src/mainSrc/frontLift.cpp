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
