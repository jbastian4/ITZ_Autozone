#ifndef Variables
#define Variables

enum liftPos {low, goal, para, high};
int liftVal[] = {820, 1020, 1120, 1760};

enum goalPos {out, in};
int goalVal[] = {2555, 245};

enum barSpeed {drop, down};
int barVal[] = {127, -127};

#define liftStillSpeed 15

#define barStillUp 20
#define barStillDown 10
#define autoBarTime 500

//#region drive ramp values
int lPower = 0;
int lPowerReq;
int waitVar;
bool skillsFlip = false;

int rPower = 0;
int rPowerReq;

int rampTime = 1;
int normRampSpeed = 7;
int hiRampSpeed = 30;
int nullVal = 10;
//#endregion

int lastLiftBtnPressed = 1;
int lastBarBtnPressed = 1;

#endif
