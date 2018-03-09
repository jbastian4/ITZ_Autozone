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
  wait1Msec(250);
  unityStraight(-38);   //drive back
  wait1Msec(300);
  motor[clawMot] = -60;
  wait1Msec(300);
  motor[clawMot] = 0;
  drivewaity(-38);
  unityTurn(315,-1,true);//440
  unityStraight(-29,true);
  drivewaity(-30);
  unityTurn(934,-1,true);//885
  unityStraight(23);
  drivewaity(15);
  goalRequest(middle);
  drivewaity(23);
  goalRequest(out);//score first goal in 20
  wait1Msec(500);

  unityStraight(-21);
  //wait1Msec(110);
  goalRequest(middle);
  wait1Msec(150);
  drivewaity(-21);
  unityTurn(908,-1,true);
  unityStraight(12,true);
  goalRequest(out);
  unityTurn(800,-1,true);
  goalRequest(out,true);
  unityStraight(34,true);// go for the second mobile goal
  goalRequest(in,true);
  unityTurn(1720,-1,true);
  unityStraight(43);
  drivewaity(25);
  goalRequest(middle); //drop second mobile goal
  drivewaity(43);

  unityStraight(-34);
  wait1Msec(750);
  goalRequest(middle);
  drivewaity(-34);
  unityTurn(930,1,true);
  goalRequest(out,false,100);
  unityStraight(56,true);//go for third goal
  goalRequest(in,);
  wait1Msec(750);
  unityTurn(1100,-1,true);
  unityStraight(35,true);
  unityTurn(150,1,true);
  unityStraight(8);
  goalRequest(middle); //score third goal in 10
  drivewaity(8);

  unityStraight(-6,true);
  goalRequest(middle);
  unityTurn(1735,1,true);
  //wellIReckon(-50,750);     pulled out line for speed
  //unityStraight(10,true);
  //unityTurn(60,-1);
  //wait1Msec(150);
  //unityTurn(80,-1);
  //wait1Msec(250);
  unityStraight(110);// go for fourth mobile goal
  goalRequest(out,false,100);
  drivewaity(60);
  goalRequest(in);
  drivewaity(80);
  goalRequest(middle);// score the fourth mobile goal
  drivewaity(110);
  wellIReckon(127,150)
  wellIReckon(-127,150);

  wellIReckon(27,500);
  unityStraight(-36);
  wait1Msec(750);
  goalRequest(out);
  drivewaity(-36);
  unityTurn(880,1,true);
  goalRequest(out,false,100);
  unityStraight(45,true);//go for fifth goal
  goalRequest(in,true);
  unityTurn(900,-1,true);
  unityStraight(49);
  drivewaity(18);
  goalRequest(middle); //score fifth goal in 10
  drivewaity(49);
  wellIReckon(-127,100);
  wellIReckon(27,1000);

  unityStraight(-8 ,true);
  unityTurn(900,1,true);
  goalRequest(in);
  unityStraight(10,true);
  unityTurn(400,1,true);
  goalRequest(out,true);
  unityStraight(58,true);//go for the sixth mobile goal
  goalRequest(in,true);
  wait1Msec(250);
  unityStraight(-55,true);
  unityTurn(320,-1,true);
  unityStraight(-21,true);
  unityTurn(940,-1,true);
  unityStraight(23);
  drivewaity(15);
  goalRequest(middle); //score sixth goal in 20
  drivewaity(22);
  wellIReckon(127,500);

  unityStraight(-23,true);
  unityTurn(1200,-1,true); //1155
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
  wellIReckon(-127,250);
  unityTurn(300,-1,true);
  wellIReckon(-127,4000);



}
//#endregion
#endif
