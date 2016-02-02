#include "WPILib.h"

/**
 * This sample program shows how to control a motor using a joystick. In the operator
 * control part of the program, the joystick is read and the value is written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as range from
 * -1 to 1 making it easy to work together. The program also delays a short time in the loop
 * to allow other threads to run. This is generally a good idea, especially since the joystick
 * values are only transmitted from the Driver Station once every 20ms.
 */
class Robot : public SampleRobot {
	Joystick m_stick;

	// The motor to control with the Joystick.
	// This uses a Talon speed controller; use the Victor or Jaguar classes for
	//   other speed controllers.
	Talon m_motor;
	Talon m_motor4;

	bool shooterEnabled = false;
	bool intakeEnabled = false;

	// update every 0.005 seconds/5 milliseconds.
	double kUpdatePeriod = 0.005;

public:
	Robot() :
			m_stick(0), // Initialize Joystick on port 0.
			m_motor(0), // Initialize the Talon on channel 0.
			m_motor4(4)
	{
	}

	/**
	 * Runs the motor from the output of a Joystick.
	 */
	void OperatorControl() {
		while (IsOperatorControl() && IsEnabled()) {
			// Set the motor controller's output.
			// Thss takes a number from -1 (100% speed in reverse) to +1 (100% speed forwards).
			if(shooterEnabled == true)
			{
				m_motor.Set(0.5);
				m_motor4.Set(-0.5);
				Wait(0.25);
			}
			if(shooterEnabled == false)
			{
				m_motor.Set(0);
				m_motor4.Set(0);
				Wait(0.25);
			}
			if(m_stick.GetRawButton(1))
			{
				shooterEnabled = !shooterEnabled;
			}

			Wait(kUpdatePeriod); // Wait 5ms for the next update.
		}
	}
};

START_ROBOT_CLASS(Robot)
