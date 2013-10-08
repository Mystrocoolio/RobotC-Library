#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)

void drive(int left,int right){
	motor[rightMotor] = right;
  motor[leftMotor] = left;
}

void moveForward(float rotation, int speed) {
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[leftEncoder] < rotation*360 && SensorValue[leftEncoder] < rotation*360){

  }

	drive(0,0);
}

void moveBackward(float rotation, int speed){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[leftEncoder] < -1*	rotation*360){
    drive(-1*speed,-1*speed);
  }

	drive(0,0);
}

void moveLeftPoint(float rotation, int speed) {
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[rightEncoder] < rotation*360){
    drive(-1*speed,speed);
  }

	drive(0,0);
}

void moveRightPoint(float rotation, int speed) {
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[leftEncoder] < rotation*360){
    drive(speed,-1*speed);
  }

	drive(0,0);
}

void moveLeftSwing(float rotation, int speed) {
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[rightEncoder] < rotation*360){
    drive(0,speed);
  }

	drive(0,0);
}

void moveRightSwing(float rotation, int speed) {
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;

  while(SensorValue[leftEncoder] < rotation*360){
    drive(speed,0);
  }

	drive(0,0);
}

void wait(int time) {
	drive(0,0);
	wait1Msec(time);
}

void dance(int reps) {
	for(int i = 1; i <=reps; i++) {
		moveLeftPoint(.25,110);
		wait(800);
		moveRightPoint(.25,110);
		wait(800);
		moveRightPoint(.25,110);
		wait(800);
		moveLeftPoint(.25,110);
		wait(800);
	}
}


task main() {
	wait1Msec(2000);
  dance(5);
}
