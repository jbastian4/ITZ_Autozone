#ifndef Variables
#define Variables

enum liftPos {low, goal, para, high};
int liftVal[] = {750, 1020, 1120, 1840};

enum goalPos {out, middle, in};
int goalVal[] = {450, 1605, 2760};

enum barPos {drop, down};
int barVal[] = {350, 2000};

#define liftStillSpeed 15

#define barStillUp 20
#define barStillDown -15
#define autoBarTime 750

#define intakeStill 20

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
