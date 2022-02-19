#include "main.h"
#include "api.h"
#include <algorithm>
#include <cmath>

const double kP = 0.5;
const double kI = 0.0;
const double kD = 0.0;
const double integralMin = -100;
const double integralMax = 100;
const double maxIntegrateError = 0.5;

double target = 0.0;
double error = 0.0;
double lastError = 0.0;
double integral = 0.0;
double derivative = 0.0;
int time = 0;
int lastTime = 0;

double pidCalculate(double currentValue);
void resetPID();
void pidSetTarget(double value);
