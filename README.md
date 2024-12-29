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

### Wiring Schematic (main board only):
NB: each LED has a 220 ohm resistor connected to it, which will later be increased to further dim the LEDs as they are very bright at the moment. 
<img width="700" alt="Screenshot 2024-12-24 at 02 27 55" src="https://github.com/user-attachments/assets/972d5872-cb4c-4f9f-9be7-d79a7f309d89" />
** used this for some basic PCB design practice too
