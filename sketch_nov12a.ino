#include <LiquidCrystal.h>

const int irSensorPin = 2;       // Digital IR sensor input pin
const int buzzerPin = 3;          // Buzzer output pin
const int relayPin = 11;           // Relay output pin
const int trig = 4; 

const int eyeBlinkThreshold = LOW;  // Adjust this value based on IR sensor
const int alcoholThreshold = 500;   // Adjust this threshold based on alcohol sensor
int a=0;
LiquidCrystal lcd(10, 9, 8, 7, 6, 5);  // Pin configuration for 16x2 LCD

void setup() {
  Serial.begin(9600);
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(trig, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Eye Blink &");
  lcd.setCursor(0, 1);
  lcd.print("Alcohol Detect");
  digitalWrite(trig, HIGH);
}

void loop() {
  int irSensorValue = digitalRead(irSensorPin);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IR: ");
  lcd.print(irSensorValue);


  // Eye blink detection
  if (irSensorValue == eyeBlinkThreshold) {
    a=a+1;
    // Blink detected
    lcd.clear();
    lcd.print("Eye Blink Detected");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, HIGH);  // Lock the relay
    delay(2000);  // Lock for 2 seconds
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW);   // Release the relay
  }
if(a==5)
{
 digitalWrite(trig, LOW); 
 a=0;
 delay(3000);
 digitalWrite(trig, HIGH); 
}
  

  delay(1000);  // Adjust the delay based on your requirements
}
