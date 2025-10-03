const int AD8232_PIN = A0; // Analog pin for AD8232 output
int signalValue = 0;

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(AD8232_PIN, INPUT); // Set AD8232 output as input
}

void loop() {
  signalValue = analogRead(AD8232_PIN);
  Serial.println(signalValue);

  // Optional: Set a threshold to detect muscle activation
  if (signalValue > 500) { // Adjust threshold as needed
    //Serial.println("Muscle activated!");
    // Add code here to control the myoelectric arm
  }

  delay(100);  // Adjust delay as necessary for smoother signal reading
}
