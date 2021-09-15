// include the library code:
#include <LiquidCrystal.h>

#define BUZZER_PIN 12
#define GAS_SENSOR_PIN A5
#define SONAR_TRIG_PIN 8
#define SONAR_ECHO_PIN 9
#define FORCE_PIN A0

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int gasSensorVal;
boolean intruder;
int force;

void setup() {

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SONAR_TRIG_PIN, OUTPUT);
    pinMode(SONAR_ECHO_PIN, INPUT);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Security System!");
    Serial.begin(9600);
}

void loop() {
    checkSensors();
    notify();
    delay(1000);

}

//---------------- Functions -------------------

void checkSensors() {
    gasSensorVal = readGasMeasurement();
    intruder = checkDoor();
    force = readForce();
}

void notify() {
    lcd.setCursor(0, 1);

    if (gasSensorVal > 50) { //There is a gas leak

        lcd.print("Gas Leak!   ");
        Serial.println("Gas Leak!");
        buzzerRun(2);
    }
    else if (intruder) { //There is a intruder in front of the door

        lcd.print("Check Front Door!");
        Serial.println("We have a visitor, Check front door!   ");
        buzzerRun(2);
    }
    else if (force > 0.5) { //There is an intruder and has stepped inside the house

        Serial.println("intruder inside!");
        lcd.print("intruder inside!");
        buzzerRun(2);
    }
    else {
        lcd.print("No Problems!");
        Serial.println("No Problems!");
    }
}

boolean checkDoor() {
    float distance = findSonarDistance();
    if (distance < 100) {
        return true;
    }
    else
        return false;
}

//Run buzzer buzzer for a specific time duration (seconds)
void buzzerRun(int duration) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(duration * 1000);
    digitalWrite(BUZZER_PIN, LOW);
}

//Start the buzzer
void buzzerStart() {
    digitalWrite(BUZZER_PIN, HIGH);
}

//Stop the buzzer
void buzzerStop() {
    digitalWrite(BUZZER_PIN, LOW);
}

//Input from Gas Sensor
int readGasMeasurement() {
    return analogRead(GAS_SENSOR_PIN);
}
//Input from Force Sensor
float readForce() {
    return analogRead(FORCE_PIN);
}

//Distance Calculation from Ultrasonic Sensor
float findSonarDistance()
{
    float distance;
    int duration;

    //Make the pulse
    digitalWrite(SONAR_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(SONAR_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(SONAR_TRIG_PIN, LOW);

    //Reads a pulse (either HIGH or LOW) on a pin.
    duration = pulseIn(SONAR_ECHO_PIN, HIGH);

    distance = (float)duration * (0.0343) / 2;

    return distance;
}
