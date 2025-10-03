#include <Servo.h>

Servo myServoT;
Servo myServoI;
Servo myServoM;
Servo myServoR;
Servo myServoP;

const int AD8232_PIN = A0;
const int threshold = 260; // Threshold value for muscle activation

// Moving average variables
const int numReadings = 10; // Number of readings for the moving average
int readings[numReadings];   // Array to store readings
int readIndex = 0;           // Index of the current reading
int total = 0;               // Sum of all readings
int average = 0;             // Moving average

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(AD8232_PIN, INPUT); // Set AD8232 output as input
  
  // Attach servos to respective pins
  myServoP.attach(8);
  myServoR.attach(9);
  myServoM.attach(10);
  myServoI.attach(11);
  myServoT.attach(12);

  // Initialize readings array
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
  
  open();  // Start with fingers open
}

void open() {
  myServoP.write(90);
  myServoR.write(90);
  myServoM.write(90);
  myServoI.write(90);
  myServoT.write(60);
}

void close() {
  myServoP.write(150);
  myServoR.write(150);
  myServoM.write(190);
  myServoI.write(150);
  myServoT.write(150);
}

void loop() {
  // Read the AD8232 signal
  int signalValue = analogRead(AD8232_PIN);

  // Update moving average buffer
  total -= readings[readIndex];     // Subtract the oldest reading from the total
  readings[readIndex] = signalValue; // Add the new reading to the buffer
  total += readings[readIndex];     // Add the new reading to the total
  readIndex = (readIndex + 1) % numReadings; // Move to the next index
  average = total / numReadings;    // Calculate the moving average

  // Print the moving average for debugging
  Serial.print("Moving Average: ");
  Serial.println(average);

  // Check if the moving average exceeds the threshold
  if (average > threshold) {
    Serial.println("Curling fingers...");
    delay(5000);
    close();  // Curl fingers when average exceeds threshold
  } else {
    Serial.println("Opening fingers...");
    open();   // Open fingers when average is below threshold
  }

  delay(100);  // Small delay for responsiveness
}

