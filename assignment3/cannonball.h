#include "std_lib_facilities.h"
#pragma once

double acclY();

double velY(double initVelocity, double time);

double PosX(double initPositionX, double initVelocityX, double time);
double PosY(double initPositionY, double initVelocityY, double time);

void printTime(double time);

double flightTime(double initVelocityY);

//-------------------------------------------------------------------------//
double getUserInputTheta();

double getUserInputInitVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double initVelocity);
double getVelocityY(double theta, double initVelocity);

vector<double> getVelocityVector(double theta, double initVelocity);

void printVector(vector<double> v);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, 
double velocityX, double velocityY);

//-----------------------------------------------------------------------------//

void playTargetPractice();