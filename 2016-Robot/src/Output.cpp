#include "WPILib.h"
#include "Wheels.cpp"
#include "Lifter.cpp"
#include "Loader.cpp"

struct Output_In
{

};
struct Output_Out
{

};
class Output
{
private:
	Wheels* wheels;
	Lifter* lifter;
	Loader* loader;
public:
	Output()
	{
		wheels = new Wheels();
		lifter = new Lifter();
		loader = new Loader();
	}
	Output_Out Run(Output_In input)
	{
		Output_Out output;

		// Code here

		return output;
	}
};
