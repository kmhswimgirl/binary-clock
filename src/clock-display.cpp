#include <arduino.h>
#include <clock-display.h>
#include <iostream>

//pin definitons for each LED
#define A1 27
#define A2 12

#define B1 13
#define B2 33
#define B3 26
#define B4 25

#define C1 16
#define C2 2
#define C3 4

#define D1 19
#define D2 18
#define D3 22
#define D4 23 

//2D array that describes the location of each pin 
uint8_t pins[4][4] = {
    {A1, A2, 0, 0},
    {B1, B2, B3, B4},
    {C1, C2, C3, 0},
    {D1, D2, D3, D4}
};

//Used to initialize all of the pin connections for the clock
void Display::init(){

    //A Pins Setup
    pinMode(A1, OUTPUT); 
    pinMode(A2, OUTPUT);

    //B Pins Setup
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);
    pinMode(B3, OUTPUT);
    pinMode(B4, OUTPUT);

    //C Pins Setup
    pinMode(C1, OUTPUT);
    pinMode(C2, OUTPUT);
    pinMode(C3, OUTPUT);

    //D Pins Setup
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);

    Serial.print("Pins initialized");
};

void Display::displayDigit(uint8_t column,  int number){

    switch(number){
        case 0: 
         digitalWrite(pins[column][0], LOW);
         digitalWrite(pins[column][1], LOW);
         digitalWrite(pins[column][2], LOW);
         digitalWrite(pins[column][3], LOW);
        break;

        case 1: 
         digitalWrite(pins[column][0], HIGH);
         digitalWrite(pins[column][1], LOW);
         digitalWrite(pins[column][2], LOW);
         digitalWrite(pins[column][3], LOW);
        break;

        case 2:
         digitalWrite(pins[column][0], LOW);
         digitalWrite(pins[column][1], HIGH);
         digitalWrite(pins[column][2], LOW);
         digitalWrite(pins[column][3], LOW);
        break;

        case 3:
         digitalWrite(pins[column][0], HIGH);
         digitalWrite(pins[column][1], HIGH);
         digitalWrite(pins[column][2], LOW);
         digitalWrite(pins[column][3], LOW);
        break;

        case 4:
         digitalWrite(pins[column][0], LOW);
         digitalWrite(pins[column][1], LOW);
         digitalWrite(pins[column][2], HIGH);
         digitalWrite(pins[column][3], LOW);
        break;

        case 5:
         digitalWrite(pins[column][0], HIGH);
         digitalWrite(pins[column][1], LOW);
         digitalWrite(pins[column][2], HIGH);
         digitalWrite(pins[column][3], LOW);
        break;

        case 6:
         digitalWrite(pins[column][0], LOW);
         digitalWrite(pins[column][1], HIGH);
         digitalWrite(pins[column][2], HIGH);
         digitalWrite(pins[column][3], LOW);
        break;

        case 7:
         digitalWrite(pins[column][0], HIGH);
         digitalWrite(pins[column][1], HIGH);
         digitalWrite(pins[column][2], HIGH);
         digitalWrite(pins[column][3], LOW);
        break;

        case 8: 
         digitalWrite(pins[column][0], LOW);
         digitalWrite(pins[column][1], LOW);
         digitalWrite(pins[column][2], LOW);
         digitalWrite(pins[column][3], HIGH);
        break;

        case 9: 
         digitalWrite(pins[column][0], HIGH);
         digitalWrite(pins[column][1], LOW);
         digitalWrite(pins[column][2], LOW);
         digitalWrite(pins[column][3], HIGH);
        break;
    };
};

void Display::testLED(char ledNum){
    digitalWrite(ledNum, HIGH);
    delay(200);
    digitalWrite(ledNum, LOW);
    delay(200);
};
//eventually will write a for loop animation or two for fun
void Display::booting(){
   
};
