#ifndef Auton
#define Auton

//#region right
void testAuton()
{

}
//#endregion

//#region skills
void skills()
{
  goalRequest(out);         //go for first mgl
  unityStraight(51,true);
  goalRequest(out,true);
  goalRequest(in);
  wait1Msec(250);
  unityStraight(-53);     //drive back
  goalRequest(in,true);
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
}
//#endregion
#endif
