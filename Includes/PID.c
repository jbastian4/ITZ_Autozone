#ifndef PID
#define PID

//#region vars
static float  lift_Kp = 0.3;
static float  liftRequestedValue;
static float  lift_Kd = 1.5;

float liftD;
float liftP;
float lastliftError;
float liftDF;

float  liftSensorCurrentValue;
float  liftError;
float  liftDrive;

static int waitLiftError = 20;

static float  goal_Kp = 0.3;
static float  goalRequestedValue;
static float  goal_Kd = 0.1;

float goalD;
float goalP;
float lastgoalError;
float goalDF;

float  goalSensorCurrentValue;
float  goalError;
float  goalDrive;

static int waitgoalError = 20;
//#endregion


//#region lift
task liftController()
{

	while( true )
	{
		// Read the sensor value and scale
		liftSensorCurrentValue = SensorValue[ liftPot ];

		// calculate error
		liftError =  liftRequestedValue - liftSensorCurrentValue;

		// calculate drive
		liftP = (lift_Kp * liftError);

		liftD = liftError - lastliftError;
		liftDF = (lift_Kd * liftD);

		liftDrive = liftP + liftDF;

		// limit drive
		if( liftDrive > 127 )
			liftDrive = 127;
		if( liftDrive < (-127) )
			liftDrive = (-127);

		// send to motor

		motor[ lLiftMot ] = liftDrive;
		motor[ rLiftMot ] = liftDrive;
		lastliftError = liftError;

		// Don't hog cpu
		wait1Msec( 25 );
	}
}

//#endregion

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

		motor[ rGoalMot ] = goalDrive;
		motor[ lGoalMot ] = goalDrive;
		lastgoalError = goalError;

		// Don't hog cpu
		wait1Msec( 25 );
	}
}
//#endregion

#endif