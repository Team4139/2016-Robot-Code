/*
 * XBoxController.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Warren Hu
 */

#ifndef XBOXCONTROLLER_H_
#define XBOXCONTROLLER_H_
#include "WPILib.h";

struct ControllerInput{
	//Wheels
	float rotLeftWheelsSpeed, rotRightWheelsSpeed;

	//Shooter
	float intakeSpeed, outputSpeed;
	float shooterAngle;

};

class XBoxController {
public:
	//
	XBoxController();
	virtual ~XBoxController();

	//Takes in a reference to the input structure then modifies it
	void getInput(ControllerInput &in);
};

#endif /* XBOXCONTROLLER_H_ */
