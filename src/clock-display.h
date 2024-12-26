#ifndef BINARY_CLOCK
#define BINARY_CLOCK
#include <Arduino.h>



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
    void testLED(char ledNum);

    //displays loading LED animation
    void booting();

};

#endif