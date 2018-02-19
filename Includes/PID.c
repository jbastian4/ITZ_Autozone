#ifndef PID
#define PID

//#region vars
static float  lift_Kp = 0.5;
static float  liftRequestedValue;
static float  lift_Kd = 1.5;

float liftD;
float liftP;
float lastliftError;
float liftDF;

float  liftSensorCurrentValue;
float  liftError;
float  liftDrive;

static int shortWaitLiftError = 70;
static int longWaitLiftError = 175;

//////////////////////////////////////////////////////

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

bool goalPID;

//////////////////////////////////////////////////////

static float  bar_Kp = 0.35;
static float  barRequestedValue;
static float  bar_Kd =.6;

float barD;
float barP;
float lastbarError;
float barDF;

float  barSensorCurrentValue;
float  barError;
float  barDrive;

static int shortWaitBarError = 70;
static int longWaitBarError = 175;
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
		motor[ mLiftMot ] = liftDrive;
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

			motor[ goalMot ] = -goalDrive;
			lastgoalError = goalError;

			// Don't hog cpu
			wait1Msec( 25 );

		/*if(goalPID==false)
		{
			goalSensorCurrentValue = SensorValue[ GoalPot ];

			// calculate error
			goalError =  goalRequestedValue - goalSensorCurrentValue;
			if(goalSensorCurrentValue <= goalRequestedValue + waitgoalError
				&& goalSensorCurrentValue <= goalRequestedValue - waitgoalError)
				{
					motor[ goalMot ] =0;
				}
			else if (goalSensorCurrentValue > goalRequestedValue)
			 {
				 motor[ goalMot ] =127;
			 }
			 else if (goalSensorCurrentValue < goalRequestedValue)
 			 {
 				 motor[ goalMot ] =-127;
 			 }
		}*/
	}
}
//#endregion

//#region bar
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

		motor[ barMot ] = -barDrive;
		lastbarError = barError;

		// Don't hog cpu
		wait1Msec( 25 );
	}
}

//#endregion

#endif
