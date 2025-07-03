
#include <Stepper.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define STEPS 2048  // Steps per revolution for 28BYJ-48

Stepper stepper(STEPS, 8, 10, 9, 11);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Codes (0x27 or 0x3F)

const int button1 = 2; // Run motor for 1 sec (+1 click)
const int button2 = 3; // Run motor for 2 sec (+2 clicks)
const int button3 = 4; // Rotate +2048 for 1 sec
const int button4 = 5; // Reset to it's original
const int flowSensor = 6; // Flow meter sensor
const int ledG = 7; // The device is taken power
const int led1 = 12; // LED 1 (On at 2 clicks)
const int led2 = 13; // LED 2 (On at 4 clicks)
const int buzzer = 1; // Buzzer (On at 5 clicks)

volatile int pulseCount = 0;
float flowRate;
int clickCounter = 0; // Click counter

void IRAM_ATTR countPulse() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600);
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(flowSensor, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(flowSensor), countPulse, RISING);

  lcd.begin();
  //lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Infusion Bumb ON");
}

void loop() {
  digitalWrite(ledG, HIGH);

  if (digitalRead(button1) == 1 ) {
    clickCounter += 1; // Increment by 1
    stepper.setSpeed(13);
    stepper.step(-2048); // Puch
    delay(1000);
    stepper.setSpeed(0);
  }

  if (digitalRead(button2) == 1 ) {
    clickCounter += 2; // Increment by 2
    stepper.setSpeed(13);
    stepper.step(-2048); // Puch
    delay(2000);
    stepper.setSpeed(0);
  }

  if (digitalRead(button3) == 1 ) {
    stepper.setSpeed(13);
    stepper.step(2048); // Pull
    delay(1000);
    stepper.setSpeed(0);
  }

  if (digitalRead(button4) == 1 ) {
    stepper.setSpeed(13);
    stepper.step(2048); // Pull for clicks sec
    delay(1000*clickCounter);
    stepper.setSpeed(0);
    clickCounter = 0 ;
  }

  // Turn LEDs and Buzzer ON based on click count
  if (clickCounter >= 2) digitalWrite(led1, HIGH);
  if (clickCounter >= 4) digitalWrite(led2, HIGH);
  if (clickCounter >= 5) digitalWrite(buzzer, HIGH);

  // Flow Meter Calculation
  float calibrationFactor = 4.5; // Adjust based on your sensor
  flowRate = (pulseCount / calibrationFactor); // Calculate flow rate
  pulseCount = 0; // Reset counter

  // Display on Serial Monitor & LCD
  Serial.print("Flow Rate: ");
  Serial.print(flowRate);
  Serial.println(" L/min");

  lcd.setCursor(0, 1);
  lcd.print("Flow: ");
  lcd.print(flowRate);
  lcd.print(" L/min ");

  delay(500); // Update every second
}
