#include <Servo.h>

Servo myServoT;
Servo myServoI;
Servo myServoM;
Servo myServoR;
Servo myServoP;
  // create a servo object

void open(){
  myServoP.attach(8);  // attach servo to pin 9
  myServoP.write(90);
  myServoR.attach(9);  // attach servo to pin 9
  myServoR.write(90);
  myServoM.attach(10);  // attach servo to pin 9
  myServoM.write(50);
  myServoI.attach(11);  // attach servo to pin 9
  myServoI.write(90);
  myServoT.attach(12);  // attach servo to pin 9
  myServoT.write(90);
}

void close(){
  myServoP.attach(8);  // attach servo to pin 9
  myServoP.write(170);
  myServoR.attach(9);  // attach servo to pin 9
  myServoR.write(150);
  myServoM.attach(10);  // attach servo to pin 9
  myServoM.write(180);
  myServoI.attach(11);  // attach servo to pin 9
  myServoI.write(200);
  myServoT.attach(12);  // attach servo to pin 9
  myServoT.write(150);
}

void setup() {
}

void loop() {
  open();
  delay(5000);
  close();
  delay(5000);

}