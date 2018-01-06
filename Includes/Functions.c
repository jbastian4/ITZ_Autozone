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
void driveStraight(float distance)
{
	distance = (distance * 360) / (PI * 4);
	SensorValue[lEnc] = 0;
	SensorValue[rEnc] = 0;
	while (SensorValue[lEnc] < distance )
	{
	 if ( SensorValue[lEnc] == SensorValue[rEnc])
	 {
		 setLMotors(127);
		 setRMotors(127);
	 }
	 else if ( SensorValue[lEnc] > SensorValue[rEnc])
	 {
		 setLMotors(100);
		 setRMotors(127);
	 }
	 else if ( SensorValue[lEnc] < SensorValue[rEnc])
	{
		setLMotors(127);
		setRMotors(100);
	}
	}
	while (SensorValue[lEnc] > distance )
	{
	 if ( SensorValue[lEnc] == SensorValue[rEnc])
	 {
		 setLMotors(-127);
		 setRMotors(-127);
	 }
	 else if ( SensorValue[lEnc] < SensorValue[rEnc])
	 {
		 setLMotors(-100);
		 setRMotors(-127);
	 }
	 else if ( SensorValue[lEnc] > SensorValue[rEnc])
	{
		setLMotors(-127);
		setRMotors(-100);
	}
	}
	setLMotors(0);
	setRMotors(0);
}
void dissentStraight(int distance)
{
	unityStraight(distance);
	int ticks = countsToInches(distance);
	while(abs(SensorValue[lEnc])<= ticks - 20)
	{}
}
//#endregion

//#region lift functions
void setLiftMotors(int power)
{
	motor[rLiftMot] = power;
	motor[lLiftMot] = power;
}

void liftRequest(int liftValue, bool nowWaitJustASecondThere = false)
{
  liftRequestedValue = liftValue;
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
void barRequest(barPos bar, bool nowWaitJustASecondThere = false)
{
  barRequestedValue = barVal[bar];
	if(nowWaitJustASecondThere){
	while( barSensorCurrentValue >= barRequestedValue + waitBarError
		|| barSensorCurrentValue <= barRequestedValue - waitBarError){}}
}
void manualBar()
{
	if(vexRT[Btn8D]==1) //4bar control
      setBarMotors(127);
  else if(vexRT[Btn8U]==1)
      setBarMotors(90);
  else
      setBarMotors(15);
}
//#endregion

//#region other functions
void setGoalMotors(int power)
{
	motor[lGoalMot] = power;
	motor[rGoalMot] = power;
}

void goalRequest(goalPos goal, bool nowWaitJustASecondThere = false)
{
	goalRequestedValue = goalVal[goal];
	while( goalSensorCurrentValue >= goalRequestedValue + waitgoalError
		|| goalSensorCurrentValue <= goalRequestedValue - waitgoalError && nowWaitJustASecondThere){}
}

void specificGoalRequest(int goal, bool nowWaitJustASecondThere = false)
{
	goalRequestedValue = goal;
	/*while( goalSensorCurrentValue >= goalRequestedValue + waitgoalError
		|| goalSensorCurrentValue <= goalRequestedValue - waitgoalError && nowWaitJustASecondThere){}*/
}

/*void intake()
{
	setIntakeMotors(intakeUp); //was intakeUp
	barRequest(low, false);
	wait1Msec(intakeTime);
	setIntakeMotors(intakeStill);
}*/
/*void stack()
{
	liftRequest(calcLiftTargetForCones() + lowLift);
	barRequest(drop, false);
	wait1Msec(timePerCone*coneNum);
	wait1Msec(timePerCone * 2);
	liftRequest(calcLiftTargetForCones() + stackDown); //WIGH
	wait1Msec(baseStackTime);
	setIntakeMotors(intakeDown);
	wait1Msec(intakeTime);
	barRequest(norm, false);
	wait1Msec(baseStackTime / 2);
	liftRequest(lowLift);
	coneNum++;
}*/

/*void autoGoal(int end = goalVal[out], int start = SensorValue(GoalPot)) {
	int direction = sgn(end-start);
	specificGoalRequest(start, true);
	for(int i = abs(start-end); i == abs(end-start); i++) {
		switch(direction) {
			case 1:
				specificGoalRequest(i);
			break;
			case -1:
				specificGoalRequest(start - i);
			break;
		}
		EndTimeSlice();
	}
}*/

void autoGoal(int end = goalVal[out], int start = SensorValue(GoalPot)) {
	startTask(goalController);
	specificGoalRequest(start);
	int autoGoalVal = start;
	while(SensorValue(GoalPot) <= end)
	{
		specificGoalRequest(autoGoalVal);
		autoGoalVal++;
		wait1Msec(3);
	}
	stopTask(goalController);
}
//#endregion

//#region tasks
/*task autoStack()
{
	while(true)
	{
		if(stacking)
		{
			stack();
			stacking = false;
		}
		else if(intStack)
		{
			intake();
			wait1Msec(intakeTime + 100);
			stack();
			stacking = false;
			intStack = false;
		}
		wait1Msec(25); //don't hog cpu
	}
}*/

task liftBtnTracker()
{
	while(true)
	{
			if(vexRT[Btn5U] == 1)
				lastLiftBtnPressed = 1;
			if(vexRT[Btn5D] == 1)
				lastLiftBtnPressed = -1;
		wait1Msec(25);
	}
}

task barBtnTracker()
{
	while(true)
	{
			if(vexRT[Btn6U] == 1)
				lastBarBtnPressed = 1;
			if(vexRT[Btn6D] == 1)
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
