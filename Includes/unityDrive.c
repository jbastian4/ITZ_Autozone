#ifndef unity_Drive
#define unity_Drive
//#include "Functions.c"
//<editor-fold Variables
//#region User Variables
#define gyroPort in1
#define lEncPort dgtl8
#define rEncPort dgtl3

#define lDrivePort1 port10
#define lDrivePort2 port9
#define rDrivePort1 port4
//#define rDrivePort2 port12

float wheelDiameter = 4;

int dontHog = 25; //don't hog cpu wait time

int stopError = 17; //allowed variation distance for drivestraight stop (inches)
int stopTime = 200;

int driveStraightError = 8;

int gyroCoeff = 1;
int gyroDriveCoeff = -1;

//Encoder PID Values
static float  lEnc_Kp = 0.8; //.45
static float  lEnc_Kd = 0.03;

static float  rEnc_Kp = 0.45;
static float  rEnc_Kd = 0.03;

//Gyro PID Values
static float  gyro_Kp = 0.35; //.08
static float  gyro_Kd = 1; //.2

//Drive ramp values
int rampInterval = 5;
int lNormalRampSpeed = 15; //was 7
int rNormalRampSpeed = 10;
int lHighRampSpeed = 15.; //was 30
int rHighRampSpeed = 9;//was 35
int nullPower = 10;
//#endregion

//#region System Variables
int funcDriveMode = 0;//these allow variables used in the task to be changed only at the beginning of the task
int funcDriveModifier = 0;
int funcDirection = 0;

int driveMode = 0; //0 is drivestraight, 1 is turn, 2 is free
int direction = 0; //0 is stopped, 1 is forward/right, -1 is backward/left
int driveModifier = 0; //Ls drive distance or turn angle
bool newDriveCommand = false; //signals to the task when a new drive command has been given
bool driveEncoderPID = true; //enables/disables encoder pid
bool gyroPID = false; //enables/disables gyro pid
bool enableEverything = true;

bool isDriving = false; //records if the drivestraight is actually running;
int  goalfree = 0; //records wether on not a drive or turn is in progress to properly set the goal motors
int countsToInches(float value) //converts drive encoder counts into inches
{
  return (value * 360)/(PI * wheelDiameter);
}

//drive ramp values
int leftPower = 0;

int rightPower = 0;

//Encoder PID Values
int  lEncRequestedValue;
int  rEncRequestedValue;
int  gyroRequestedValue;

float lEncD;
float lEncP;
float lastlEncError;
float lEncDF;

float  lEncSensorCurrentValue;
float  lEncError;
float  lEncDrive;

float rEncD;
float rEncP;
float lastrEncError;
float rEncDF;

float  rEncSensorCurrentValue;
float  rEncError;
float  rEncDrive;

float gyroD;
float gyroP;
float lastGyroError;
float gyroDF;

float  gyroCurrentValue;
float  gyroError;
float  gyroDrive;
//#endregion
//</editor-fold>

//<editor-fold Functions
//#region Drive Functions
void driveWaity(int distance)
{
  int ticks = fabs(countsToInches(distance));
  while(fabs(SensorValue[lEnc]) <= ticks - stopError){}
  wait1Msec(stopTime);
  ticks = 0;
}
void unityStraight(int distance, bool waity = false) //this void sends appropriate values to the main drive task
{

  int direction = sgn(distance);
  funcDriveMode = 0; //drive straight
  funcDriveModifier = abs(distance); //sets drive distance
  funcDirection = direction; //set drive direction

  newDriveCommand = true; //tells the task that it has new instructions
  isDriving = true; //sets PID tasks to run drivestraight

  if(waity)
  {
    wait1Msec(stopTime);
    driveWaity(distance);
  }
}
void turnwaity(int degrees)
  {
    while(fabs(SensorValue[gyroPort]) <= fabs(degrees) - 100){}
    wait1Msec(stopTime);
  }
void unityTurn(int degrees, int direction,bool waity=false)
{
  funcDriveMode = 1; //turn
  funcDriveModifier = degrees; //sets number of degrees to turn
  funcDirection = direction; //set turn direction

  newDriveCommand = true; //tells the task that it has new instructions
  isDriving = false; //sets PID tasks to not run drivestraight
  if(waity)
  {
    turnwaity(degrees);
  }

}
//#endregion

//#region set motor functions
void setLDriveMotors(int power)
{
	motor[lDrivePort1] = power;
	motor[lDrivePort2] = power;
}
void setRDriveMotors(int power)
{
	motor[rDrivePort1] = power;
//	motor[rDrivePort2] = power;
}
//#endregion

//#region Ramp Functions
void leftDriveRamp(int leftPowerReq) //ramping
{
if(leftPower >= 30)
{
	if(leftPowerReq > leftPower)
	{
		leftPower += lNormalRampSpeed;
	}
	else if(leftPowerReq < leftPower)
	{
		leftPower = leftPowerReq;
	}
}
else if(leftPower <= -30)
{
	if(leftPowerReq < leftPower)
	{
		leftPower -= lNormalRampSpeed;
	}
	else if(leftPowerReq > leftPower)
	{
		leftPower = leftPowerReq;
	}
}
else if((leftPower > -30 && leftPower < -10) || (leftPower < 30 && leftPower > 10))
{
	if(leftPowerReq > leftPower)
	{
		leftPower += lHighRampSpeed;
	}
	if(leftPowerReq < leftPower)
	{
		leftPower = leftPowerReq;
	}
}
else
{
	if(leftPowerReq > leftPower)
	{
		leftPower += lNormalRampSpeed;
	}
	if(leftPowerReq < leftPower)
	{
		leftPower = leftPowerReq;
	}
}

if(abs(leftPowerReq) < nullPower)
{
	leftPower = 0;
}

  if(enableEverything)
  {
    setLDriveMotors(leftPower);
    if(goalfree==0)
    {
      motor[lGoalMot]=leftPower-20;
    }
  }
wait1Msec(rampInterval);
//setLDriveMotors(leftPowerReq);
}

void rightDriveRamp(int rightPowerReq) //ramping
{
  if(rightPower >= 30)
  {
  	if(rightPowerReq > rightPower)
  	{
  		rightPower += rNormalRampSpeed;
  	}
  	else if(rightPowerReq < rightPower)
  	{
  		rightPower = rightPowerReq;
  	}
  }
  else if(rightPower <= -30)
  {
  	if(rightPowerReq < rightPower)
  	{
  		rightPower -= rNormalRampSpeed;
  	}
  	else if(rightPowerReq > rightPower)
  	{
  		rightPower = rightPowerReq;
  	}
  }
  else if((rightPower > -30 && rightPower < -10) || (rightPower < 30 && rightPower > 10))
  {
  	if(rightPowerReq > rightPower)
  	{
  		rightPower += rHighRampSpeed;
  	}
  	if(rightPowerReq < rightPower)
  	{
  		rightPower = rightPowerReq;
  	}
  }
  else
  {
  	if(rightPowerReq > rightPower)
  	{
  		rightPower += rNormalRampSpeed;
  	}
  	if(rightPowerReq < rightPower)
  	{
  		rightPower = rightPowerReq;
  	}
  }

  if(abs(rightPowerReq) < nullPower)
  {
  	rightPower = 0;
  }

  if(enableEverything)
  {
    setRDriveMotors(rightPower);
    if(goalfree==0)
    {
      motor[rGoalMot]=rightPower-20;
    }
  }
  wait1Msec(rampInterval);
  //setRDriveMotors(rightPowerReq);
}
//#endregion
//</editor-fold>

//<editor-fold Tasks
//#region PID Controllers
task lEncController()
{
	while(true)
	{
    if(driveEncoderPID == true)
    {
		// Read the sensor value and scale
		lEncSensorCurrentValue = SensorValue[lEncPort];

		// calculate error
		lEncError =  lEncRequestedValue - lEncSensorCurrentValue;

		// calculate drive
		lEncP = (lEnc_Kp * lEncError);

		lEncD = lEncError- lastlEncError;
		lEncDF = (lEnc_Kd * lEncD);

		lEncDrive = lEncP + lEncDF;

		// limit drive
		if(lEncDrive > 100)
			lEncDrive = 100;
		if(lEncDrive < -100)
			lEncDrive = -100;

    //correct for drivestraight
    if(isDriving == true)
    {
      if(SensorValue[lEncPort] > (SensorValue[rEncPort] + driveStraightError) && direction == 1)
        lEncDrive -= (SensorValue[lEncPort] - SensorValue[rEncPort]);
      else if(SensorValue[lEncPort] < (SensorValue[rEncPort] - driveStraightError) && direction == -1)
        lEncDrive += (SensorValue[rEncPort] - SensorValue[lEncPort]);
    }

    // limit drive again
	   if(lEncDrive > 127)
			lEncDrive = 127;
		if(lEncDrive < -127)
			lEncDrive = -127;


		// send to motor

		leftDriveRamp(lEncDrive+10);

		lastlEncError = lEncError;
    }

		// Don't hog cpu
		wait1Msec(dontHog);
  }
}

task rEncController()
{
	while(true)
	{
    if(driveEncoderPID == true)
    {
		// Read the sensor value and scale
		rEncSensorCurrentValue = SensorValue[rEncPort];

		// calculate error
		rEncError =  rEncRequestedValue - rEncSensorCurrentValue;

		// calculate drive
		rEncP = (rEnc_Kp * rEncError);

		rEncD = rEncError - lastrEncError;
		rEncDF = (rEnc_Kd * rEncD);

		rEncDrive = rEncP + rEncDF;

		// limit drive
		if(rEncDrive > 90)
			rEncDrive = 90;
		if(rEncDrive < -90)
			rEncDrive = -90;

    //correct for drivestraight
    if (isDriving == true)
    {
      if(SensorValue[rEncPort] > (SensorValue[lEncPort] + driveStraightError) && direction == 1)
        rEncDrive -= (SensorValue[rEncPort] - SensorValue[lEncPort]);
      else if(SensorValue[rEncPort] < (SensorValue[lEncPort] - driveStraightError) && direction == -1)
        rEncDrive += (SensorValue[lEncPort] - SensorValue[rEncPort]);
    }

    // limit drive again
   if(rEncDrive > 100)
      rEncDrive = 100;
    if(rEncDrive < -100)
      rEncDrive = -100;

		// send to motor

		rightDriveRamp(rEncDrive);

		lastrEncError = rEncError;
    }

		// Don't hog cpu
		wait1Msec(dontHog);
	}
}

task gyroController()
{
	while(true)
	{
    if(gyroPID == true)
    {
		// Read the sensor value and scale
		gyroCurrentValue = gyroCoeff * abs(SensorValue[gyroPort]);

		// calculate error
		gyroError =  gyroRequestedValue - gyroCurrentValue;

		// calculate drive
		gyroP = (gyro_Kp * gyroError);

		gyroD = gyroError - lastGyroError;
		gyroDF = (gyro_Kd * gyroD);

		gyroDrive = gyroP + gyroDF;

		// limit drive
		if(gyroDrive > 127)
			gyroDrive = 127;
		if(gyroDrive < (-127))
			gyroDrive = (-127);

		// send to motor

		leftDriveRamp(direction * gyroDrive * gyroDriveCoeff);
		rightDriveRamp(-direction * gyroDrive * gyroDriveCoeff);

		lastGyroError = gyroError;

		// Don't hog cpu
		wait1Msec(dontHog);
  }
	}
}
//#endregion

//#region Main Drive Task
task unityDrive()
{
  //SensorType[gyro]= sensorNone; //Fix *most* gyro drift
  /*wait1Msec(250);
  SensorType[gyro]=sensorGyro;
  wait1Msec(250);*/

  startTask(lEncController); //start drivestraight tasks
  startTask(rEncController);

  startTask(gyroController); //start gyro turn task

  driveEncoderPID = false; //disable drivestraight tasks
  gyroPID = false; //disable turn task

  while(true)
  {
  //#region setup
      if(newDriveCommand == true)
      {
        driveMode = funcDriveMode; //updates values used in the task
        direction = funcDirection;
        driveModifier = funcDriveModifier;

        SensorValue[lEncPort] = 0;
        SensorValue[rEncPort] = 0;

        SensorValue[gyroPort] = 0;

        newDriveCommand = false; //These values are no longer new
        gyroPID = false; //disables turn PID
        driveEncoderPID = true; //allows encoder PID tasks to run

      }

  //#endregion

  //#region actions
    //drive straight
    if(driveMode == 0)
    {
      gyroPID = false; //disables turn PID
      driveEncoderPID = true; //enables encoder PID

      if(driveModifier == 0) //PID position locking
      {
        lEncRequestedValue = 0; //sets PID tasks to not allow the robot to move
        rEncRequestedValue = 0;
      }
      else //normal drivestraight
      {
        int distance = countsToInches(driveModifier) * direction;

        lEncRequestedValue = distance;
        rEncRequestedValue = distance;

      }
    }

    //Gyro turn
    if(driveMode == 1)
    {
      driveEncoderPID = false; //disables encoder PID
      gyroPID = true; //enables turn PID
      gyroRequestedValue = (driveModifier);
    }

    //move freely
    if(driveMode == 2)
    {
      driveEncoderPID = false; //stops drive PID tasks
      gyroPID = false; //stops gyro PID tasks
    }
  //#endregion
  wait1Msec(dontHog);
  }
}
//#endregion
//</editor-fold>

#endif
