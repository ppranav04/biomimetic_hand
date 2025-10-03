#include <Servo.h>

Servo myServoT;
Servo myServoI;
Servo myServoM;
Servo myServoR;
Servo myServoP;

const int AD8232_PIN = A0; // Analog pin for AD8232 output
int signalValue = 0;



void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(AD8232_PIN, INPUT); // Set AD8232 output as input
}

void open(){
  
  myServoP.attach(8);  // attach servo to pin 9
  myServoP.write(90);
  myServoR.attach(9);  // attach servo to pin 9
  myServoR.write(90);
  myServoM.attach(10);  // attach servo to pin 9
  myServoM.write(90);
  myServoI.attach(11);  // attach servo to pin 9
  myServoI.write(90);
  myServoT.attach(12);  // attach servo to pin 9
  myServoT.write(60);
}

void close(){
  myServoP.attach(8);  // attach servo to pin 9
  myServoP.write(150);
  myServoR.attach(9);  // attach servo to pin 9
  myServoR.write(150);
  myServoM.attach(10);  // attach servo to pin 9
  myServoM.write(190);
  myServoI.attach(11);  // attach servo to pin 9
  myServoI.write(150);
  myServoT.attach(12);  // attach servo to pin 9
  myServoT.write(150);
}


void loop() {
  signalValue = analogRead(AD8232_PIN);
  Serial.println(signalValue);
  open();
  // Optional: Set a threshold to detect muscle activation
  if (signalValue > 300) { // Adjust threshold as needed
    close();
    
  }

  delay(500);  // Adjust delay as necessary for smoother signal reading
}
