# Home-Security-TinkerCAD
A tinkercad simulation for home security using Arduino UNO

The below project demonstrates a simulation of home security done using Tinkercad

Components:


![image](https://user-images.githubusercontent.com/69236709/133388485-5bd5804c-db66-4e18-bc6d-f8e7be7c8693.png)

The security of any home is a crucial component of an individual's safety. There have been several incidents of theft in residences, as well as fires breaking out in housing units. As a result, we devised an IoT-based solution to address this issue.

A gas sensor detects and measures the concentration of hazardous and explosive gases. If any gas is detected, the user at home is notified. An ultrasonic sensor detects any burglar attempting to break in via the door and buzzes using a peizo buzzer. A force sensor is placed just inside the main door of the house to detect any intruders who have entered.

Circuit:

![Copy of Smart Home Security System](https://user-images.githubusercontent.com/69236709/133388723-8b2962cc-b1a1-4c85-b51d-b721f06c3ebd.png)


Connections:

*BUZZER*
1. P1 to digital pin 12
2. P2 to GND

*GAS_SENSOR*
1. Side A

 * P1 to analog pin A5
 * P2 to GND
 * P3 to Resistor

2. Side B

  * P1 to 5V
  * P2 to 5V
  * P3 to 5V

*ULTRASONIC SENSOR*
1. TRIG_PIN to digital pin 8
2. SECHO_PIN to digital pin 9
3. GND to GND
4. VCC to 5V

*FORCE SENSOR*
1. P1 to analog pin A0
2. P2 to digital pin GND

*LCD*

 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

The complete code can be found in home_security_code.cpp
