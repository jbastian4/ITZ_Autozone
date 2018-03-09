#ifndef unity_Drive
#define unity_Drive
//<editor-fold Variables
//#region User Variables
#define gyroPort in2
#define lEncPort dgtl1
#define rEncPort dgtl3

#define lDrivePort1 port8
#define lDrivePort2 port9
#define lDrivePort3 port10
#define rDrivePort1 port1
#define rDrivePort2 port2
#define rDrivePort3 port3

float wheelDiameter = 3.25;

int dontHog = 25; //don't hog cpu wait time

int stopError = 80; //allowed variation distance for drivestraight stop (inches)
int stopTime = 150;

int driveStraightError = 50;

int gyroCoeff = 1;
int gyroDriveCoeff = -1;

//Encoder PID Values
static float  lEnc_Kp = 0.6;
static float  lEnc_Kd = 0.03;

static float  rEnc_Kp = 0.6;
static float  rEnc_Kd = 0.03;

//Gyro PID Values
static float  gyro_Kp = 0.4; //.08
static float  gyro_Kd = 1; //.2

//Drive ramp values
int rampTime = 1;
int normRampSpeed = 9; //was 7
int hiRampSpeed = 35; //was 30
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
float  turnError = 60;
//#endregion
//</editor-fold>

//<editor-fold Functions
//#region Drive Functions
void drivewaity(int distance)
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
    //int ticks = fabs(countsToInches(distance));
  	//while(fabs(SensorValue[lEnc]) <= ticks - stopError){}
    drivewaity(distance);
  }
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
  	while(fabs(SensorValue[gyroPort]) <= fabs(degrees) - turnError){}
    wait1Msec(stopTime*2);
  }

}
//#endregion
//#region set motor functions
void setLDriveMotors(int power)
{
	motor[lDrivePort1] = power;
	motor[lDrivePort2] = power;
  motor[lDrivePort3] = power;
}
void setRDriveMotors(int power)
{
	motor[rDrivePort1] = power;
	motor[rDrivePort2] = power;
  motor[rDrivePort3] = power;
}
//#endregion
//#region Ramp Functions
void leftDriveRamp(int leftPowerReq) //ramping
{
if(leftPower >= 30)
{
	if(leftPowerReq > leftPower)
	{
		leftPower += normRampSpeed;
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
		leftPower -= normRampSpeed;
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
		leftPower += hiRampSpeed;
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
		leftPower += normRampSpeed;
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
  setLDriveMotors(leftPower);

wait1Msec(rampTime);
}

void rightDriveRamp(int rightPowerReq) //ramping
{
  if(rightPower >= 30)
  {
  	if(rightPowerReq > rightPower)
  	{
  		rightPower += normRampSpeed;
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
  		rightPower -= normRampSpeed;
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
  		rightPower += hiRampSpeed;
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
  		rightPower += normRampSpeed;
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
    setRDriveMotors(rightPower);

  wait1Msec(rampTime);
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
        lEncDrive -= 45;
      else if(SensorValue[lEncPort] < (SensorValue[rEncPort] - driveStraightError) && direction == -1)
        lEncDrive += 10;
    }

    // limit drive again
		if(lEncDrive > 127)
			lEncDrive = 127;
		if(lEncDrive < -127)
			lEncDrive = -127;

		// send to motor
    setLDriveMotors(lEncDrive);
		//leftDriveRamp(lEncDrive);

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
		if(rEncDrive > 100)
			rEncDrive = 100;
		if(rEncDrive < -100)
			rEncDrive = -100;

    //correct for drivestraight
    if(isDriving == true)
    {
      if(SensorValue[rEncPort] > (SensorValue[lEncPort] + driveStraightError) && direction == 1)
        rEncDrive -= 45;
      else if(SensorValue[rEncPort] < (SensorValue[lEncPort] - driveStraightError) && direction == -1)
        rEncDrive += 10;
    }

    // limit drive again
    if(rEncDrive > 127)
      rEncDrive = 127;
    if(rEncDrive < -127)
      rEncDrive = -127;

		// send to motor
    setRDriveMotors(rEncDrive);
		//rightDriveRamp(rEncDrive);

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
		if(gyroDrive > 80)
			gyroDrive = 80;
		if(gyroDrive < (-80))
			gyroDrive = (-80);

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
  /*SensorType[gyro]= sensorNone; //Fix *most* gyro drift
  wait1Msec(250);
  SensorType[gyroPort]=sensorGyro;
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

        clearTimer(T1);
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
