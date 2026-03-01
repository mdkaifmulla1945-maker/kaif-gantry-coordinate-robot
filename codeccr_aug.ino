// XYZ Cartesian Pick and Place Robot - Basic Control Code

// Define stepper motor pins

// X Axis Motor
#define X_STEP 2
#define X_DIR 5

// Y Axis Motor
#define Y_STEP 3
#define Y_DIR 6

// Z Axis Motor
#define Z_STEP 4
#define Z_DIR 7

// Motor step delay (controls speed)
int motorSpeedDelay = 800;

void setup() {

  pinMode(X_STEP, OUTPUT);
  pinMode(X_DIR, OUTPUT);

  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);

  pinMode(Z_STEP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
}

// Function to move stepper motor
void moveMotor(int stepPin, int dirPin, int steps, bool direction) {

  digitalWrite(dirPin, direction);

  for(int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(motorSpeedDelay);

    digitalWrite(stepPin, LOW);
    delayMicroseconds(motorSpeedDelay);
  }
}

// Pick and place sequence
void loop() {

  // Move to object position
  moveMotor(X_STEP, X_DIR, 1000, HIGH);
  moveMotor(Y_STEP, Y_DIR, 800, HIGH);

  // Lower gripper (Z axis down)
  moveMotor(Z_STEP, Z_DIR, 600, LOW);

  delay(1000);

  // Lift object
  moveMotor(Z_STEP, Z_DIR, 600, HIGH);

  // Move to destination
  moveMotor(X_STEP, X_DIR, 1000, LOW);
  moveMotor(Y_STEP, Y_DIR, 800, LOW);

  // Release object position
  delay(2000);
}