#ifndef Variables
#define Variables

enum barPos {low, norm, drop, back};
int barVal[] = {3770, 2880, 1250, 180};

enum goalPos {out, in};
int goalVal[] = {2555, 245};

#define coneHeight 2.0 //Height of a cone in pot values
#define downHeight 360; //Height to go down when stacking in pot values
#define lowLift 820 //Pot value of the lowest lift height
#define liftPara 1120 //Pot value when the lift is parallel to the ground
#define liftGoal 1020 //Lowest pot value to allow the mobile goal to be moved
#define highLift 1760 //pot value of the highest lift height
#define liftLength 12.5 //length of lift bars
#define uncorrectedCones 0 //how many cones should be uncorrected
#define stackDown (lowLift - 325) //lowLift - how far it should go down at the top
#define apathyCones 1 //number of extra cones to add after the first stack

int coneNum = 0;
#define timePerCone 75
#define baseStackTime 750

#define intakeUp 127
#define intakeDown -127
#define intakeStill 20
#define intakeTime 1000 // was 400

#define radToPot 880.1

#define liftStillSpeed 15

#define barStillUp 20
#define barStillDown 10

float liftOffset = sin((lowLift - liftPara) / radToPot);

//#region drive ramp values
int lPower = 0;
int lPowerReq;
int waitVar;
int skillsFlip=1;

int rPower = 0;
int rPowerReq;

int rampTime = 1;
int normRampSpeed = 7;
int hiRampSpeed = 30;
int nullVal = 10;
//#endregion


int calcNumOfCones()
{
  return (coneNum <= uncorrectedCones) ? 0 : coneNum + apathyCones;
}

int calcLiftTargetForCones()
{
  //return radToPot * asin(calcNumOfCones() * coneHeight / 2 / liftLength + liftOffset) + liftPara;
  //*
  if(calcNumOfCones() <= 9)
  return calcNumOfCones() * coneHeight;
  else
  return (calcNumOfCones() + 2) * coneHeight;
  // */
}

int lastLiftBtnPressed = 1;
int lastBarBtnPressed = 1;

bool stacking = false;
bool intStack = false;
bool manual = true;
bool enableBarPID = true;
#endif
