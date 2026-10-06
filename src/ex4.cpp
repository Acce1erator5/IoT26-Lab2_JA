#include "Arduino.h"

const int BUTTON_PIN = 25;
const int LED_RED    = 26;
const int LED_GREEN  = 27;
const int LED_YELLOW = 12;
const int LED_BLUE   = 14;


int pressCounter = 0;    
bool lastButtonState = HIGH; 

void updateLEDs() {
  digitalWrite(LED_RED,    (pressCounter >= 1) ? HIGH : LOW);
  digitalWrite(LED_GREEN,  (pressCounter >= 2) ? HIGH : LOW);
  digitalWrite(LED_YELLOW, (pressCounter >= 3) ? HIGH : LOW);
  digitalWrite(LED_BLUE,   (pressCounter >= 4) ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);
  

  pinMode(BUTTON_PIN, INPUT);
  

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  
  updateLEDs();
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);
  
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50); 
    
    pressCounter++;
    if (pressCounter > 4) {
      pressCounter = 0;
    }
    

    Serial.print("count=");
    Serial.println(pressCounter);
    
    updateLEDs();
  }
  
  lastButtonState = currentButtonState;
}

