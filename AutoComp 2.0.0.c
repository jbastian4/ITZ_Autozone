#pragma config(Sensor, in2,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, in4,    GoalPot,        sensorPotentiometer)
#pragma config(Sensor, in5,    lPot,           sensorPotentiometer)
#pragma config(Sensor, in6,    rPot,           sensorPotentiometer)
#pragma config(Sensor, in7,    barPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl1,  lEnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rEnc,           sensorQuadEncoder)
#pragma config(Motor,  port1,           rfDriveMot,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rbDriveMot,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           lbDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rLiftMot,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           lfDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           mLiftMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           goalMot,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           intakeMot,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           barMot,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          lLiftMot,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
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
  //#region initialization
	startTask(unityDrive);
  startTask(liftController);
  startTask(goalController);
  startTask(barController);
  SensorValue[lEnc] = 0;
  SensorValue[rEnc] = 0;

  //fix the freaking gyro
  SensorType[gyro] = sensorNone;
  wait1Msec(500);
  SensorType[gyro] = sensorGyro;
  wait1Msec(500);
  SensorScale[gyro] = 215; //Tunes the gyro value, can be tuned to 90 degrees (215) OR 180 degrees (160)
  //#endregion

  //#region left routines
	if (SensorValue[lPot]<1300)
	{
		if(SensorValue[rPot]<300)//Mobile goal in 20 and preload
		{
			//pot 1-pot 1
			lGoalScore();

		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800)//nothing
		{
			//pot 1-pot2
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //nothing
		{
			//pot 1-pot 3
		}
	if(SensorValue[rPot]>3700)//Mobile goal in 10 and preload
		{
			//pot 1-pot 4
			lPairWithE();
		}
	}
  //#endregion

  //#region right routines
	if (SensorValue[lPot]>2500)
	{
		if(SensorValue[rPot]<300) //Mobile goal in 20 and preload
		{
			//pot 3-pot1
			rGoalScore();
		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800) //Skills (or lack thereof)
		{
				//pot 3-pot2
        skills();
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //nothing
		{
			//pot 3-pot3
	}
	if(SensorValue[rPot]>3700) //Mobile goal in 10 and preload
		{
			//pot 3-pot4
			rPairWithE();
		}
	}
  //#endregion
}
//#endregion

//#region user control
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
  startTask(liftController);
  startTask(liftBtnTracker);
  startTask(barBtnTracker);
  startTask(userDrive);
  startTask(barController);
  barRequest(drop);
  while(true)
  {
  	//#region skill flip
    if(skillsFlip)
    {
      //<editor-fold lift
      startTask(liftController);
      liftRequest(para);
      //</editor-fold>

      //<editor-fold goal
      if(vexRT[Btn6U] == 1)
        setGoalMotors(127);
  		else if(vexRT[Btn6D] == 1)
        setGoalMotors(-127);
      else
      	setGoalMotors(0);
      //</editor-fold>

      //<editor-fold bar
      setBarMotors(barStillUp);
      //</editor-fold>
		}
		//#endregion

		//#region no skill flip
    else
    {
      //<editor-fold lift
      stopTask(liftController);
      if(vexRT[Btn5U] == 1)
			  setLiftMotors(127);
      else if(vexRT[Btn5D] == 1)
			  setLiftMotors(-127);
      else if(vexRT[Btn5UXmtr2] == 1)
          setLiftMotors(127);
      else if(vexRT[Btn5DXmtr2] == 1)
          setLiftMotors(-127);
      else
        setLiftMotors(liftStillSpeed * lastLiftBtnPressed);
      //</editor-fold>



      //<editor-fold intake
      if(vexRT[Btn6U] == 1)
      setIntakeMotors(127);
			else if(vexRT[Btn6D] == 1)
      setIntakeMotors(-127);
      else if(vexRT[Btn8RXmtr2] == 1)
      setIntakeMotors(127);
      else if(vexRT[Btn8DXmtr2] == 1)
      setIntakeMotors(-127);
    	else
      setIntakeMotors(intakeStill);
      //</editor-fold>

      //<editor-fold bar
      	if(vexRT[Btn8D] == 1)
   	    //setBarMotors(127);
     		barRequest(drop,false);
				else if(vexRT[Btn8R] == 1)
   	    //setBarMotors(-127);
				barRequest(down);
   	    else if(vexRT[Btn6UXmtr2] == 1)
   	    {}
  	    //setBarMotors(127);
  	    else if(vexRT[Btn6DXmtr2] == 1)
  	    {}
  	    //setBarMotors(-127);
     	 //	else
     	 	//setBarMotors(lastBarBtnPressed == 1 ? barStillUp : barStillDown);
      //</editor-fold>
      //<editor-fold goal
      if(vexRT[Btn7U] == 1)
        setGoalMotors(127);
    	else if(vexRT[Btn7D] == 1)
        setGoalMotors(-127);
      else if(vexRT[Btn7R] == 1)
      	setGoalMotors(-20);
     	else if(vexRT[Btn7L] == 1)
     		setGoalMotors(35);
      else if(vexRT[Btn7UXmtr2] == 1)
        setGoalMotors(127);
      else if(vexRT[Btn7DXmtr2] == 1)
        setGoalMotors(-127);
      else if(vexRT[Btn7RXmtr2] == 1)
      	setGoalMotors(-20);
      else if(vexRT[Btn7LXmtr2] == 1)
      	setGoalMotors(35);
      else
      	setGoalMotors(0);
      //</editor-fold>





  }
    //#endregion

    //#region flip toggle
      if(vexRT[Btn8L]==0) //If the button is pressed...
      {
        waitVar=1;
      }
      if (vexRT[Btn8L] == 1 && skillsFlip && waitVar == 1) //Disable skills flip
	    {
		     skillsFlip = false;
        waitVar=0;
	    }
	    else if (vexRT[Btn8L]==1 && !skillsFlip && waitVar == 1) //Enable skills flip
	    {
	       skillsFlip = true;
         waitVar=0;
	    }
    //#endregion
    }
}
//#endregion
