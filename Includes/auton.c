#ifndef Auton
#define Auton

//#region tasks

task lPainPt1()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);           //go for first mgl
  unityStraight(46);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(46);
  unityStraight(12);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  barRequest(drop);
  liftRequest(low,true);
  wait1Msec(250);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(goal);
  barRequest(down,true);
  wait1Msec(100);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(500);
  setIntakeMotors(20);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(200);
  unityStraight(12);
  liftRequest(goal);
  barRequest(down,true);
  wait1Msec(100);
  driveWaity(12);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(500);
  setIntakeMotors(20);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(-20);
  timers[3] = pain20MoveOnTime;
}

//#endregion

//#region right
void rDefensive()
{
  rampInterval = 7;
  setIntakeMotors(20);
  liftRequest(low,false,170);
  barRequest(drop);
  unityStraight(12,true);
  unityTurn(440,-1,true);
  unityStraight(70,true);
  liftRequest(goal);
  unityStraight(-32);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(-80);
  setRDriveMotors(-80);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(out,true,-500);
  startTask(lEncController);
  startTask(rEncController);
  driveWaity(-17);
  liftRequest(low,false,150);
  driveWaity(-32);
  goalRequest(out,true);
  unityTurn(210,-1);//240
  wait1Msec(300);
  turnwaity(210);
  unityStraight(20,true);
  liftRequest(goal);
  unityStraight(10);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(70);
  setRDriveMotors(70);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true,500);
  startTask(lEncController);
  startTask(rEncController);
  driveWaity(10);
  goalRequest(in);
  goalQueryHandler();
  liftRequest(low,false,150);
  unityTurn(200,-1,true);
  unityStraight(-33,true);
  unityTurn(1250,-1,true);
  unityStraight(45,false);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(goal);
  driveWaity(31);
  goalRequest(out,true);
  unityStraight(-30,true);
  unityTurn(1250,-1,true);
  unityStraight(20);
}

void rConeScore()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);
  goalRequest(out,false,220);            //go for first mgl
  unityStraight(44);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(44);
  unityStraight(13);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  goalQueryHandler();
  barRequest(drop,false,200);
  liftRequest(low,true);
  wait1Msec(350);
  setIntakeMotors(-127);
  liftRequest(goal);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(200);
  setIntakeMotors(20);
  rampInterval = 15;
  unityStraight(9);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop,true);
  liftRequest(para,true);
  wait1Msec(200);
  liftRequest(low,true,50);
  liftRequest(low);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(75);
  liftRequest(goal);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(250);
  setIntakeMotors(20);
  rampInterval = 5;
  unityStraight(12);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(para,true);
  liftRequest(low,true,50);
  liftRequest(low);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(para);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(400);
  liftRequest(goal);
  unityStraight(-6);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(low,true,75);
  liftRequest(low);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(100);
  unityTurn(300,1);
  liftRequest(para,true);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(250);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true,60);
  setIntakeMotors(30);
  barRequest(drop,true);
  liftRequest(goal);
  unityTurn(700,-1);
  wait1Msec(200);
  liftRequest(low,true,100);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(para,true,100);
  setIntakeMotors(127);
  barRequest(down,true);
  liftRequest(low,true,100);
  wait1Msec(250);
  liftRequest(para,true);
  barRequest(drop);
  setIntakeMotors(30);
  liftRequest(goal,true);
  barRequest(drop,true);
  setIntakeMotors(-127);
  wait1Msec(500);
  liftRequest(para);
}

void r5GoalScore()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);           //go for first mgl
  goalRequest(out,false,220);
  unityStraight(48);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(48);
  unityStraight(10);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  wait1Msec(150);
  goalQueryHandler();
    unityStraight(-40);
  barRequest(drop);
  liftRequest(low);
  wait1Msec(500);
  setIntakeMotors(-127);
  liftRequest(goal);
  driveWaity(-40);
  unityTurn(1350,-1,true);
  goalManeuver(-10);
  unityStraight(-70,true);
  liftRequest(low,false,150);
  unityTurn(400,-1,true);
}

void r10PointZone()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);           //go for first mgl
  goalRequest(out,false,220);
  unityStraight(47);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(47);
  unityStraight(11);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(55);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  barRequest(drop,true);
  barRequest(drop,false,200);
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
  unityStraight(11);
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
  unityStraight(-70);
  setIntakeMotors(20);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(para);
  driveWaity(-70);
  unityTurn(1330,-1,true);
  goalRequest(out,true);
  liftRequest(low,false,150);
  unityStraight(-30,true);
  unityTurn(26,-1,true);
  unityStraight(-40,true);
  unityTurn(700,-1,true);
  unityStraight(15);
}

void r20PtZone()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);          //go for first mgl
  goalRequest(out,true);
  goalRequest(out,false,220);
  unityStraight(46);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(46);
  unityStraight(12);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  goalQueryHandler();
  barRequest(drop);
  liftRequest(low,true);
  wait1Msec(250);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(goal);
  barRequest(down,true);
  wait1Msec(100);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(500);
  setIntakeMotors(20);
    unityStraight(-57);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  unityStraight(-48);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(20);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(127);
  driveWaity(-48);
  unityTurn(450,-1,true);
  unityStraight(-13,true);
  unityTurn(900,-1,true);
  unityStraight(15,true);
  goalRequest(out,true);
  liftRequest(low,false,150);
  wellIReckon(127,250);
  unityStraight(-20);
  wait1Msec(200);
}

//#endregion

//#region left
void lDefensive()
{
  setIntakeMotors(20);
  liftRequest(low,false,150);
  barRequest(drop);
  unityStraight(15,true);
  unityTurn(490,-1,true);
  unityStraight(70,true);
  liftRequest(low,false,150);
  unityStraight(-3,true);
  goalRequest(out);
  liftRequest(goal);
  goalManeuver(-25);
  liftRequest(low,false,150);
  unityTurn(300,-1,true);//240
  unityStraight(20,true);
  liftRequest(goal);
  goalManeuver(9);
  goalQueryHandler();
  liftRequest(low,false,150);
  unityTurn(200,-1,true);
  unityStraight(-33,true);
  liftRequest(low,false,150);
  unityTurn(1300,-1,true);
  unityStraight(30,false);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(goal);
  driveWaity(30);
  goalRequest(out,true);
  unityStraight(-12,true);
  unityTurn(1250,-1,true);
}

void lConeScore()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);
  goalRequest(out,false,220);            //go for first mgl
  unityStraight(44);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(44);
  unityStraight(13);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  goalQueryHandler();
  barRequest(drop,false,200);
  liftRequest(low,true);
  wait1Msec(350);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(goal);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(200);
  setIntakeMotors(20);
  unityStraight(7);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop,true);
  liftRequest(para,true);
  liftRequest(low,true,50);
  liftRequest(low);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(75);
  liftRequest(goal);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(250);
  setIntakeMotors(20);
  unityStraight(9);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(para,true);
  liftRequest(low,true,50);
  liftRequest(low);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(para);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(200);
  liftRequest(goal);
  unityStraight(-6);
  liftRequest(para,true);
  barRequest(drop,true);
  liftRequest(low,true,75);
  liftRequest(low);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(100);
  unityTurn(300,-1);
  liftRequest(para,true);
  barRequest(down,true);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(250);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true,60);
  setIntakeMotors(30);
  barRequest(drop,true);
  liftRequest(goal);
  unityTurn(700,1);
  wait1Msec(200);
  liftRequest(low,true,100);
  wait1Msec(100);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(para,true,100);
  setIntakeMotors(127);
  barRequest(down,true);
  liftRequest(low,true,100);
  wait1Msec(250);
  liftRequest(para,true);
  barRequest(drop);
  setIntakeMotors(30);
  liftRequest(goal,true);
  barRequest(drop,true);
  setIntakeMotors(-127);
  wait1Msec(500);
  liftRequest(para);
}

void l5GoalScore()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);           //go for first mgl
  goalRequest(out,false,220);
  unityStraight(48);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(48);
  unityStraight(10);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  wait1Msec(150);
  goalQueryHandler();
    unityStraight(-40);
  barRequest(drop);
  liftRequest(low);
  wait1Msec(500);
  setIntakeMotors(-127);
  liftRequest(goal);
  driveWaity(-40);
  unityTurn(1350,1,true);
  goalManeuver(-10);
  unityStraight(-70,true);
  liftRequest(low,false,150);
  unityTurn(400,1,true);
}

void l10PointZone()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);           //go for first mgl
  goalRequest(out,false,220);
  unityStraight(44);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(44);
  unityStraight(11);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(55);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  barRequest(drop,true);
  barRequest(drop,false,200);
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
  unityStraight(11);
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
  unityTurn(150,1);
  liftRequest(goal,true);
  unityStraight(-60);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(250);
  liftRequest(para);
  driveWaity(-60);
  unityTurn(300,1,true);
  setIntakeMotors(0);
  unityStraight(-6,true);
  unityTurn(1030,1,true);
  goalRequest(out,true);
  liftRequest(low,false,150);
  unityStraight(-30,true);
  unityTurn(26,1,true);
  unityStraight(-40,true);
  unityTurn(700,1,true);
  unityStraight(15);
}

void l20PtZone()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);          //go for first mgl
  goalRequest(out,true);
  goalRequest(out,false,220);
  unityStraight(46);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(46);
  unityStraight(12);
  stopTask(lEncController);
  stopTask(rEncController);
  setLDriveMotors(40);
  setRDriveMotors(40);
  wait1Msec(250);
  liftRequest(goal);
  goalRequest(in,true);
  startTask(lEncController);
  startTask(rEncController);
  goalQueryHandler();
  barRequest(drop);
  liftRequest(low,true);
  wait1Msec(250);
  setIntakeMotors(-127);
  wait1Msec(100);
  liftRequest(goal);
  barRequest(down,true);
  wait1Msec(100);
  setIntakeMotors(127);
  liftRequest(low,true);
  wait1Msec(500);
  unityTurn(160,1);
  setIntakeMotors(20);
  liftRequest(goal,true);
  liftRequest(para);
  barRequest(drop);
  liftRequest(para,true);
  unityStraight(-57);
  liftRequest(low,true,100);
  setIntakeMotors(-127);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(20);
  wait1Msec(200);
  liftRequest(goal);
  setIntakeMotors(127);
  driveWaity(-57);
  unityTurn(450,1,true);
  unityStraight(-18,true);
  unityTurn(930,1,true);
  unityStraight(15,true);
  goalRequest(out,true);
  liftRequest(low,false,150);
  wellIReckon(127,250);
  unityStraight(-20);
  wait1Msec(200);
  liftRequest(goal,true);
  goalRequest(in);
}

void lPain20()
{
  resetTimer(auton);
  startTask(lPainPt1);
  while(time(auton) < pain20MoveOnTime) {}
  stopTask(lPainPt1);

  unityTurn(200,1,true);
  unityStraight(-54);
  wait1Msec(200);
  liftRequest(para);
  setIntakeMotors(127);
  driveWaity(-54);
  unityTurn(450,1,true);
  unityStraight(-17,true);
  unityTurn(770,1,true);
  unityStraight(13,true);
  goalRequest(out,true);
  liftRequest(low,false,150);
  wellIReckon(127,250);
  unityStraight(-20);
  wait1Msec(200);
  liftRequest(goal,true);
  goalRequest(in);
}

//#endregion

//#region skills

void testAuton()
{
  setIntakeMotors(15);
  barRequest(drop);
  liftRequest(goal);
  goalRequest(out,true);           //go for first mgl
  unityStraight(46);
  liftRequest(low,false,150);
  driveWaity(36);
  liftRequest(para);
  driveWaity(46);
}
/*
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
  driveWaity(-53);
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
  driveWaity(-20);
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
  driveWaity(50);
  goalRequest(in);
  driveWaity(92);
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

  driveWaity(-23);
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
  driveWaity(-60);
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
  driveWaity(30);
  goalRequest(out);
  driveWaity(35);
  wellIReckon(50,750);
  goalRequest(out,true);// score the sixth mobile goal
  unityStraight(-9,true);
  unityTurn(370,-1);
  wait1Msec(350);
  unityStraight(-80);
  */








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
//}
//#endregion

#endif
