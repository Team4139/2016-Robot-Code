#include "WPILib.h"
#include "Joystick.h"
#include "nt_Value.h"
#include "Math.h"
class Robot: public SampleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick; // only joystick
	Victor shooter;
	bool isMoving=false;

public:
	Robot() :
		myRobot(0, 1, 2, 3),
		stick(5),
		shooter(4)
		{
		myRobot.SetExpiration(0.1);
		SmartDashboard::init();

}
	void OperatorControl()
	{
		isMoving=false;
		while (IsOperatorControl() && IsEnabled())
		{
			bool isArcade = false;
			if(stick.GetRawButton(1))
				isArcade = !isArcade;
			if(isArcade)
				myRobot.ArcadeDrive(stick.GetRawAxis(1), true);
			if(!isArcade)
				myRobot.TankDrive(stick.GetRawAxis(4), stick.GetRawAxis(1), true);
			Wait(0.005);
		}
		while(IsAutonomous() && IsEnabled())
		{
			std::cout << "Test";
			double xVal = SmartDashboard::GetNumber("COG_X", 0.0);
			std::cout<<"xVal is currently "<<xVal<<std::endl;
						double speed = (1/160)*(xVal-160);
			if(abs(160-xVal)<25){
				myRobot.TankDrive(0.25, 0.25);
			}
			else if(speed > 0.5){
				myRobot.TankDrive(0.5*speed, -0.5*speed);
			}
			else{
				myRobot.TankDrive(speed, -speed);
			}
			Wait(0.005);
		}
	}
};


START_ROBOT_CLASS(Robot)