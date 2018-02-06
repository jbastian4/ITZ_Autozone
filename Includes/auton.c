#ifndef Auton
#define Auton

#include "unityDrive.c"
#include "/Includes/Variables.c"
#include "/Includes/Functions.c"

//#region right
void rGoalScore()
{
  setIntakeMotors(intakeStill);
  setBarMotors(20);
  liftRequest(para);
  setGoalMotors(-127);
  unityStraight(57);
  wait1Msec(1500);
  setGoalMotors(-35);
  wait1Msec(1000);
  setGoalMotors(100);
  wait1Msec(1500);
  setGoalMotors(35);
  wait1Msec(500);
  setGoalMotors(0);
  liftRequest(low);
  wait1Msec(500);
  setIntakeMotors(-127);
  wait1Msec(1500);
  setIntakeMotors(0);


  /*liftRequest(para);
  goalRequest(out);
  unityStraight(57,true);
  goalRequest(in,true);
  //barRequest(drop);
  //liftRequest(low);
  wait1Msec(500);
  wait1Msec(500);
  //liftRequest(para);
  unityStraight(-58);
  wait1Msec(3000);
  unityTurn(1700,-1); //correcting for gyro inaccuracies, should be 1800
  wait1Msec(2000);
  unityStraight(23,true);
  goalRequest(out,true);
  wait1Msec(50);
  unityStraight(-20, true);*/
}
void rPairWithE()
{
  liftRequest(para);
  goalRequest(out);
  wait1Msec(500);
  unityStraight(57,true);
  goalRequest(in,true);
  //barRequest(drop);
  liftRequest(low);
  wait1Msec(500);
  wait1Msec(500);
  liftRequest(para);
  unityStraight(-44,true);
  wait1Msec(2000);
  unityTurn(1200,1); //correcting for gyro inaccuracies, should be 1800
  wait1Msec(2000);
  unityStraight(10);
  goalRequest(out,true);
  wait1Msec(50);
  unityStraight(-10, true);
  goalRequest(in);
  unityTurn(2450, -1);
  wait1Msec(2000);
  unityStraight(70,true);
}
//#endregion
//#region left
void lGoalScore()
{
  setBarMotors(20);
  liftRequest(para);
  goalRequest(out);
  wait1Msec(750);
  stopTask(goalController);
  setGoalMotors(0);
  unityStraight(57,true);
  //goalRequest(in/*,true*/);
  //stopTask(goalController);
  setGoalMotors(-127);
  //goalRequestedValue = -250;
  wait1Msec(1500);
  //liftRequest(low);
  liftRequestedValue = 750;
  wait1Msec(500);
  setIntakeMotors(-127);
  liftRequestedValue = 1120;
  wait1Msec(1500);
  setIntakeMotors(0);
  //barRequest(drop);
  /*wait1Msec(2000);
  stopTask(liftController);
  setLiftMotors(-127);
  wait1Msec(500);
  setLiftMotors(-20);
  wait1Msec(2000);
  setBarMotors(-127)
  wait1Msec(500);
  setBarMotors(0);
  wait1Msec(500);
  //startTask(liftController);
  liftRequest(para);*/
  /*liftRequest(low);
  wait1Msec(1000);
  stopTask(liftController);
  setLiftMotors(-30);
  barRequest(down);
  wait1Msec(1000);
  setLiftMotors(0);
  /*wait1Msec(500000);
  unityStraight(-50);
  wait1Msec(3000);
  unityTurn(2300,1); //correcting for gyro inaccuracies, should be 1800
  wait1Msec(2000);
  unityStraight(23,true);
  goalRequest(out,true);
  wait1Msec(50);
  unityStraight(-20, true);*/
}
void lPairWithE()
{
  liftRequest(para);
  goalRequest(out);
  wait1Msec(1000);
  unityStraight(55,true);
  goalRequest(in,true);
  //barRequest(drop);
  liftRequest(low);
  wait1Msec(1000);
  wait1Msec(500);
  liftRequest(para);
  unityStraight(-42,true);
  wait1Msec(2000);
  unityTurn(1200,1); //correcting for gyro inaccuracies, should be 1800
  wait1Msec(2000);
  unityStraight(10);
  goalRequest(out,true);
  wait1Msec(50);
  unityStraight(-10, true);
  goalRequest(in);
  unityTurn(2450, -1);
  wait1Msec(2000);
  unityStraight(70,true);
}
void testAuton()
{
  unityStraight(8,true);
}
//#endregion
//#region skills
void skills()
{
  setIntakeMotors(15);
  liftRequest(goal);
  goalRequest(out);           //go for first mgl
  unityStraight(25,true);
  goalRequest(out,true);
  unityStraight(8,true);
  barRequestedValue=drop;
  goalRequest(in,true);
  unityStraight(-30);
  liftRequest(low,true);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(0);
  wait1Msec(1000);
  unityTurn(980,1);
  wait1Msec(1600);
  unityStraight(15,true);
  unityTurn(980,1);
  wait1Msec(1600);
  unityStraight(16,true);
  unityStraight(8);
  goalRequest(out);
  wait1Msec(750);
  unityStraight(-20,true);
/*goalRequest(in);
  unityTurn(1300,-1);
  wait1Msec(1800);
  unityStraight(15,true);
  unityTurn(1400,-1);
  wait1Msec(1800);
  unityStraight(-15);
  wait1Msec(500);
  driveEncoderPID = false;
  wait1Msec(1000);
  goalRequest(out);    //Go for second mgl
  unityStraight(60,true);
  goalRequest(in,true);
  unityStraight(30);
  unityTurn(1300,-1);
  wait1Msec(1800);
  unityStraight(16,true);
  unityTurn(1500,1);
  wait1Msec(1800);
  unityStraight(20,true);
  goalRequest(out,true);
  unityStraight(-18,true);
  goalRequest(in);
  unityTurn(1300,-1);
  wait1Msec(1800);
  unityStraight(15,true);
  unityTurn(1400,-1);
  wait1Msec(1800);
  unityStraight(-15);
  wait1Msec(1500);*/
}
//#endregion
#endif
