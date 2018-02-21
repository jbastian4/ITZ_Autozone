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

void r5PointZone()
{
  setIntakeMotors(15);
  liftRequest(goal);
  goalRequest(out);           //go for first mgl
  unityStraight(40,true);
  goalRequest(out,true);
  unityStraight(15,true);
  barRequestedValue=drop;
  goalRequest(in,true);
  unityStraight(-42);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(-127);
  wait1Msec(200);
  drivewaity(-42);
  liftRequest(goal);
  setIntakeMotors(0);
  wait1Msec(1000);
  unityTurn(1400,-1);
  wait1Msec(1600);
  goalRequest(out,true);
  unityStraight(-48,true);
  unityTurn(1090,-1);
  wait1Msec(1500);
  unityStraight(15,true);
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

void lConeScore()
{
  setIntakeMotors(15);
  liftRequest(goal);
  goalRequest(out);           //go for first mgl
  unityStraight(35,true);
  goalRequest(out,true);
  unityStraight(15,true);
  barRequestedValue=drop;
  goalRequest(in,true);
  unityStraight(7);
  liftRequest(low,true);
  setIntakeMotors(-127);  //drop fisrt cone
  wait1Msec(500);
  liftRequest(goal,true);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,false,50);
  wait1Msec(750);
  setIntakeMotors(30);
  liftRequest(goal);
  barRequest(drop,true);
  liftRequest(low,true,80); // drop second cone
  setIntakeMotors(-127);
  wait1Msec(300);
  unityStraight(8);
  liftRequest(para,true);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(500);
  setIntakeMotors(30);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(500);
  liftRequest(para);
  unityStraight(4);
  liftRequest(para,true);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true,150);
  wait1Msec(500);
  unityStraight(-3,true);
  setIntakeMotors(30);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(500);
  liftRequest(para);
}

void l5PointZone()
{
  setIntakeMotors(15);
  liftRequest(goal);
  goalRequest(out);           //go for first mgl
  unityStraight(35,true);
  goalRequest(out,true);
  unityStraight(15,true);
  barRequestedValue=drop;
  goalRequest(in,true);
  unityStraight(-37);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(-127);
  wait1Msec(200);
  drivewaity(-37);
  liftRequest(goal);
  setIntakeMotors(0);
  wait1Msec(1000);
  unityTurn(1400,1);
  wait1Msec(1600);
  goalRequest(out,true);
  unityStraight(-48,true);
  unityTurn(950,1);
  wait1Msec(1500);
  unityStraight(15,true);
}

void testAuton()
{

}
//#endregion

//#region skills
void skills()
{

  setIntakeMotors(15);  //go for first mgl
  liftRequest(goal);
  goalRequest(out);
  unityStraight(51,true);
  goalRequest(out,true);
  barRequestedValue=drop;
  goalRequest(in);
  wait1Msec(250);
  unityStraight(-47);     //drive back
  goalRequest(in,true);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(0);
  drivewaity(-47);
  unityTurn(450,-1);
  wait1Msec(840);
  unityStraight(-22,true);
  unityTurn(900,-1);
  wait1Msec(1000);
  wellIReckon(127,800); //score first goal in 20
  wait1Msec(200);
  wellIReckon(-50,150);
  goalRequest(out,true,300);
  wellIReckon(127,750);
  wellIReckon(75,250);
  unityStraight(-20,true); //go for second goal
  wait1Msec(1000);
  unityTurn(870,-1);
  wait1Msec(1000);
  unityStraight(17,true);
  unityTurn(870,-1);
  wait1Msec(900);
  wellIReckon(-75,750);
  goalRequest(out,true);
  wellIReckon(50,150);
  unityStraight(35,true);
  goalRequest(middle);
  wait1msec(150);
  unityTurn(900,-1); //score second goal in 10
  wait1Msec(900);
  unityTurn(900,-1);
  wait1Msec(1000);
  unityStraight(35,true);
  wellIReckon(60,300);
  goalRequest(out,true);
  wellIReckon(60,500);
  unityStraight(-10,true);
  wait1Msec(250);
  goalRequest(middle);      //go for third goal
  unityStraight(-30, true);
  unityTurn(900,1);
  wait1Msec(1000);
  goalRequest(out,true);
  unityStraight(30,true);
  wait1msec(150);
  goalRequest(middle);
  unityTurn(925,-1);
  wait1Msec(1000);
  unityStraight(42,true); //score third goal in 10
  goalRequest(out,true);
  wellIReckon(60,250);
  unityStraight(-15,true);
  wait1Msec(750);
  unityTurn(1850,1);
  wait1msec(1800);
  wellIReckon(-50,1200);
  unityStraight(65,true);
  goalRequest(middle,true);
  unityStraight(60,true);
  wait1Msec(1000);
  goalRequest(out,true);
  unityStraight(-8,true);
  wait1Msec(500);
  goalRequest(middle);
  unityTurn(1250,-1);
  wait1Msec(1200);

  unityStraight(51,true);
  goalRequest(out,true);
  goalRequest(in);
  wait1Msec(250);
  unityStraight(-47);     //drive back
  goalRequest(in,true);
  drivewaity(-47);
  unityTurn(450,1);
  wait1Msec(840);
  unityStraight(-22,true);
  unityTurn(900,1);
  wait1Msec(1000);
  wellIReckon(127,800); //score first goal in 20
  wait1Msec(200);
  wellIReckon(-50,150);
  goalRequest(out,true,300);
  wellIReckon(127,750);
  wellIReckon(75,250);
  unityStraight(-20,true);
  






  /*
  setIntakeMotors(15);
  liftRequest(goal);
  goalRequest(out);           //go for first mgl
  unityStraight(12,true);
  goalRequest(out,true);
  unityStraight(26,true);
  barRequest(drop);
  goalRequest(in,true);
  unityStraight(-33);
  liftRequest(low,true);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(0);
  wait1Msec(1000);
  unityTurn(900,1);
  wait1Msec(750);
  unityStraight(16,true);
  unityTurn(900,1);
  wait1Msec(1000);
  unityStraight(16,true);
  goalRequest(out);
  wellIReckon(100,750);
  goalRequest(out,true,160);
                            // score first 20 pt goal
  unityStraight(-17);
  wait1Msec(350);
  goalRequest(middle);
  wait1Msec(1500);
  unityTurn(900,1);
  wait1Msec(1600);
  unityStraight(16,true);
  unityTurn(860,1);
  wait1Msec(1600);
  wellIReckon(-42,1100); //reckon to bar
  goalRequest(out);
  wellIReckon(20,100);
  unityStraight(68,true);
  goalRequest(in);
  unityStraight(38,true);
  wait1Msec(1250);
  unityTurn(900,1);
  wait1Msec(1000);
  unityStraight(17,true);
  unityTurn(900,-1);
  wait1Msec(1000);
  unityStraight(12,true);
  goalRequest(out);
  wellIReckon(100,1250);
                                    // score second 20pt goal
  unityStraight(-22);
  wait1Msec(350);
  goalRequest(in);
  wait1Msec(1500);
  unityTurn(900,1);
  wait1Msec(1600);
  unityStraight(14,true);
  unityTurn(900,1);
  wait1Msec(1600);
  wellIReckon(-40,2000); //reckon to bar
  goalRequest(out);
  wellIReckon(15,100);
  unityStraight(15,true);
  goalRequest(out,true);
  unityStraight(20,true);
  goalRequest(in,true);
  unityStraight(-31,true);
  unityTurn(1780,1);
  wait1Msec(2000);
  wellIReckon(40,750);
  goalRequest(out,true);
  unityStraight(-10,true);
  goalRequest(out,true);
  goalRequest(middle,true);
  unityTurn(1800,-1);
  wait1Msec(1300);
  goalRequest(out,true);
  unityStraight(60,true);
  goalRequest(middle,true);
  unityStraight(68,true);
  goalRequest(out,true);
  unityStraight(-20);*/


}
//#endregion
#endif
