#ifndef Variables
#define Variables

enum goalPos {out, middle, in};
int goalVal[] = {415, 1605, 2660};

enum timeType {mgl, lift, BART};
long timers[] = {0, 0, 0};

//#region drive ramp values
int LDriveRampRequest;
int LDriveRampSgn;
int LDriveRampCurrent;
int goalstill;

int RDriveRampRequest;
int RDriveRampSgn;
int RDriveRampCurrent;

int rampInterval = 1;
int normalRampSpeed = 7;
int highRampSpeed = 30;
int deadband = 10;
//#endregion

#endif
