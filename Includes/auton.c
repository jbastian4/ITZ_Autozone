#ifndef Auton
#define Auton

//#region right
void testAuton()
{
unityTurn(900,-1,true);
wait1Msec(1000);
unityTurn(900,-1,true);
wait1Msec(1000);
unityTurn(900,-1,true);
wait1Msec(1000);
unityTurn(900,-1,true);
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
  unityStraight(-45);     //drive back
  goalRequest(in,true);
  drivewaity(-45);
  wait1Msec(500);
  motor[clawMot] = -60;
  wait1Msec(300);
  motor[clawMot] = 0;
  unityTurn(445,-1,true);
  unityStraight(-21,true);
  unityTurn(885,-1,true);
  unityStraight(22,true);
  goalRequest(out);
  wellIReckon(-50,100);
  goalRequest(out,true,-600);//score first goal in 20
  goalRequest(out);
  wellIReckon(127,300);

  unityStraight(-30);
  wait1Msec(400);
  goalRequest(middle);
  drivewaity(-30);
  unityTurn(905,-1,true);
  unityStraight(10,true);
  goalRequest(out);
  unityTurn(905,-1,true);
  goalRequest(out,true);
  unityStraight(27,true);// go for the second mobile goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(1790,-1,true);
  unityStraight(37);
  drivewaity(37);
  wellIReckon(40,175);
  goalRequest(out,true); //drop second mobile goal
  wellIReckon(70,250);

  unityStraight(-37);
  wait1Msec(750);
  goalRequest(middle);
  drivewaity(-37);
  unityTurn(910,1,true);
  goalRequest(out,true);
  unityStraight(26,true);//go for third goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(900,-1);
  wait1Msec(900);
  unityStraight(46,true);
  wellIReckon(50,200);
  goalRequest(out,true);//score third goal in 10
  wellIReckon(60,250);

  unityStraight(-15,true);
  wait1Msec(750);
  unityTurn(1700,1);
  wait1Msec(1700);
  unityStraight(96);// go for fourth mobile goal
  drivewaity(50);
  goalRequest(in);
  drivewaity(96);
  goalRequest(out, true); //score fourth goal in 10
  wellIReckon(60,250);

  unityStraight(-37);
  wait1Msec(750);
  goalRequest(middle);
  drivewaity(-37);
  unityTurn(910,1,true);
  goalRequest(out,true);
  unityStraight(26,true);//go for fifth goal
  goalRequest(middle);
  wait1Msec(150);
  unityTurn(900,-1);
  wait1Msec(900);
  unityStraight(46,true);
  wellIReckon(50,200);
  goalRequest(out,true);//score fifth goal in 10
  wellIReckon(60,250);


  unityStraight(-10,true);
  unityTurn(750,1,true);
  unityStraight(60,true);
  goalRequest(middle,true);
  goalRequest(out);
  unityStraight(-60,true);
  unityTurn(260,-1,true);
  unityStraight(-20,true);
  unityTurn(900,1,true);
  unityStraight(22,true);
  goalRequest(out);
  wellIReckon(-50,100);
  goalRequest(out,true,-600);//score first goal in 20
  goalRequest(out);
  wellIReckon(127,300);

  unityStraight(-30);






  /*unityTurn(900,-1);
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
  unityStraight(-80);*/
}
//#endregion
#endif
