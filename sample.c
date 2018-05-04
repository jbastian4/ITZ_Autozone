//SAMPLE code
//--------------------------user_control----------------------------------//
if(vexRT[Btn8D] == 1)
	buttonflip=0;
else if(vexRT[Btn8R] == 1)
	buttonflip=1;
if(buttonflip==1){
	if (SensorValue[barPot]>400 ){
		motor[ barMot ] = -127;}
	else{
		motor[ barMot ] = -15;}
		}
else if(buttonflip==0){
		if (SensorValue[barPot]< 1885){
		motor[ barMot ] = 127;}
	else{
		motor[ barMot ] = 15;}
	}// running this code in user control lets the driver press two diffrent buttons and ahave a motor run until it is outside
	// a limit
	if(vexRT[Btn7D] == 0)
		togglewait=true;
	if(vexRT[Btn7D] == 1 && togglewait==true && buttontoggle==1){
		togglewait=false;
		buttontoggle=0;
		// right here you can set a PID request
	}
	else if(vexRT[Btn7D] == 1 && togglewait==true && buttontoggle==0){
		togglewait=false;
		buttontoggle=1;
		// right here you can set a PID request
	} // this toggle runs on a single button and the button must be let up prior to it changing again


//--------------------------end_user_control-------------------------------//
//---------------------random_usefull_functions----------------------------//
void setMotors(int power)
{
	motor[rMot] = power;
	motor[lMot] = power;
}// this code can define multiple motors in one void
setMotors(100);//call
//---------------------end_random_usefull_functions------------------------//
//-------------------------------PID---------------------------------------//
static float  sample_Kp = 0.5;
static float  sampleRequestedValue;
static float  sample_Kd = 1.2;

float sampleD;
float sampleP;
float lastsampleError;
float sampleDF;

float  sampleSensorCurrentValue;
float  sampleError;
float  sampleDrive;


task sampleController()
{

	while( true )
	{
		// Read the sensor value and scale
		sampleSensorCurrentValue = SensorValue[ samplePot ];

		// calculate error
		sampleError =  sampleRequestedValue - sampleSensorCurrentValue;

		// calculate drive
		sampleP = (sample_Kp * sampleError);

		sampleD = sampleError - lastsampleError;
		sampleDF = (sample_Kd * sampleD);

		sampleDrive = sampleP + sampleDF;

		// limit drive
		if( sampleDrive > 127 )
			sampleDrive = 127;
		if( sampleDrive < (-127) )
			sampleDrive = (-127);

		// send to motor
		motor[ rtsampleMot ] = sampleDrive;
		motor[ ltsampleMot ] = sampleDrive;
		lastsampleError = sampleError;

		// Don't hog cpu
		wait1Msec( 25 );
	}
}



void Request(goalPos goal, bool waitforcompletion = false, int modifier = 0)
{
  RequestedValue = Val[goal] + modifier;

	if(waitforcompletion)
		while(fabs(sampleSensorCurrentValue - RequestedValue) > 60)
		{}
}/*if you use this code to set your PID requests, there is the option to have the
code cycle at the end waiting for the request to be fufilled withina spicific error*/
