#ifndef BINARY_CLOCK
#define BINARY_CLOCK
#include <Arduino.h>

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

class Display{
 public:

    //Initializes all of the 13 LED pins to OUTPUT
    void init();

    /**
     * Displays a binary digit in the desired column by writing the correct pins to HIGH
        @param column enter 0-3 for columns A-D on the schematic
        @param number this is the number (0-9) that will be displayed in the desired column
    */
    void displayDigit(uint8_t column, int number);

    /**
     * writes a single pin to blink in order to test electrical wiring functionality
        @param ledNum the alphanumeric code assigned to each LED to blink it
    */
    void testLED(uint8_t ledNum);

    //Blinks each LED as ESP32 is connecting to local Wi-Fi
    void booting();

    /**
     *  updates the time by taking in an hour and minute integer value. 
        @param currHour the current hour as an integer
        @param currMin the current minute as an integer
    */
    void updateTime(int currHour, int currMin);
};

#endif