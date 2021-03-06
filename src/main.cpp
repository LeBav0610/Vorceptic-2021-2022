#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 int auton_select = 0;

void selectAuton() {
  while (true) {
    if (Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
      auton_select++;
      if (auton_select > 1) {
        auton_select = 0;
      }
    } else if (Controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      break;
    }

    pros::delay(50);
  }
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello there...");
	pros::lcd::set_text(2, "1140M");

	//pros::lcd::register_btn1_cb(on_center_button);

	BackLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	FrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	BackRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	FrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	LiftFrontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	LiftFrontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	LiftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	pros::ADIGyro gyro('A');
	pros::delay(2000);

	selectAuton();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */






void skills(){
	driveForward(1000);
	gyroTurn(-85, 100);
	FrontLiftUp(500);
	driveForward(5000);
	gyroTurn(-85, 100);
	driveForward(1000);
}

void autonomous() {
	if (auton_select == 1) {
    skills();
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol(){
	while(true) {
		// Drive Controller
		setDriveMotors();
		// Front Lift Controller
		setFrontLiftMotors();
		// Back Lift CONTROLLER
		setBackLiftMotors();
		pros::delay(10);
	}
}
