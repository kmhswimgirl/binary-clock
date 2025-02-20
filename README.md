# ESP32 Binary LED Display Clock
Goal: create a system that retrieves the time from wi-fi and/or GPS and display it by using on/off LEDS to represent 1s and 0s. GPS version should displays coordinates as well. Eventually further versions will have custom PCBs, however I need to learn PCB design/KiCad first. 

## Current Version Materials List:
- ESP32 (needs 13 GPIO pins)
- Female pin headers (ESP --> PCB connection)
- Male pin headers (connecting main Protoboard to secondary one)
- LEDs (x13, 5mm)
- ElectroCookie Solderable Breadboard (1/2 size)
- PCB protoboard (smaller than ElectroCookie one)
- 220 ohm resistors (x13)
- Electrical wire and/or breadboard wires
- M-M & M-F dupont breadboard wires

> [!TIP]
Have a test rig setup with basic Arduino IDE code that blinks an LED. This saved me a LOT of time when trying to figure out which connection(s) I initially soldered incorrectly.

## Version 1.0.0
Basic Working LED binary clock with no additional features.

### Images:
<img width = "350" alt="Post-soldering all of the resistors on" src="https://github.com/user-attachments/assets/0eb2fa0a-3993-4f1b-9f7d-01eeafb127f9" />
<img width = "350" alt="it works!" src="https://github.com/user-attachments/assets/c3dab65a-27d0-412b-a622-1a03e3dc80a5" />
<img width = "700" alt="it works!" src="https://github.com/user-attachments/assets/b0d06481-1865-4168-9bc8-8da016e4292d" />

### Features: 

- Accurately displays 24hr time in binary using LEDs
- updated time is fetched from NTP server every 5 seconds
- Is able to show connected/not connected states using a loading LED animation
- can automatically reconnect to wi-fi if disconnected

### Wiring Schematic (main protoboard only):
<img width="700" alt="initial KiCad design" src="https://github.com/user-attachments/assets/972d5872-cb4c-4f9f-9be7-d79a7f309d89" />
<br/>
Note: each LED has a 220 ohm resistor connected to it, which will later be increased to further dim the LEDs as they are very bright at the moment. I also used this for some PCB/ KiCad practice

## Version 1.1.0
Added non-blocking timer, updated KiCad schematics, began thinking about building a much neater and more organized. CAD modeled a stand to hold the main board. wrote and tested display compatibility for an SSD1306 128x32.

### Images:

### Features:
  - timer is now non blocking
  - added OLED display in order to show current date and day of the week
  - refactored code in order to accommodate auto dimming by using analog pwm signals instead of digital ones

    
### KiCad Schematic:
<img width="700" alt="KiCad schematic with resistors" src="https://github.com/user-attachments/assets/db3af4e5-d0d9-4c55-877c-877dbd50886a" />
<br/>
Note: Schematic has been updated to include resistors, still only shows the main board wiring, but will soon include all elements of the design




