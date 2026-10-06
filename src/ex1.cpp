#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14


int step = 0;



/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT); // RED LED
    pinMode(GREEN_LED_PIN, OUTPUT); // GREEN LED
    pinMode(YELLOW_LED_PIN, OUTPUT); // YELLOW LED  
    pinMode(BLUE_LED_PIN, OUTPUT); // BLUE LED


}


/****************************************************/
void loop(void) 
{
    if (step == 0)
    {
        digitalWrite(RED_LED_PIN, HIGH);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
        Serial.println("chase=RED");
    }
    else if (step == 1)
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
        Serial.println("chase=GREEN");
    }
    else if (step == 2)
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, LOW);
        Serial.println("chase=YELLOW");
    }
    else if (step == 3)
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, HIGH);
        Serial.println("chase=BLUE");

    }
    else if (step == 4)
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, HIGH);
        digitalWrite(BLUE_LED_PIN, LOW);
        Serial.println("chase=YELLOW");

    }
    else if (step == 5)
    {
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, HIGH);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
        Serial.println("chase=GREEN");
    }

    step = step + 1;
    if (step >= 6) {
        step = 0;
    }


    delay(150);
}