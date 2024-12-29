#include <arduino.h>
#include <clock-display.h>
#include <iostream>

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

void Display::testLED(u_int8_t ledNum){

    digitalWrite(ledNum, HIGH);
    delay(200);
    digitalWrite(ledNum, LOW);
    delay(200);
};

void Display::booting(){
   testLED(A1);
   testLED(A2);

   testLED(B1);
   testLED(B2);
   testLED(B3);
   testLED(B4);

   testLED(C1);
   testLED(C2);
   testLED(C3);

   testLED(D1);
   testLED(D2);
   testLED(D3);
   testLED(D4);

   delay(1000);
};

void Display::updateTime(int currHour, int currMin){

    //calculate values to be displayed
    int firstHourDigit = currHour / 10;
    int secondHourDigit = currHour % 10;
    int firstMinDigit = currMin /10;
    int secondMinDigit = currMin % 10;

    //set column A
    displayDigit(0,firstHourDigit);

    //set column B
    displayDigit(1,secondHourDigit);

    //set column C
    displayDigit(2, firstMinDigit);

    //set column D
    displayDigit(3, secondMinDigit);
};
