#pragma config(Sensor, in3,    gyro,           sensorGyro)
#pragma config(Sensor, in4,    GoalPot,        sensorPotentiometer)
#pragma config(Sensor, in5,    lPot,           sensorPotentiometer)
#pragma config(Sensor, dgtl1,  lEnc,           sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rEnc,           sensorQuadEncoder)
#pragma config(Motor,  port1,           rbDriveMot,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rmDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rfDriveMot,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rollerMot,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           chainMot,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           goalMot,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           lfDriveMot,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lmDriveMot,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          lbDriveMot,    tmotorVex393_HBridge, openLoop)
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
//#endregion

//#region PreAuton
void pre_auton()
{
  bStopTasksBetweenModes = true;
}
//#endregion

//#region Auton
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  //#region initialization
	startTask(unityDrive);
  startTask(goalController);

  //fix the freaking gyro
  SensorType[gyro] = sensorNone;
  wait1Msec(60);
  SensorType[gyro] = sensorGyro;
  wait1Msec(60);
  SensorScale[gyro] = 147; //Tunes the gyro value, can be tuned to 90 degrees (147) OR 180 degrees (160)
  wait1Msec(60);
  //#endregion

  //#region auton routines
	if(SensorValue[lPot]<1300)
    testAuton();
	if(SensorValue[lPot]>2500)
    skills();
  //#endregion
}
//#endregion

//#region user control
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  //startTask(userDrive);
  while(true)
  {
  	setLMotors(vexRT[Ch3]);
  	setRMotors(vexRT[Ch2]);
    if(vexRT[Btn6U] == 1){
      setGoalMotors(127);
    	goalstill=15;}
    else if(vexRT[Btn6D] == 1){
      setGoalMotors(-127);
    	goalstill=-15;}
    else
      setGoalMotors(goalstill);
    if(vexRT[Btn5U] == 1){
    	motor[chainMot]=127;
    }
    else if(vexRT[Btn5D] == 1){
    	motor[chainMot]=-127;
    }
    else
    {
    	motor[chainMot]=0;
    }
        if(vexRT[Btn8U] == 1){
    	motor[rollerMot]=127;
    }
    else if(vexRT[Btn8D] == 1){
    	motor[rollerMot]=-127;
    }
    else
    {
    	motor[rollerMot]=20;
    }
  }
}
//#endregion
