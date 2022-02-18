#include "main.h"

//SECONDARY FUNCTIONS
void setDrive(int left, int right) {
  BackLeft.move_voltage(left);
  BackRight.move_voltage(right);
  FrontLeft.move_voltage(left);
  FrontRight.move_voltage(right);
}

void resetDriveEncoders(){
  BackLeft.tare_position();
  FrontLeft.tare_position();
  BackRight.tare_position();
  FrontRight.tare_position();
}

//DRIVER CONTROL FUNCTIONS
void setDriveMotors() {
  int power = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int turn = Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  int leftPower = power;
  int rightPower = power;
  if(abs(power) < 10)
    leftPower = 0;
    rightPower = 0;
  if(turn > 10){
    leftPower*=1.5;
  }
  if(turn < -10){
    rightPower*=1.5;
  }
  setDrive(leftPower, rightPower);
}

//AUTONOMUS FUNCTIONS
/**
void translate(int units, int voltage) {
  int direction = abs(units) / units;
  // Motor Encoder Reset
  resetDriveEncoders();
  //Drive Forwards until reached
  while(fabs(FrontLeft.get_position()) < abs(units)) {
    setDrive(voltage * direction, voltage * direction);
    pros::delay(10);
  }
  //Brief brake
  setDrive(-10 * direction, -10 * direction);
  pros::delay(50);
  //Set drive neutral
  setDrive(0, 0);
}
Need to integrate PID
*/
