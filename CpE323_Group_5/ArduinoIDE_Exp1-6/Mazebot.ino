//Castillo, Joaquin Iverson M.
const int motorPin = 9;      // Pin connected to the base of the transistor
const int maxSpeed = 255;    // Maximum motor speed (0-255)
const int minSpeed = 0;     // Slowest motor speed (0-255)
const int duration = 10000;   // Duration of each speed (in milliseconds)

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Rotate at maximum speed for 10 seconds
  motorSpeed(maxSpeed);
  delay(duration);

  // Reduce speed for 3 seconds
  motorSpeed(minSpeed);
  delay(3000);
}

void motorSpeed(int speed) {
  analogWrite(motorPin, speed);
} 
