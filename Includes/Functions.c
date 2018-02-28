#ifndef Functions
#define Functions

#include "PID.c"
#include "unityDrive.c"

//#region misc Functions
long resetTimer() {
	return nPgmTime;
}

int time(long timer) {
	return nPgmTime - timer;
}
//#endregion

//#region drive functions
void setLMotors(int power)
{
	motor[lfDriveMot] = power;
	motor[lbDriveMot] = power;
	motor[lmDriveMot] = power;
}
void setRMotors(int power)
{
	motor[rfDriveMot] = power;
	motor[rbDriveMot] = power;
	motor[rmDriveMot] = power;

}
void setDriveMotors(int power)
{
	setLMotors(power);
	setRMotors(power);
}
void wellIReckon(int power, int time)
{
	enableEverything = false;
	gyroPID = false;
	setDriveMotors(power);
	wait1Msec(time);
	setDriveMotors(0);
	enableEverything = true;
}
//#endregion

//#region goal functions
void setGoalMotors(int power)
{
	motor[goalMot] = power;
}

void goalRequest(goalPos goal, bool nowWaitJustASecondThere = false, int modifier = 0, int timer = -1)
{
  goalRequestedValue = goalVal[goal] + modifier;
	timers[mgl] = resetTimer();

	if(nowWaitJustASecondThere)
		while(fabs(goalSensorCurrentValue - goalRequestedValue) > shortWaitGoalError
		      || (fabs(goalSensorCurrentValue - goalRequestedValue) > longWaitGoalError
					    && timer >= 0 && time(timers[goal]) >= timer)) EndTimeSlice();
}
//#endregion

//#region tasks

task userDrive()
{
	while(true)
	{
		LDriveRampRequest = vexRT[Ch3];
		RDriveRampRequest = vexRT[Ch2];
		LDriveRampSgn = sgn(LDriveRampRequest);
		RDriveRampSgn = sgn(RDriveRampRequest);

		if(fabs(LDriveRampRequest) > deadband)
		{
		 if(fabs(LDriveRampCurrent) < fabs(LDriveRampRequest) && fabs(LDriveRampCurrent) < 30)
		 LDriveRampCurrent += highRampSpeed*LDriveRampSgn;
		 else if(fabs(LDriveRampCurrent) < fabs(LDriveRampRequest))
		 LDriveRampCurrent += normalRampSpeed*LDriveRampSgn;
		 else if(fabs(LDriveRampCurrent) >= fabs(LDriveRampRequest))
		 LDriveRampCurrent = LDriveRampRequest*LDriveRampSgn;
		}

		if(fabs(RDriveRampRequest) > deadband)
	  {
	 	if(fabs(RDriveRampCurrent) < fabs(RDriveRampRequest) && fabs(RDriveRampCurrent) < 30)
	 	RDriveRampCurrent += highRampSpeed*RDriveRampSgn;
	 	else if(fabs(RDriveRampCurrent) < fabs(RDriveRampRequest))
	 	RDriveRampCurrent += normalRampSpeed*RDriveRampSgn;
	 	else if(fabs(RDriveRampCurrent) >= fabs(RDriveRampRequest))
	 	RDriveRampCurrent = RDriveRampRequest*RDriveRampSgn;
	  }

		else if(fabs(LDriveRampRequest) <= deadband)
		LDriveRampCurrent = 0;

		else if(fabs(RDriveRampRequest) <= deadband)
	  RDriveRampCurrent = 0;

	 	setLMotors(LDriveRampCurrent);
	 	setRMotors(RDriveRampCurrent);
	 	wait1Msec(rampInterval);
	}
}

//#endregion

#endif
