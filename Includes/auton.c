#ifndef Auton
#define Auton

//#region right
void testAuton()
{
while(1==1){}
}
//#endregion

//#region skills
void skills()
{
  motor[clawMot] = 20;
  goalRequest(out);
  wait1Msec(100);      //go for first mgl
  unityStraight(52,true);
  wait1Msec(100);
  goalRequest(in);
  wait1Msec(500);
  unityStraight(-48);     //drive back
  goalRequest(in,true);
  drivewaity(-48);
  wait1Msec(500);
  motor[clawMot] = -60;
  wait1Msec(300);
  motor[clawMot] = 0;
  unityTurn(430,-1,true);
  unityStraight(-27,true);
  unityTurn(900,-1,true);
  unityStraight(23,true);
  goalRequest(out);
  wellIReckon(-50,100);
  goalRequest(out,true,-600);//score first goal in 20
  goalRequest(out);

  wellIReckon(127,300);
  unityStraight(-25);
  wait1Msec(150);
  goalRequest(middle);
  drivewaity(-25);
  unityTurn(915,-1,true);
  unityStraight(18,true);
  goalRequest(out);
  unityTurn(910,-1,true);
  goalRequest(out,true);
  unityStraight(30,true);// go for the second mobile goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(1750,-1,true);
  unityStraight(39);
  drivewaity(25);
goalRequest(out);
  drivewaity(39);
  goalRequest(out,true);
//  goalRequest(out,true); //drop second mobile goal

  //wellIReckon(60,500);
  unityStraight(-36);
  drivewaity(-10);
  goalRequest(middle);
  drivewaity(-36);
  unityTurn(880,1,true);
  goalRequest(out,true);
  unityStraight(30,true);//go for third goal
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
  goalRequest(out,true,-600);//score fourth goal in 20
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
}
//#endregion
#endif
