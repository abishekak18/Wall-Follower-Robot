// ===== IR Sensors =====
int irLeft  = A0;
int irFront = A1;

// ===== Motor Driver Pins =====
// Left Motor
int enA = 9;
int in1 = 8;
int in2 = 7;

// Right Motor
int enB = 10;
int in3 = 6;
int in4 = 5;

// ===== Variables =====
int leftValue;
int frontValue;

int threshold = 450;

// ===== PWM Speeds =====
int forwardSpeed = 50;
int turnSpeed    = 55;
int reverseSpeed = 60;

// ===== Turn duration (IMPORTANT) =====
int turnDelay = 500;   // ms (adjust 400–700 if needed)

void setup() {
  pinMode(irLeft, INPUT);
  pinMode(irFront, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  leftValue  = analogRead(irLeft);
  frontValue = analogRead(irFront);

  bool leftObstacle  = leftValue  < threshold;
  bool frontObstacle = frontValue < threshold;

  // ===== NO OBSTACLE =====
  if (!leftObstacle && !frontObstacle) {
    moveForward();
  }

  // ===== BOTH SENSORS BLOCKED =====
  else if (leftObstacle && frontObstacle) {
    stopRobot();
    delay(200);
    moveBackwardWithDelay();
  }

  // ===== ONLY FRONT SENSOR BLOCKED =====
  else if (frontObstacle && !leftObstacle) {
    stopRobot();
    delay(150);
    turnLeftTimed();   // 🔥 TIMED TURN
  }

  // ===== ONLY LEFT SENSOR BLOCKED =====
  else if (leftObstacle && !frontObstacle) {
    stopRobot();
    delay(150);
    turnRightTimed();  // 🔥 TIMED TURN
  }

  delay(30);
}

// ===== MOTOR FUNCTIONS =====

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, forwardSpeed);
  analogWrite(enB, forwardSpeed);
}

void moveBackwardWithDelay() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, reverseSpeed);
  analogWrite(enB, reverseSpeed);

  delay(3000);   // 3 seconds reverse

  stopRobot();
}

// 🔁 TIMED LEFT TURN
void turnLeftTimed() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, 0);
  analogWrite(enB, turnSpeed);

  delay(turnDelay);   // 🔥 gives time to actually turn

  stopRobot();
}

// 🔁 TIMED RIGHT TURN
void turnRightTimed() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  analogWrite(enA, turnSpeed);
  analogWrite(enB, 0);

  delay(turnDelay);   // 🔥 gives time to actually turn

  stopRobot();
}

void stopRobot() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  analogWrite(enA, 0);
  analogWrite(enB, 0);
}