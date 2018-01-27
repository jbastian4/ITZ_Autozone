#ifndef Functions
#define Functions

#include "PID.c"
#include "unityDrive.c"

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
//#endregion

//#region lift functions
void setLiftMotors(int power)
{
	motor[rLiftMot] = power;
	motor[mLiftMot] = power;
	motor[lLiftMot] = power;
}

void liftRequest(liftPos lift, bool nowWaitJustASecondThere = false, int modifier = 0)
{
  liftRequestedValue = liftVal[lift] + modifier;
	if(nowWaitJustASecondThere)
	while( liftSensorCurrentValue >= liftRequestedValue + waitLiftError
		|| liftSensorCurrentValue <= liftRequestedValue - waitLiftError){}
}
//#endregion

//#region bar functions
void setBarMotors(int power)
{
	motor[barMot] = power;
}
void barRequest(barSpeed speed)
{
  setBarMotors(barVal[speed]);
	wait1Msec(autoBarTime);
	setBarMotors(0);
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
}

void goalRequest(goalPos goal, bool nowWaitJustASecondThere = false, int modifier = 0)
{
	goalRequestedValue = goalVal[goal] + modifier;
	while( goalSensorCurrentValue >= goalRequestedValue + waitgoalError
		|| goalSensorCurrentValue <= goalRequestedValue - waitgoalError && nowWaitJustASecondThere){}
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

		if(vexRT[Ch3] <= 5 && vexRT[Ch3] >= -5)
			lPowerReq = vexRT[Ch3Xmtr2];
		else
			lPowerReq = vexRT[Ch3];

		if(vexRT[Ch2] <= 5 && vexRT[Ch2] >= -5)
			rPowerReq = vexRT[Ch2Xmtr2];
		else
			rPowerReq = vexRT[Ch2];

		//lPowerReq = vexRT[Ch3];
		//rPowerReq = vexRT[Ch2];

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
