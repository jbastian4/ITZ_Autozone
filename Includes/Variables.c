#ifndef Variables
#define Variables

enum liftPos {low, goal, para, high};
int liftVal[] = {490, 790, 1135, 2215};

enum goalPos {out, middle, in};
int goalVal[] = {3400, 1590, 563};

enum barPos {drop, down};
int barVal[] = {2111, 111};

enum timeType {mgl, lift, BART};
long timers[] = {0, 0, 0};

#define liftStillSpeed 15

#define barStillUp 20
#define barStillDown -15
#define autoBarTime 750

#define intakeStill 30

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
