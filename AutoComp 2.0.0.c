#pragma config(Sensor, in1,    gyro,           sensorGyro)
#pragma config(Sensor, in2,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, in3,    GoalPot,        sensorPotentiometer)
#pragma config(Sensor, in4,    barPot,         sensorPotentiometer)
#pragma config(Sensor, in5,    cancer,         sensorLineFollower)
#pragma config(Sensor, in6,    lPot,           sensorPotentiometer)
#pragma config(Sensor, in7,    rPot,           sensorPotentiometer)
#pragma config(Sensor, dgtl3,  rEnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  lEnc,           sensorQuadEncoder)
#pragma config(Motor,  port1,           rtLiftMot,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           intakeMot,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           barMot,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rDriveMot,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bLiftMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rGoalMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           lGoalMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ltLiftMot,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lbDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          lfDriveMot,    tmotorVex393_HBridge, openLoop)
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
#include "/Includes/auton.c"
 float debug;
 float cumbias;
 int barflip;
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
  barRequestedValue = SensorValue(barPot);
	/*SensorType[gyro] = sensorNone;
	for(int i = 0; i<2000; i++)
	{
		cumBias += SensorValue[gyro];
		wait1Msec(1);
	}

	debug = cumBias / 2000;*/
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
	//startTask (killmeplz);
	startTask(unityDrive);
  startTask(liftController);
  startTask(goalController);
  startTask(barController);
  startTask(goalDriveHandler);
  SensorValue[lEnc] = 0;
  SensorValue[rEnc] = 0;

  //fix the freaking gyro
	SensorScale[gyro] = 144; //Tunes the gyro value, can be tuned to 90 degrees (147) OR 180 degrees (160)
  /*wait1Msec(500);*/
  SensorBias[gyro] = 1870;
  //#endregion

  //#region left routines
	if(SensorValue[lPot]<1300)
	{
		if(SensorValue[rPot]<300) //Mobile goal in 20 and 2 cones
		{
		  //pot 1-pot 1
		    l20PtZone();
		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800) //Goal in 10 and 3 cones
		{
		  //pot 1-pot2
		    l10PointZone();
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //Goal in 5, 1 cone, setup
		{
		  //pot 1-pot 3
		    l5GoalScore();

		}
	  if(SensorValue[rPot]>3700) //3-5 cones
		{
		  //pot 1-pot 4
		    lConeScore();
		}
	}
  //#endregion

  //#region middle routines
  if(SensorValue[lPot] >= 1300 && SensorValue[lPot] <= 2500)
  {
    if(SensorValue[rPot]<300) //Goal in 10, 1 cone, defensive
		{
		  //pot 2-pot 1
        lDefensive();
		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800) //nothing
		{
		  //pot 2-pot2
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //nothing
		{
		  //pot 2-pot 3

		}
	  if(SensorValue[rPot]>3700) //Goal in 10, 1 cone, defensive
		{
		  //pot 2-pot 4
		    rDefensive();
		}
  }
  //#endregion

  //#region right routines
	if(SensorValue[lPot]>2500)
	{
		if(SensorValue[rPot]<300) //Mobile goal in 20 and 2 cones
		{
		  //pot 3-pot1
		    r20PtZone();
		}
		if(SensorValue[rPot]>300 && SensorValue[rPot]<1800) //Goal in 10 and 3 cones
		{
		  //pot 3-pot2
        r10PointZone();
		}
		if(SensorValue[rPot]>1800 && SensorValue[rPot]<3700) //Goal in 5, 1 cone, setup
		{
		  //pot 3-pot3
		    r5GoalScore();
	  }
	  if(SensorValue[rPot]>3700) //3-5 cones
		{
		  //pot 3-pot4
		    rConeScore();
		}
	}
  //#endregion
}
//#endregion

//#region user control-------------*/
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
  //startTask(barController);
  //startTask(barBtnTracker);
  startTask(userDrive);

  //barRequest(drop);
  while(true)
  {

		//#region no skill flip
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
      	{
					barflip=0;
     		}
				else if(vexRT[Btn8R] == 1)
				{
					barflip=1;
				}

				if(barflip==1)
				{
					if (SensorValue[barPot]>400 )
					{
						motor[ barMot ] = -127;
					}
					else
					{
						motor[ barMot ] = -15;
					}
				}
				else if(barflip==0)
				{
					      		if (SensorValue[barPot]< 1885)
					{
						motor[ barMot ] = 127;
					}
					else
					{
						motor[ barMot ] = 15;
					}

				}
   	    /*else if(vexRT[Btn6UXmtr2] == 1)
   	    //setBarMotors(127);
   	    barRequest(drop,false);
  	    else if(vexRT[Btn6DXmtr2] == 1)
  	    	//setBarMotors(-127);
  	    	barRequest(down);
     	 	/*else
     	 		setBarMotors(lastBarBtnPressed == 1 ? barStillUp : barStillDown);*/
      //</editor-fold>*/

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
      else {
      	motor[lGoalMot] = lPowerReq;
        motor[rGoalMot] = rPowerReq;
      }
      //</editor-fold>

    //#endregion

    //#region flip toggle
    if(vexRT[Btn7L]==0&&vexRT[Btn7LXmtr2]==0) //If the button is pressed...
    {
      waitVar=1;
    }
    if (vexRT[Btn7L] == 1 && skillsFlip==true && waitVar == 1) //Disable skills flip
    {
    	startTask(userDrive);
       skillsFlip = false;
       waitVar=0;
       stopTask (lockDrive);
    }
    	else if (vexRT[Btn7L]==1 && skillsFlip == false && waitVar == 1) //Enable skills flip
   	 {
   	   stopTask(userDrive);
	   	SensorValue[lEnc] = 0;
			SensorValue[rEnc] = 0;
       skillsFlip = true;
       waitVar=0;
       startTask (lockDrive);
   	 }
   	   else if (vexRT[Btn7LXmtr2] == 1 && skillsFlip==true && waitVar == 1) //Disable skills flip
    {
    	startTask(userDrive);
       skillsFlip = false;
       waitVar=0;
       stopTask (lockDrive);
    }
    	else if (vexRT[Btn7LXmtr2]==1 && skillsFlip == false && waitVar == 1) //Enable skills flip
   	 {
   	   stopTask(userDrive);
	   	SensorValue[lEnc] = 0;
			SensorValue[rEnc] = 0;
       skillsFlip = true;
       waitVar=0;
       startTask (lockDrive);
   	 }

    /*if (vexRT[Btn7LXmtr2] == 1 && skillsFlip && waitVar == 1) //Disable skills flip
    {
      skillsFlip = false;//golinetrackyourself
      waitVar=0;
      lockDrive(false);
    }
    else if (vexRT[Btn7LXmtr2]==1 && !skillsFlip && waitVar == 1) //Enable skills flip
    {
       skillsFlip = true;
       waitVar=0;
       lockDrive();
    }*/

    //#endregion
    }

}
//#endregion
