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
}
void setRMotors(int power)
{
	motor[rfDriveMot] = power;
	motor[rbDriveMot] = power;
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

//#region lift functions
void setLiftMotors(int power)
{
	motor[rLiftMot] = power;
	//motor[mLiftMot] = power;
	motor[lLiftMot] = power;
}

void liftRequest(liftPos lift, bool nowWaitJustASecondThere = false, int modifier = 0, int timer = -1)
{
  liftRequestedValue = liftVal[lift] + modifier;
	timers[lift] = resetTimer();

	if(nowWaitJustASecondThere)
		while(fabs(liftSensorCurrentValue - liftRequestedValue) > shortWaitLiftError
		      || (abs(liftSensorCurrentValue - liftRequestedValue) > longWaitLiftError
					    && timer >= 0 && time(timers[lift]) >= timer)) EndTimeSlice();
}

//#endregion

//#region lift functions
void setBarMotors(int power)
{
	motor[barMot] = power;
}
/*void barRequest(barSpeed speed)
{
  setBarMotors(barVal[speed]);
	wait1Msec(autoBarTime);
	setBarMotors(0);
}*/
void barRequest(barPos bar, bool nowWaitJustASecondThere = false, int modifier = 0, int timer = -1)
{
  barRequestedValue = barVal[bar] + modifier;
	timers[BART] = resetTimer();

	if(nowWaitJustASecondThere)
		while(fabs(barSensorCurrentValue - barRequestedValue) > shortWaitBarError
		      || (abs(barSensorCurrentValue - barRequestedValue) > longWaitBarError
					    && timer >= 0 && time(timers[bar]) >= timer)) EndTimeSlice();
}

//#endregion

//#region intake functions

void setIntakeMotors(int power)
{
	motor[intakeMot] = power;
}

//#endregion

//#region goal functions
void setGoalMotors(int power)
{
	motor[goalMot] = power;
	motor[mLiftMot] = power;
}

void goalRequest(goalPos goal, bool nowWaitJustASecondThere = false, int modifier = 0, int timer = -1)
{
  goalRequestedValue = goalVal[goal] + modifier;
	timers[mgl] = resetTimer();

	if(nowWaitJustASecondThere)
		while(fabs(goalSensorCurrentValue - goalRequestedValue) > shortWaitGoalError
		      || (abs(goalSensorCurrentValue - goalRequestedValue) > longWaitGoalError
					    && timer >= 0 && time(timers[goal]) >= timer)) EndTimeSlice();
}
//#endregion

//#region tasks
task liftBtnTracker()
{
	while(true)
	{
			if(vexRT[Btn5U] == 1||vexRT[Btn5UXmtr2] == 1)
				lastLiftBtnPressed = 1;
			if(vexRT[Btn5D] == 1 ||vexRT[Btn5DXmtr2] == 1 )
				lastLiftBtnPressed = -1;
		wait1Msec(25);
	}
}

task barBtnTracker()
{
	while(true)
	{
			if(vexRT[Btn8D] == 1||vexRT[Btn6UXmtr2] == 1)
				lastBarBtnPressed = 1;
			if(vexRT[Btn8R] == 1||vexRT[Btn6DXmtr2] == 1)
				lastBarBtnPressed = -1;
		EndTimeSlice();
	}
}

int AAmainL;
int AApartL;
int AAmainR;
int AApartR;

task userDrive()
{
	while(true)
	{
		AAmainL = vexRT[Ch3];
		AApartL = vexRT[Ch3Xmtr2];
		AAmainR = vexRT[Ch2];
		AApartR = vexRT[Ch2Xmtr2];

		/*if(vexRT[Ch3] <= 5 && vexRT[Ch3] >= -5)
			lPowerReq = vexRT[Ch3Xmtr2];
		else
			lPowerReq = vexRT[Ch3];

		if(vexRT[Ch2] <= 5 && vexRT[Ch2] >= -5)
			rPowerReq = vexRT[Ch2Xmtr2];
		else
			rPowerReq = vexRT[Ch2];*/

		lPowerReq = vexRT[Ch3];
		rPowerReq = vexRT[Ch2];

		if(lPower >= 30)
		{
			if(lPowerReq > lPower)
			{
				lPower += normRampSpeed;
			}
			else if(lPowerReq < lPower)
			{
				lPower = lPowerReq;
			}
		}
		else if(lPower <= -30)
		{
			if(lPowerReq < lPower)
			{
				lPower -= normRampSpeed;
			}
			else if(lPowerReq > lPower)
			{
				lPower = lPowerReq;
			}
		}
		else if((lPower > -30 && lPower < -10) || (lPower < 30 && lPower > 10))
		{
			if(lPowerReq > lPower)
			{
				lPower += hiRampSpeed;
			}
			if(lPowerReq < lPower)
			{
				lPower = lPowerReq;
			}
		}
		else
		{
			if(lPowerReq > lPower)
			{
				lPower += normRampSpeed;
			}
			if(lPowerReq < lPower)
			{
				lPower = lPowerReq;
			}
		}

		if(rPower >= 30)
		{
			if(rPowerReq > rPower)
			{
				rPower += normRampSpeed;
			}
			else if(rPowerReq < rPower)
			{
			rPower = rPowerReq;
			}
		}
		else if(rPower <= -30)
		{
			if(rPowerReq < rPower)
			{
				rPower -= normRampSpeed;
			}
			else if(rPowerReq > rPower)
			{
				rPower = rPowerReq;
			}
		}
		else if((rPower > -30 && rPower < -10) || (rPower < 30 && rPower > 10))
		{
			if(rPowerReq > rPower)
			{
				rPower += hiRampSpeed;
			}
			if(rPowerReq < rPower)
			{
				rPower = rPowerReq;
			}
		}
		else
		{
			if(rPowerReq > rPower)
			{
				rPower += normRampSpeed;
			}
			if(rPowerReq < rPower)
			{
				rPower = rPowerReq;
			}
		}

		if(abs(lPowerReq) < nullVal)
		{
			lPower = 0;
		}

		if(abs(rPowerReq) < nullVal)
		{
			rPower = 0;
		}

		setLMotors(lPower);
		setRMotors(rPower);

		wait1Msec(rampTime);
	}
}
//#endregion

#endif
