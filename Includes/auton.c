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
  goalRequest(out);     //go for first mgl
  unityStraight(48);
  drivewaity(47);
  goalRequest(in);
  drivewaity(48);
  goalRequest(in,true);
  wait1Msec(250);
  unityStraight(-46,true);   //drive back
  /*wait1Msec(500);
  motor[clawMot] = -60;
  wait1Msec(300);
  motor[clawMot] = 0;*/
  unityTurn(315,-1,true);//440
  unityStraight(-19,true);
  unityTurn(934,-1,true);//885
  unityStraight(22);
  drivewaity(15);
  goalRequest(middle);
  drivewaity(22);
  wellIReckon(127,500);//score first goal in 20

  unityStraight(-28);
  wait1Msec(400);
  goalRequest(middle);
  drivewaity(-28);
  unityTurn(908,-1,true);
  unityStraight(13,true);
  goalRequest(out);
  unityTurn(855,-1,true);
  goalRequest(out,true);
  unityStraight(32,true);// go for the second mobile goal
  goalRequest(in,true);
  unityTurn(1780,-1,true);
  unityStraight(41);
  drivewaity(25);
  goalRequest(middle); //drop second mobile goal
  drivewaity(41);

  unityStraight(-37);
  wait1Msec(750);
  goalRequest(middle);
  drivewaity(-37);
  unityTurn(980,1,true);
  goalRequest(out,false,100);
  unityStraight(50,true);//go for third goal
  goalRequest(in,true);
  unityTurn(1155,-1,true);
  unityStraight(35,true);
  unityTurn(150,1,true);
  unityStraight(10);
  goalRequest(middle); //score third goal in 10
  drivewaity(10);

  unityStraight(-8,true);
  goalRequest(middle);
  unityTurn(1770,1,true);
  wellIReckon(-27,1250);
  unityStraight(10,true);
  unityTurn(80,-1);
  wait1Msec(250);
  unityStraight(109);// go for fourth mobile goal
  goalRequest(out,false,100);
  drivewaity(60);
  goalRequest(in);
  drivewaity(80);
  goalRequest(middle);// score the fourth mobile goal
  drivewaity(109);
  wellIReckon(-127,100);
  wait1Msec(250);

  wellIReckon(27,500);
  unityStraight(-39);
  wait1Msec(750);
  goalRequest(middle);
  drivewaity(-39);
  unityTurn(990,1,true);
  goalRequest(out,false,100);
  unityStraight(35,true);//go for fifth goal
  goalRequest(in,true);
  unityTurn(1000,-1,true);
  unityStraight(48);
  drivewaity(18);
  goalRequest(middle); //score fifth goal in 10
  drivewaity(48);
  wellIReckon(-127,100);

  unityStraight(-8 ,true);
  unityTurn(900,1,true);
  goalRequest(in);
  unityStraight(8,true);
  unityTurn(430,1,true);
  goalRequest(out);
  unityStraight(57,true);//go for the sixth mobile goal
  wait1Msec(100);
  goalRequest(in,true);
  wait1Msec(250);
  unityStraight(-55,true);
  unityTurn(290,-1,true);
  unityStraight(-17,true);
  unityTurn(940,-1,true);
  unityStraight(23);
  drivewaity(15);
  goalRequest(middle); //score sixth goal in 20
  drivewaity(22);
  wellIReckon(127,500);

  unityStraight(-5,true);
  unityTurn(1100,-1,true); //1155
  unityStraight(80);
  drivewaity(10);
  goalRequest(out);
  drivewaity(80);
  goalRequest(in);
  wait1Msec(500);
  unityTurn(1800,true);
  unityStraight(80,true);



}
//#endregion
#endif
