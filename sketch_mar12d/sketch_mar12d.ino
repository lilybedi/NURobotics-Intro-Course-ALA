// Standby pin is used to turn on and off the motor driver
const int STBY = 3;
// PWM Channel A and B are used to control the speed of the motors
const int PWMA = 5;
const int PWMB = 6;
// Input Channels A and B are used to control the direction of the motors
const int AIN1 = 7;
const int BIN1 = 8;

// Line Tracker Sensor Pins 
const int LTleftSensor = A2;
const int LTmiddleSensor = A1;
const int LTrightSensor = A0;

/**
 * @brief Moves the robot forward with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void forward(int carSpeed) {
    // Enable the motor driver
    digitalWrite(STBY, HIGH);
    // Set the direction of the motors
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);

    // Write speed to 'A' and 'B' MotorGroups
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Moves the robot in a swing turn to the left. A swing turn is when only one side of the robot's drivebase is powered.
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void swingTurnLeft(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);
    analogWrite(PWMA, 0.25 * carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Moves the robot in a swing turn to the right. A swing turn is when only one side of the robot's drivebase is powered.
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void swingTurnRight(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, 0.25 * carSpeed);
}

/**
 * @brief Moves the robot backwards with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void back(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Turns the robot left with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void turnLeft(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, LOW);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Turns the robot right with the given speed
 *
 * @param carSpeed an integer representing the car's speed.
 * This value is capped at 255 and passing in a higher value will
 * cap at 255
 */
void turnRight(int carSpeed) {
    digitalWrite(STBY, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, HIGH);
    analogWrite(PWMA, carSpeed);
    analogWrite(PWMB, carSpeed);
}

/**
 * @brief Stops the robot's drive motors.
 */
void stop() {
    digitalWrite(STBY, LOW);
}

void setup() {
    // Configure all of these pins as outputs
    pinMode(STBY, OUTPUT);
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(BIN1, OUTPUT);

    // Line sensor on the 4.0 is analog so no need to use pinMode

    // Start serial monitor
    Serial.begin(9600);
}

void turnNinetyDegrees() {
    turnRight(110);
    delay(655);
    stop();
}

void square() {
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {        
            forward(100);
            delay(2000);
            turnNinetyDegrees();
        } else {
            forward(50);
            delay(4000);
            turnNinetyDegrees();
        }
    }
}

void circle() {
    swingTurnRight(100);
    delay(250);
}

void printSensorValues() {
    Serial.println("L: ");
    Serial.println(analogRead(LTleftSensor));
    Serial.println("M: ");
    Serial.println(analogRead(LTmiddleSensor));
    Serial.println("R: ");
    Serial.println(analogRead(LTrightSensor));
    delay(1000);
}

// Track and follow a dark line
void loop() {
    // Once you have tuned the sensors, you can use the movement functions
    // to move your robot!
    // square();
    circle();

    // Challenge: Have your robot only track lines for 10 seconds, then stop

    // Challenge: How will your robot handle intersections?
}
