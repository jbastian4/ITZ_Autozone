#ifndef Functions
#define Functions

#include "PID.c"
//#include "unityDrive.c"

//#region misc Functions
long timerReset() {
	return nPgmTime;
}

int time(long timer) {
	return nPgmTime - timer;
}

void resetTimer(timeType timer)
{
	timers[timer] = timerReset();
}
//#endregion

//#region goal functions
void setGoalMotors(int power)
{
	motor[rGoalMot] = power;
	motor[lGoalMot] = power;
}
void goalQueryHandler()
{
	resetTimer(cringeTime);
	for (int i = 0; i < 19; i++) {
		if(SensorValue[cancer]>3010)
			i = 0;
			wait1Msec(5);
	}
}
void goalRequest(goalPos goal, bool nowWaitJustASecondThere = false, int modifier = 0)
{
  goalRequestedValue = goalVal[goal] + modifier;

	if(nowWaitJustASecondThere)
		while(fabs(goalSensorCurrentValue - goalRequestedValue) > 60)
		{}
}

void goalManeuver(int distance,byte speed = 40)
{
	unityStraight(distance);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(speed * sgn(distance));
  setRDriveMotors(speed * sgn(distance));
  wait1Msec(250);
	switch (sgn(distance)) {
		case -1:
			goalRequest(out,true);
			break;
		case 1:
			goalRequest(in,true);
			break;
	}
  startTask(lEncController);
  startTask(rEncController);
  driveWaity(distance);
}

task goalDriveHandler()
{
	while(true) {
		if(fabs(goalSensorCurrentValue - goalRequestedValue) > 10
				|| (fabs(goalSensorCurrentValue - goalRequestedValue) > 10))
					goalfree=1;
		else
					goalfree=0;
  }
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
	motor[rDriveMot] = power;
}
void setDriveMotors(int power)
{
	setLMotors(power);
	setRMotors(power);
	setGoalMotors(power);
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
	motor[ltLiftMot] = power;
	motor[rtLiftMot] = power;
	motor[bLiftMot] = power;
}

void liftRequest(liftPos lift, bool nowWaitJustASecondThere = false, int modifier = 0)
{
  liftRequestedValue = liftVal[lift] + modifier;
	timers[lift] = timerReset();

	if(nowWaitJustASecondThere)
		while(fabs(liftSensorCurrentValue - liftRequestedValue) > 250)
		{}
}

//#endregion

//#region lift functions
/* setBarMotors(int power)
{
	motor[barMot] = power;
}
/*void barRequest(barSpeed speed)
{
  setBarMotors(barVal[speed]);
	wait1Msec(autoBarTime);
	setBarMotors(0);
}*/
void barRequest(barPos bar, bool nowWaitJustASecondThere = false, int modifier = 0)
{
	barRequestedValue = barVal[bar] + modifier;
	timers[BART] = timerReset();

	if(nowWaitJustASecondThere)
		while(fabs(barSensorCurrentValue - barRequestedValue) > 150)
		{}
}

//#endregion

//#region intake functions

void setIntakeMotors(int power)
{
	motor[intakeMot] = power;
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

		if(vexRT[Ch3] <= 15 && vexRT[Ch3] >= -15)
			lPowerReq = vexRT[Ch3Xmtr2];
		else
			lPowerReq = vexRT[Ch3];

		if(vexRT[Ch2] <= 15 && vexRT[Ch2] >= -15)
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

//#region end voids

 task killmeplz()
 {
	 wait1Msec(15000);
	 stopAllTasks();
	 allMotorsOff();
 }
task lockDrive()
{
	while(true)
	{
		setRMotors(-SensorValue[rEnc]*1.25);
		setLMotors(-SensorValue[lEnc]*1.25);
	}

}

//#endregion

#endif
