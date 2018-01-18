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
	motor[lBarMot] = power;
	motor[rBarMot] = power;
}
void barRequest(barSpeed speed)
{
  setBarMotors(barVal[speed]);
	wait1Msec(autoBarTime);
	setBarMotors(0);
}
//#endregion

//#region goal functions
void setGoalMotors(int power)
{
	motor[lGoalMot] = power;
	motor[rGoalMot] = power;
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
			if(vexRT[Btn6U] == 1||vexRT[Btn6UXmtr2] == 1)
				lastBarBtnPressed = 1;
			if(vexRT[Btn6D] == 1||vexRT[Btn6DXmtr2] == 1)
				lastBarBtnPressed = -1;
		EndTimeSlice();
	}
}

task userDrive()
{
	while(true)
	{
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
