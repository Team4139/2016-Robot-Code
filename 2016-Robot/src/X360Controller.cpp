/*
 *  X360Controller.cpp
 *  	Takes in various user inputs and sends them out.
 *
 */
//
#include "WPILib.h"
#include "math.h"

struct X360Controller_In
{
	//
};

struct X360Controller_Out
{

};

class X360Controller
{
private:
	Joystick* stick;

public:

	X360Controller()
	{
		stick = new Joystick(0);
	}

	X360Controller_Out Run(X360Controller_In input)
	{
		X360Controller_Out output;
		return output;
	}
};
