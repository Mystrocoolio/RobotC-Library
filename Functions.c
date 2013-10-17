#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)

// Feel free to rename these in the "Motors and Sensors Setup" window under "Robot" BUT BEWARE!!
// 	You would need to change their names in almost every function below (your call tho)

int InToDegrees(float in) {
	// CHANGE THIS TO MATCH YOUR ROBOT!!
	return in * 000; // Replace 000 with your robot's unique degree per inch
			 // Like if your robot goes 11 inches in one full rotation, put in "(360/11)"
}

void drive(int left,int right){
	// CHANGE THIS TO MATCH YOUR ROBOT!!
	// Since every robot is different, i made this function so as long as you tell it how to drive
	// 	the left ans right side, all of the later functions wont have to be changed
	motor[rightMotor] = right;
  	motor[leftMotor] = left;
}

void moveForward(int degree, int speed) {
	// goes forward for given degrees at given speed
	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	
  	drive(speed,speed);

  	while(SensorValue[leftEncoder] < degree){
		
  	}

	drive(0,0);
}

void moveBackward(int degree, int speed){
	// goes backward for given degrees at given speed
	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  
    	drive(-1*speed,-1*speed);

  	while(SensorValue[leftEncoder] < -1*degree){
  		
  	}

	drive(0,0);
}

// ( ( (BTW) ) )
// A point turn is when both sides run at oposite speeds to turn about the center of the robot
// A swing turn is when one sides runs as the other doesnt to turn about the the stationary side's front wheel

void moveLeftPoint(int degree, int speed) {
	// Does a point turn left for given degrees at given speed
	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	
  	drive(-1*speed,speed);

  	while(SensorValue[rightEncoder] < degree){
  	}

	drive(0,0);
}

void moveRightPoint(int degree, int speed) {
	// Does a point turn right for given degrees at given speed
	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	
  	drive(speed,-1*speed);

  	while(SensorValue[leftEncoder] < degree){
    		
  	}

	drive(0,0);
}

void moveLeftSwing(int degree, int speed) {
	// Does a swing turn left for given degrees at given speed
	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	
    	drive(0,speed);

  	while(SensorValue[rightEncoder] < degree){
  	}
		
	drive(0,0);
}

void moveRightSwing(int degree, int speed) {
	// Does a swing turn right for given degrees at given speed
	SensorValue[rightEncoder] = 0;
  	SensorValue[leftEncoder] = 0;
  	
  	drive(speed,0);

  	while(SensorValue[leftEncoder] < degree){
    		
  	}

	drive(0,0);
}

void stopSec(float time) {
	// simply stops the motors and waits for the given amount of seconds
	// I though seconds whould be better to work with than milliseconds, and feel free to put in decimals
	drive(0,0);
	wait1Msec(time*1000);
}

void dance(int reps) {
	// Just something to test the functions and provide amusement, totaly useless otherwise
	for(int i = 1; i <=reps; i++) {
		moveLeftPoint(90,110);
		stopSec(.8);
		moveRightPoint(90,110);
		stopSec(.8);
		moveRightPoint(90,110);
		stopSec(.8);
		moveLeftPoint(90,110);
		stopSec(.8);
	}
}


task main() {
	
}
