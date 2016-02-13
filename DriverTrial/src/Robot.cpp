#include "WPILib.h"
class Robot: public SampleRobot
{
	RobotDrive myRobot;
	Joystick stick;

public:
	Robot() :
			myRobot(0, 1, 2, 3),
			stick(5)
	{
		myRobot.SetExpiration(0.1);
	}

	void OperatorControl()
	{
		while (IsOperatorControl() && IsEnabled())
		{
			int mode = 0; // 0: TankDrive, 1: ArcadeDrive, 2: Silver's Thing
			if(stick.GetRawButton(1)){
				mode=0; // Set mode to TankDrive on press of "A" button
				Wait(0.25);
			}
			if(stick.GetRawButton(2)){
				mode=1; // Set mode to ArcadeDrive on press of "B" button
				Wait(0.25);
			}
			if(stick.GetRawButton(3)){
				mode=2; // Set mode to Silver's Thing on press of "X" button
				Wait(0.25);
			}
			switch(mode){
			case 0:
				myRobot.TankDrive(stick.GetRawAxis(1), stick.GetRawAxis(5));
				break;
			case 1:
				myRobot.ArcadeDrive(stick.GetRawAxis(1), stick.GetRawAxis(4), true);
				break;
			case 2:
				int val;
				if(stick.GetRawAxis(2)>0.25)
					val=-1*stick.GetRawAxis(2);
				if(stick.GetRawAxis(3)>0.25)
					val=stick.GetRawAxis(3);
				myRobot.ArcadeDrive(val, stick.GetRawAxis(4), true);
			}
			Wait(0.005);
		}
	}

};

START_ROBOT_CLASS(Robot)
