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
