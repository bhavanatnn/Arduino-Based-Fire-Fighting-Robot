#include <Servo.h>

// Single flame sensor
#define FLAME_SENSOR A0

// Motor driver pins
#define MOTOR_L1 5
#define MOTOR_L2 6
#define MOTOR_R1 9
#define MOTOR_R2 10

// Relay for water pump (LOW–trigger relay)
#define RELAY_PIN 7
#define RELAY_ON  LOW     // RED light ON, pump ON
#define RELAY_OFF HIGH    // GREEN light ON, pump OFF

// Servo pin
#define SERVO_PIN 3

// Buzzer pin
#define BUZZER 8

Servo waterServo;

// Flame sensor threshold
#define FIRE_DETECTED_THRESHOLD 800

void setup() {
    Serial.begin(9600);

    // Motor pins
    pinMode(MOTOR_L1, OUTPUT);
    pinMode(MOTOR_L2, OUTPUT);
    pinMode(MOTOR_R1, OUTPUT);
    pinMode(MOTOR_R2, OUTPUT);

    // Relay output
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, RELAY_OFF);  // Pump OFF at startup

    // Buzzer
    pinMode(BUZZER, OUTPUT);
    digitalWrite(BUZZER, LOW);

    // Servo
    waterServo.attach(SERVO_PIN);
    waterServo.write(90);

    // Flame sensor
    pinMode(FLAME_SENSOR, INPUT);

    Serial.println("🔥 Fire Fighting Robot Ready...");
}

void loop() {
    int flameValue = analogRead(FLAME_SENSOR);

    Serial.print("Flame Sensor Value: ");
    Serial.println(flameValue);

    if (flameValue < FIRE_DETECTED_THRESHOLD) {
        Serial.println("🔥 Fire Detected!");

        digitalWrite(BUZZER, HIGH);  // Beep
        moveForward();
        delay(1200);                 // Move toward fire
        stopMotors();
        digitalWrite(BUZZER, LOW);   // Stop beep

        extinguishFire();
    }
    else {
        Serial.println("✔ No Fire Detected.");
        stopMotors();
        deactivateWaterPump();
        digitalWrite(BUZZER, LOW);
    }

    delay(200);
}

// Move forward
void moveForward() {
    digitalWrite(MOTOR_L1, HIGH);
    digitalWrite(MOTOR_L2, LOW);
    digitalWrite(MOTOR_R1, HIGH);
    digitalWrite(MOTOR_R2, LOW);
}

// Stop motors
void stopMotors() {
    digitalWrite(MOTOR_L1, LOW);
    digitalWrite(MOTOR_L2, LOW);
    digitalWrite(MOTOR_R1, LOW);
    digitalWrite(MOTOR_R2, LOW);
}

// Extinguish fire
void extinguishFire() {
    Serial.println("🚰 Pump ON! Extinguishing Fire...");
    digitalWrite(RELAY_PIN, RELAY_ON);  // Pump ON (RED LIGHT ON)

    // Sweep servo left-right
    for (int pos = 60; pos <= 120; pos += 5) {
        waterServo.write(pos);
        delay(80);
    }
    for (int pos = 120; pos >= 60; pos -= 5) {
        waterServo.write(pos);
        delay(80);
    }

    delay(2000);

    deactivateWaterPump();
}

// Turn OFF pump
void deactivateWaterPump() {
    digitalWrite(RELAY_PIN, RELAY_OFF);  // Pump OFF (GREEN LIGHT ON)
    waterServo.write(90);
    Serial.println("🟢 Pump OFF.");
}
