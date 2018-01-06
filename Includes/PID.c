#ifndef PID
#define PID

//#region vars
static float  bar_Kp = 0.14;
static float  barRequestedValue;
static float  bar_Kd = 0.4;
static float  bar_Ki = 0.001;

float barI = 0;
float barD;
float barP;
float lastbarError;
float barDF;

float  barSensorCurrentValue;
float  barError;
float  barDrive;

static int waitBarError = 20;

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

//#region bar
task barController()
{
	while( true )
	{
		while(enableBarPID)
		{
			// Read the sensor value and scale
			barSensorCurrentValue = SensorValue[ barPot ];

			// calculate error
			barError =  barRequestedValue - barSensorCurrentValue;

			// calculate drive
			barP = (bar_Kp * barError);

			barD = barError - lastbarError;
			barDF = (bar_Kd * barD);

			//barI += barError * bar_Ki;

			barDrive = barP + barDF + barI;

			// limit drive
			if( barDrive > 127 )
				barDrive = 127;
			if( barDrive < (-127) )
				barDrive = (-127);

			// send to motor

			motor[lBarMot] = barDrive;
			motor[rBarMot] = barDrive;



			lastbarError = barError;

			// Don't hog cpu
			wait1Msec( 25 );
		}
		while(enableBarPID==false)
		{
			motor[lBarMot] = 0;
			motor[rBarMot] = 0;
		}

	}
}
//#endregion



//#region lift
task liftController()
{

	while( true )
	{
		while(manual == false)
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
		}
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
		while(manual == false)
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
		}
		// Don't hog cpu
		wait1Msec( 25 );
	}
}
//#endregion

#endif
