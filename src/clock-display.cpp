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

void Display::displayDigit(uint8_t column,  int number, int pot_value){

    switch(number){
        case 0: 
         analogWrite(pins[column][0], 0);
         analogWrite(pins[column][1], 0);
         analogWrite(pins[column][2], 0);
         analogWrite(pins[column][3], 0);
        break;

        case 1: 
         analogWrite(pins[column][0], pot_value);
         analogWrite(pins[column][1], 0);
         analogWrite(pins[column][2], 0);
         analogWrite(pins[column][3], 0);
        break;

        case 2:
         analogWrite(pins[column][0], 0);
         analogWrite(pins[column][1], pot_value);
         analogWrite(pins[column][2], 0);
         analogWrite(pins[column][3], 0);
        break;

        case 3:
         analogWrite(pins[column][0], pot_value);
         analogWrite(pins[column][1], pot_value);
         analogWrite(pins[column][2], 0);
         analogWrite(pins[column][3], 0);
        break;

        case 4:
         analogWrite(pins[column][0], 0);
         analogWrite(pins[column][1], 0);
         analogWrite(pins[column][2], pot_value);
         analogWrite(pins[column][3], 0);
        break;

        case 5:
         analogWrite(pins[column][0], pot_value);
         analogWrite(pins[column][1], 0);
         analogWrite(pins[column][2], pot_value);
         analogWrite(pins[column][3], 0);
        break;

        case 6:
         analogWrite(pins[column][0], 0);
         analogWrite(pins[column][1], pot_value);
         analogWrite(pins[column][2], pot_value);
         analogWrite(pins[column][3], 0);
        break;

        case 7:
         analogWrite(pins[column][0], pot_value);
         analogWrite(pins[column][1], pot_value);
         analogWrite(pins[column][2], pot_value);
         analogWrite(pins[column][3], 0);
        break;

        case 8: 
         analogWrite(pins[column][0], 0);
         analogWrite(pins[column][1], 0);
         analogWrite(pins[column][2], 0);
         analogWrite(pins[column][3], pot_value);
        break;

        case 9: 
         analogWrite(pins[column][0], pot_value);
         analogWrite(pins[column][1], 0);
         analogWrite(pins[column][2], 0);
         analogWrite(pins[column][3], pot_value);
        break;
    };
};

void Display::testLED(u_int8_t ledNum){

    analogWrite(ledNum, 255);
    delay(200);
    analogWrite(ledNum, 0);
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

void Display::updateTime(int currHour, int currMin, int pot_value){

    //calculate values to be displayed
    int firstHourDigit = currHour / 10;
    int secondHourDigit = currHour % 10;
    int firstMinDigit = currMin /10;
    int secondMinDigit = currMin % 10;

    //set column A
    displayDigit(0,firstHourDigit, pot_value);

    //set column B
    displayDigit(1,secondHourDigit, pot_value);

    //set column C
    displayDigit(2, firstMinDigit, pot_value);

    //set column D
    displayDigit(3, secondMinDigit, pot_value);
};
