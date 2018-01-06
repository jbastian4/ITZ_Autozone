#ifndef Auton
#define Auton

#include "unityDrive.c"
#include "/Includes/Variables.c"
#include "/Includes/Functions.c"

//#region blue
void bLGoalScore()
{
  liftRequest(liftPara);
  goalRequest(out);
  unityStraight(57,true);
  goalRequest(in,true);
  //barRequest(drop);
  //liftRequest(low);
  wait1Msec(500);
  wait1Msec(500);
  //liftRequest(liftPara);
  unityStraight(-58);
  wait1Msec(3000);
  unityTurn(1700,-1); //correcting for gyro inaccuracies, should be 1800
  wait1Msec(2000);
  unityStraight(23,true);
  goalRequest(out,true);
  wait1Msec(50);
  unityStraight(-20, true);
}
void bLPairWithE()
{
  liftRequest(liftPara);
  goalRequest(out);
  wait1Msec(500);
  unityStraight(57,true);
  goalRequest(in,true);
  //barRequest(drop);
  liftRequest(low);
  wait1Msec(500);
  wait1Msec(500);
  liftRequest(liftPara);
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
//#region right
void rLGoalScore()
{
  liftRequest(liftPara);
  goalRequest(out);
  unityStraight(57,true);
  goalRequest(in,true);
  ////barRequest(drop);
  liftRequest(low);
  wait1Msec(500);
  wait1Msec(500);
  liftRequest(liftPara);
  unityStraight(-58);
  wait1Msec(3000);
  unityTurn(1700,1); //correcting for gyro inaccuracies, should be 1800
  wait1Msec(2000);
  unityStraight(23,true);
  goalRequest(out,true);
  wait1Msec(50);
  unityStraight(-20, true);
}
void rLPairWithE()
{
  liftRequest(liftPara);
  goalRequest(out);
  wait1Msec(1000);
  unityStraight(55,true);
  goalRequest(in,true);
  //barRequest(drop);
  liftRequest(low);
  wait1Msec(1000);
  wait1Msec(500);
  liftRequest(liftPara);
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
  liftRequest(liftGoal);              //THIS WORKS, SO WE'RE SKIPPING TESTING IT FOR NOW
  goalRequest(out);           //go for first mgl
  unityStraight(10,true);
  goalRequest(out, true);
  unityStraight(30,true);
  goalRequest(in,true);
  unityStraight(-32,true);
  unityTurn(1300,-1);
  wait1Msec(1800);
  unityStraight(16,true);
  unityTurn(1400,-1);
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
  wait1Msec(1500);
}
//#endregion
#endif
