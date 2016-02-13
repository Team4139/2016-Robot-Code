#include "WPILib.h"
#include "X360Controller.cpp"
#include "Sensors.cpp"

struct Input_In
{

};

struct Input_Out
{

};

class Input
{
private:
	X360Controller* controller;
	Sensors* sensors;
public:
	Input()
	{
		controller = new X360Controller();
		sensors = new Sensors();
	}
	Input_Out Run(Input_In input)
	{
		Input_Out output;

		// Put all the code here

		return output;
	}
};
