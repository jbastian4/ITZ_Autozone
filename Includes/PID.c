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
static float  bar_Kp = 0.35;
static float  barRequestedValue;
static float  bar_Kd =1.2;

float barD;
float barP;
float lastbarError;
float barDF;

float  barSensorCurrentValue;
float  barError;
float  barDrive;

static int shortWaitBarError = 70;
static int longWaitBarError = 150;


task barController()
{

	while( true )
	{
		// Read the sensor value and scale
		barSensorCurrentValue = SensorValue[ barPot ];

		// calculate error
		barError =  barRequestedValue - barSensorCurrentValue;

		// calculate drive
		barP = (bar_Kp * barError);

		barD = barError - lastbarError;
		barDF = (bar_Kd * barD);

		barDrive = barP + barDF;

		// limit drive
		if( barDrive > 127 )
			barDrive = 127;
		if( barDrive < (-127) )
			barDrive = (-127);

		// send to motor

		motor[ chainMot ] = barDrive;
		lastbarError = barError;

		// Don't hog cpu
		wait1Msec( 25 );
	}
}


//#region goal
task goalController()
{

	while( true )
	{

			// Read the sensor value and scale
			goalSensorCurrentValue = SensorValue[ GoalPot ];

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
