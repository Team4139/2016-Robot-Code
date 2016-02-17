#include "WPILib.h"
#include "Math.h"
struct Sensors_In
{
	bool resetGyro;
	AnalogInput ultrasonic;
};
struct Sensors_Out
{
	float returnGyroAngle;
	float returnAccelX, returnAccelY, returnAccelz;
	float returnDistance;

	const int ultrasonicChannel = 0; //analog input pin
	double currentDistance; //distance measured from the ultrasonic sensor values
	const double valueTocm = 0.125; //factor to convert sensor values to a distance in centimeter
};
class Sensors
{
private:
	//you do this
public:
	Sensors()
	{
		//you do this
		ultrasonic(ultrasonicChannel),
	}
	Sensors_Out Run(Sensors_In input)
	{

		currentDistance = (ultrasonic.GetValue()) * valueTocm; //sensor returns a value from 0-4095 that is scaled to inches

		std::cout<<currentDistance <<std::endl;
		Sensors_Out output;
		// code here

		return output;
	}
};
