#ifndef PID
#define PID

//#region vars
static float  goal_Kp = 0.25;
static float  goalRequestedValue;
static float  goal_Kd = 0.2;

float goalD;
float goalP;
float lastgoalError;
float goalDF;

float  goalSensorCurrentValue;
float  goalError;
float  goalDrive;
static int shortWaitGoalError = 70;
static int longWaitGoalError = 175;
//#endregion

//#region goal
task goalController()
{

	while( true )
	{

			// Read the sensor value and scale
			goalSensorCurrentValue = SensorValue[ goalPot ];

			// calculate error
			goalError =  goalRequestedValue - goalSensorCurrentValue;

			// calculate drive
			goalP = (goal_Kp * goalError);

			goalD = goalError - lastgoalError;
			goalDF = (goal_Kd * goalD);

			goalDrive = goalP + goalDF;

			// limit drive
			if( goalDrive > 127 )
				goalDrive = 127;
			if( goalDrive < (-127) )
				goalDrive = (-127);

			// send to motor
			motor[ goalMot ] = goalDrive;
			lastgoalError = goalError;

			// Don't hog cpu
			wait1Msec( 25 );


	}
}
//#endregion

#endif
