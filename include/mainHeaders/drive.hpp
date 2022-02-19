#include "main.h"

//SECONDARY FUNCTIONS
void setDrive(int left, int right);
void resetDriveEncoders();

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

// AUTONOMOUS FUNCTIONS
void translate(double dtarget);
// AUTONOMOUS FUNCTIONS
int max_time = 10000;
int last_voltage = 0;
int dVoltage = 450;
int targetRange = 15;

void gyroTurn(int degrees, int voltage);
