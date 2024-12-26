#ifndef BINARY_CLOCK
#define BINARY_CLOCK
#include <Arduino.h>



class Display{
    public:
     //initializes LED Pins to OUTPUT
     void init();

     //displays a specific digit in each column
     void displayDigit( uint8_t column, int number);

     // toggles if the display is using 24 hr or common time
     bool is24hr();

     //displays loading LED animation
     void loadingPhase();

};

#endif