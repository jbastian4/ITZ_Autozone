#pragma config(Sensor, in1,    barPot,         sensorPotentiometer)
#pragma config(Sensor, in2,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    otherGyro,      sensorGyro)
#pragma config(Sensor, in4,    GoalPot,        sensorPotentiometer)
#pragma config(Sensor, in5,    lPot,           sensorPotentiometer)
#pragma config(Sensor, in6,    rPot,           sensorPotentiometer)
#pragma config(Sensor, in7,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  lEnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rEnc,           sensorQuadEncoder)
#pragma config(Motor,  port1,           rfDriveMot,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rbDriveMot,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           lbDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rLiftMot,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           lfDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lGoalMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rGoalMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lBarMot,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rBarMot,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          lLiftMot,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
// test pull push github
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

//#region includes
#include "/Includes/Variables.c"
#include "/Includes/Functions.c"
#include "/Includes/PID.c"
#include "/Includes/auton.c"
#include "/Includes/unityDrive.c"
//#endregion
//#region PreAuton
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  bStopTasksBetweenModes = true;
  barRequestedValue = SensorValue(barPot);
  liftRequestedValue = SensorValue(liftPot);
  goalRequestedValue = SensorValue(GoalPot);

	// bDisplayCompetitionStatusOnLcd = false;
}
//#endregion

//#region Auton
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//driveEncoderPID = false;
	startTask(unityDrive);
	startTask(barController);
  startTask(liftController);
  //startTask(autoStack);
  startTask(goalController);
  manual = false;
  SensorValue[lEnc] = 0;
  SensorValue[rEnc] = 0;

  //fix the freaking gyro
  SensorType[gyro] = sensorNone;
  SensorType[otherGyro] = sensorNone;
  wait1Msec(300);
  SensorType[gyro] = sensorGyro;
  SensorType[otherGyro] = sensorGyro;
  wait1Msec(300);
  SensorScale[gyro] = 150; //Tunes the gyro value, tuned to 180 degrees (150)
  SensorScale[otherGyro] = 150;

  /*unityStraight(50);
  //wait1Msec(5000);
  unityTurn(1800,1);
  //setRMotors(90);
  wait1Msec(10000);//*/

	if (SensorValue[lPot]<1300)
	{
		if(SensorValue[rPot]<300)//Score a mobile goal w/ preload starting on the left
		{
			//pot 1-pot 1
			bLGoalScore();
		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800)//nothing
		{
			//pot 1-pot2
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //nothing
		{
			//pot 1-pot 3
		}
	if(SensorValue[rPot]>3700)//nothing
		{
			//pot 1-pot 4
			bLPairWithE();
		}
	}
	if (SensorValue[lPot]>2500)
	{
		if(SensorValue[rPot]<300) //Skills (or lack thereof)
		{
			//pot 3-pot1
			rLGoalScore();
			//skills();
		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800) //nothing
		{
				//pot 3-pot2
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //nothing
		{
			//pot 3-pot3
	}
	if(SensorValue[rPot]>3700) //nothing
		{
			//pot 3-pot4
			rLPairWithE();
		}
	}//*/
}
//#endregion

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  startTask(barController);
  startTask(liftController);
  //startTask(autoStack);
  startTask(liftBtnTracker);
  startTask(barBtnTracker);
  barRequest(back);
  //liftRequest(lowLift);
  startTask(userDrive);
  manual = false;
  liftRequestedValue=1100;
  while(true)
  {
  	/*datalogAddValueWithTimeStamp(0, SensorValue(gyro));
  	datalogAddValueWithTimeStamp(1, SensorValue(otherGyro));*/
  	//#region manual control
    if(vexRT[Btn8L] == 1 &&  vexRT[Btn8D] == 1 && enableBarPID == false) //turn manual on or off
      enableBarPID = true;
    else if(vexRT[Btn8L] == 1 && vexRT[Btn8D] == 1 && enableBarPID == true)
      enableBarPID = false;
    while(vexRT[Btn8L] == 1){}  //this will eventually get changed back to manual

    if(skillsFlip==1) //manual lift control
    {
      stopTask(liftController);
      if(vexRT[Btn5U] == 1)
			  setLiftMotors(127);
      else if(vexRT[Btn5D] == 1)
			  setLiftMotors(-127);
      else
        setLiftMotors(liftStillSpeed * lastLiftBtnPressed);

		}
    else
    {
      startTask(liftController);
    }
		//#endregion

		//#region misc control
   /* else //pid lift control
    {
      if(vexRT[Btn5U] == 1)
        stacking = true;
      if(vexRT[Btn5D] == 1)
        intStack = true;
      else if(vexRT[Btn7R] == 1)
        coneNum = 0;
      else if(vexRT[Btn7L] == 1)
      {
        coneNum++;
        while(vexRT[Btn7L] ==1) {}
      }
    }
		*/
    if (skillsFlip==1)
    {
    /*if(vexRT[Btn6U] == 1 && stacking == false && intStack == false) //intake control
      setIntakeMotors(intakeUp);
    else if(vexRT[Btn6D] == 1 && stacking == false && intStack == false)
      setIntakeMotors(intakeDown);
    else if(stacking == false && intStack == false)
      setIntakeMotors(intakeStill);
    */}
    /*if(vexRT[Btn8D]==1) //barbar control
      barRequest(drop, false);
    if(vexRT[Btn8R]==1)
      barRequest(low, false);
    if(vexRT[Btn8U]==1)
      barRequest(norm, false);
    if(vexRT[Btn8L]==1)
      barRequest(back, false);*/
      //manualBar(); //temporary bar code
      if (skillsFlip==1)
      {
    if(vexRT[Btn7U] == 1) //Mobile goal control
      setGoalMotors(127);
		else if(vexRT[Btn7D] == 1 /*&& SensorValue[GoalPot] >= 2875*/)
      setGoalMotors(-127);
    else if(vexRT[Btn7R] == 1)
    	setGoalMotors(-20);
    else
    	setGoalMotors(0);
      }
      if (skillsFlip==0)
      {
    if(vexRT[Btn6U] == 1) //Mobile goal control
      setGoalMotors(127);
		else if(vexRT[Btn6D] == 1 /*&& SensorValue[GoalPot] >= 2875*/)
      setGoalMotors(-127);
    else
    	setGoalMotors(0);
      }

      if(vexRT[Btn6U] == 1) //4 bar control
      setBarMotors(127);
			else if(vexRT[Btn6D] == 1)
      setBarMotors(-127);
    	else
    	setBarMotors(barStillSpeed * lastBarBtnPressed);

      if(vexRT[Btn7L]==0)
      {
        waitVar=1;
      }
      if (vexRT[Btn7L]==1 && skillsFlip==1 && waitVar==1)
	    {
		      skillsFlip=0;
          waitVar=0;
	    }
	    else if (vexRT[Btn7L]==1 && skillsFlip==0 && waitVar==1)
	    {
	       skillsFlip=1;
         waitVar=0;
	    }

	    /*if(vexRT[Btn7R] == 1)
	    	autoGoal();*/

    //#endregion
    }
}
