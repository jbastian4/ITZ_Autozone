#ifndef Auton
#define Auton

//#region right
void testAuton()
{
unityStraight(100000,true);
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
  wait1Msec(500);
  unityStraight(-40);   //drive back
  wait1Msec(300);
  motor[clawMot] = -60;
  wait1Msec(300);
  motor[clawMot] = 0;
  drivewaity(-40);
  unityTurn(320,-1,true);//440
  unityStraight(-30,true);
  drivewaity(-30);
  unityTurn(910,-1,true);//885
  unityStraight(27);
  drivewaity(18);
  goalRequest(middle);
  drivewaity(27);
  goalRequest(out,true);//score first goal in 20
  wait1Msec(250);

  unityStraight(-26);
  //wait1Msec(110);
  goalRequest(middle);
  wait1Msec(150);
  drivewaity(-26);
  unityTurn(850,-1,true);
  unityStraight(15,true);
  goalRequest(out);
  unityTurn(820,-1,true);
  goalRequest(out,true);
  unityStraight(34,true);// go for the second mobile goal
  goalRequest(in,true);
  unityTurn(1700,-1,true);
  unityStraight(45);
  drivewaity(25);
  goalRequest(middle); //drop second mobile goal
  drivewaity(43);

  unityStraight(-38);
  wait1Msec(750);
  goalRequest(middle);
  drivewaity(-38);
  unityTurn(950,1,true);
  goalRequest(out,false,100);
  unityStraight(53,true);//go for third goal
  goalRequest(in,true);
  wait1Msec(100);
  goalRequest(in,true);
  unityTurn(1100,-1,true);
  unityStraight(35,true);
  unityTurn(150,1,true);
  unityStraight(8);
  goalRequest(middle); //score third goal in 10
  drivewaity(8);

  unityStraight(-6,true);
  goalRequest(middle);
  unityTurn(1735,1,true);
  unityStraight(112);// go for fourth mobile goal
  goalRequest(out,false,100);
  drivewaity(60);
  goalRequest(in);
  drivewaity(80);
  goalRequest(middle);// score the fourth mobile goal
  drivewaity(110);

  unityStraight(-36);
  wait1Msec(750);
  goalRequest(out);
  drivewaity(-36);
  unityTurn(940,1,true);
  goalRequest(out,false,100);
  unityStraight(45,true);//go for fifth goal
  goalRequest(in,true);
  unityTurn(980,-1,true);
  unityStraight(49);
  drivewaity(18);
  goalRequest(middle); //score fifth goal in 10
  drivewaity(49);

  unityStraight(-8 ,true);
  unityTurn(900,1,true);
  goalRequest(in);
  unityStraight(9,true); //10
  unityTurn(400,1,true);
  goalRequest(out,true);
  unityStraight(58,true);//go for the sixth mobile goal
  goalRequest(in,true);
  wait1Msec(250);
  unityStraight(-54,true);
  unityTurn(320,-1,true);
  unityStraight(-19,true);//21
  unityTurn(900,-1,true);
  unityStraight(27);
  drivewaity(15);
  goalRequest(middle); //score sixth goal in 20
  drivewaity(27);

  unityStraight(-25,true);
  unityTurn(1270,-1,true); //1155
  unityStraight(75);
  drivewaity(10);
  goalRequest(out);
  drivewaity(75);
  goalRequest(in,true);
  wait1Msec(500);
  unityStraight(-75,true);
  unityTurn(1000,1,true);
  goalRequest(middle);
  unityStraight(8,true);
  unityTurn(400,-1,true);
  wellIReckon(-127,4000);



}
//#endregion
#endif
