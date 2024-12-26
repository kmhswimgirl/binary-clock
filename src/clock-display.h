#ifndef BINARY_CLOCK
#define BINARY_CLOCK
#include <Arduino.h>

 //new branch -- config
//function that sets up the display for the time
class Display{
    public:

     void init();

     //displays the current time on the clock
     void displayDigit( uint8_t , int);

      // toggles if the display is using 24 hr or common time
      bool is24hr();

     //displays loading LED animation
     void loadingPhase();

     //test function to light certain LED
     void testLED(int, int);


};

#endif