#include "Arduino.h"


#define LIGHT 34

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(LIGHT, INPUT); // LIGHT SENSOR
}


/****************************************************/
void loop(void) 
{
    long sum = 0;
    int minVal = 4095; 
    int maxVal = 0;


    for (int i = 0; i < 10; i++) {
        int sample = analogRead(LIGHT);
        
        sum = sum + sample; 
        
        if (sample < minVal) { minVal = sample; } 
        if (sample > maxVal) { maxVal = sample; } 
    }

    int avgVal = sum / 10;


    Serial.print("min="); Serial.print(minVal);
    Serial.print(" max="); Serial.print(maxVal);
    Serial.print(" avg="); Serial.println(avgVal);

    delay(1000);
}
