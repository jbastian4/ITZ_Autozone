#ifndef Auton
#define Auton

//#region right
void rGoalScore()
{
  setIntakeMotors(15);  //go for first mgl
  liftRequest(goal);
  goalRequest(out,true);
  unityStraight(51,true);
  barRequestedValue=drop;
  goalRequest(in,true);
  unityStraight(-47);     //drive back
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
  unityStraight(-20,true);
}

void r20PtZone()
{
  setIntakeMotors(15);
  liftRequest(para);
  barRequest(drop);
  goalRequest(out,true);           //go for first mgl
  unityStraight(50,true);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  goalRequest(in,true);
  unityStraight(0);
  startTask(lEncController);
  startTask(rEncController);
  liftRequest(low);
  wait1Msec(250);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(goal);
  barRequest(down);
  wait1Msec(100);
  setIntakeMotors(127);
  liftRequest(low);
  wait1Msec(500);
  setIntakeMotors(20);
  unityStraight(8);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  barRequest(down);
  wait1Msec(200);
  setIntakeMotors(127);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(20);
  unityStraight(-55);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(para);
  setIntakeMotors(127);
  drivewaity(-55);
  unityTurn(450,-1,true);
  unityStraight(-19,true);
  unityTurn(920,-1,true);
  unityStraight(17,true);
  goalRequest(out,true);
  wellIReckon(127,250);
  unityStraight(-20);
  wait1Msec(200);
  goalRequest(in);

}

void r10PointZone()
{
  setIntakeMotors(15);
  liftRequest(para);
  barRequest(drop);
  goalRequest(out,true);           //go for first mgl
  unityStraight(54,true);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  goalRequest(in,true);
  unityStraight(0);
  startTask(lEncController);
  startTask(rEncController);
  liftRequest(low);
  wait1Msec(500);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  barRequest(down);
  wait1Msec(150);
  setIntakeMotors(127);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(20);
  unityStraight(6);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(goal);
  barRequest(down);
  wait1Msec(250);
  setIntakeMotors(127);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(20);
  unityStraight(-55);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(para);
  drivewaity(-55);
  unityTurn(220,-1);
  wait1Msec(500);
  setIntakeMotors(0);
  unityStraight(-15,true);
  unityTurn(1350,-1,true);
  goalRequest(out,true);
  liftRequest(low);
  unityStraight(-30,true);
  unityTurn(26,-1,true);
  unityStraight(-40,true);
  unityTurn(700,-1,true);
  unityStraight(15);
}
//#endregion

//#region left
void lGoalScore()
{
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
  liftRequest(para);
  barRequest(drop);
  goalRequest(out,true);           //go for first mgl
  unityStraight(48,true);
  unityStraight(8);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  barRequest(drop);
  liftRequest(low,true);
  setIntakeMotors(-127);
  liftRequest(goal);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(250);
  setIntakeMotors(20);
  unityStraight(7);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop,true);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  liftRequest(goal);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(320);
  setIntakeMotors(20);
  unityStraight(11);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(para,true);
  liftRequest(goal,true,-60);
  setIntakeMotors(-127);
  liftRequest(para);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(250);
  liftRequest(goal);
  unitystraight(-6);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(goal,true,20);
  setIntakeMotors(-127);
  unityTurn(300,1);
  liftRequest(para,true);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(500);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true,60);
  setIntakeMotors(30);
  barRequest(drop,true);
  liftRequest(goal);
  unityTurn(700,-1)
  wait1Msec(200);
  setIntakeMotors(-127);
  wait1Msec(300);
  liftRequest(para,true,100);
  setIntakeMotors(127);
  barRequest(down,true);
  liftRequest(low,true,100);
  wait(250);
  liftRequest(para,true);
  barRequest(drop);
  setIntakeMotors(30);
  liftRequest(para,true,150);
  barRequest(drop,true);
  liftRequest(para);
  setIntakeMotors(-127);
  liftRequest(high);

}

void l10PointZone()
{
  setIntakeMotors(15);
  liftRequest(para);
  barRequest(drop);
  goalRequest(out,true);           //go for first mgl
  unityStraight(54,true);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  goalRequest(in,true);
  unityStraight(0);
  startTask(lEncController);
  startTask(rEncController);
  liftRequest(low);
  wait1Msec(500);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  barRequest(down);
  wait1Msec(150);
  setIntakeMotors(127);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(20);
  unityStraight(6);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(goal);
  barRequest(down);
  wait1Msec(250);
  setIntakeMotors(127);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(20);
  unityStraight(-55);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(para);
  drivewaity(-55);
  unityTurn(220,1);
  wait1Msec(500);
  setIntakeMotors(0);
  unityStraight(-15,true);
  unityTurn(1350,1,true);
  goalRequest(out,true);
  liftRequest(low);
  unityStraight(-30,true);
  unityTurn(26,1,true);
  unityStraight(-40,true);
  unityTurn(700,1,true);
  unityStraight(15);




}

void testAuton()
{

  liftRequest(goal);
  goalRequest(middle,true);
  wellIReckon(127,2000);

  wellIReckon(-127,2000);

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
  unityStraight(-53);     //drive back
  goalRequest(in,true);
  liftRequest(low);
  wait1Msec(750);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  wait1Msec(150);
  setIntakeMotors(0);
  drivewaity(-53);
  unityTurn(430,-1);
  wait1Msec(430);
  unityStraight(-19,true);
  unityTurn(900,-1);
  wait1Msec(800);
  unityStraight(23,true);
  goalRequest(out);
  wellIReckon(-50,100);
  goalRequest(out,true,600);//score first goal in 20
  goalRequest(out);

  wellIReckon(127,300);
  unityStraight(-20);
  wait1Msec(150);
  goalRequest(middle);
  drivewaity(-20);
  unityTurn(870,-1);
  wait1Msec(850);
  unityStraight(18,true);
  unityTurn(920,-1);
  goalRequest(out);
  wait1Msec(1000);
  goalRequest(out,true);
  unityStraight(24,true);// go for the second mobile goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(1750,-1);
  wait1Msec(1650);
  unityStraight(35,true);
  goalRequest(out,true); //drop second mobile goal

  wellIReckon(60,500);
  unityStraight(-10,true);
  wait1Msec(250);
  unityStraight(-32, true);
  unityTurn(880,1);
  wait1Msec(860);
  goalRequest(out,true);
  unityStraight(28,true);//go for third goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(920,-1);
  wait1Msec(900);
  unityStraight(42,true);
  goalRequest(out,true);//score third goal in 10
  wellIReckon(60,250);
  unityStraight(-15,true);
  wait1Msec(750);
  unityTurn(1700,1);
  wait1Msec(1700);
  unityStraight(92);// go for fourth mobile goal
  drivewaity(50);
  goalRequest(in);
  drivewaity(92);
  unityTurn(900,-1);
  wait1Msec(880);
  unityStraight(-16,true);
  unityTurn(900,1);
  wait1Msec(880);
  unityStraight(17,true);
  wellIReckon(-50,100);
  goalRequest(middle);
  goalRequest(out,true,600);//score fourth goal in 20
  goalRequest(out);

  wellIReckon(127,750);
  unityStraight(-23);
  wait1Msec(250);
  goalRequest(middle);

  drivewaity(-23);
  goalRequest(middle);

  unityTurn(1180,-1);
  wait1Msec(1200);

  goalRequest(out);
  unityStraight(68,true);//go for fifth mobile goal
  goalRequest(out,true);
  goalRequest(in);
  wait1Msec(250);
  unityStraight(-60);     //drive back
  goalRequest(in,true);
  drivewaity(-60);
  unityTurn(1360,1);
  wait1Msec(840);
  unityStraight(12,true);
  goalRequest(out);// score fifth mobile goal
  wellIReckon(50,1000);
  goalRequest(out,true);
  unityStraight(-8,true);
  unityTurn(900,1);
  wait1Msec(900);
  unityStraight(21,true);
  unityTurn(920,1);
  wait1Msec(880);
  unityStraight(27,true);// go for sixth mobile goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(1750,1);
  wait1Msec(1700);
  unityStraight(35);
  drivewaity(30);
  goalRequest(out);
  drivewaity(35);
  wellIReckon(50,750);
  goalRequest(out,true);// score the sixth mobile goal
  unityStraight(-9,true);
  unityTurn(370,-1);
  wait1Msec(350);
  unityStraight(-80);









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
