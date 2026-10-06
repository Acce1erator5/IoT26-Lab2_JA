#include "Arduino.h"

#define LIGHT 34
unsigned long lastCheck = 0;
bool AlertActive = false;


/****************************************************/
void setup(void) 
{   
    Serial.begin(115200);
    pinMode(LIGHT, INPUT);


    if (analogRead(LIGHT) > 3000) {
        AlertActive = true;
    }
}


/****************************************************/
void loop(void) 
{
    if (millis() - lastCheck >= 300) {
        lastCheck = millis();

        int val = analogRead(LIGHT);

        if (val > 3000 && AlertActive == false) {
            AlertActive = true;
            Serial.println("ALERT=1");
        }
        
        if (val < 2500 && AlertActive == true) {
            AlertActive = false;
            Serial.println("ALERT=0"); 
        }
    }
}
