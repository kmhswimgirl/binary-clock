#include <Arduino.h>
#include <WiFi.h>
#include <time.h>
#include <esp_sntp.h>
#include <clock-display.h>
#include <soc/rtc_cntl_reg.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>
#include <Adafruit_GFX.h> // general graphics driver
#include <Adafruit_SSD1306.h> // hardware specific grpahics driver

#include <wifi-creds.h> 
/*
In order to set up wifi network name and passwords correctly:
1. create the header file wifi-creds.h
2. copy and paste this snippet of code:

  #include <Arduino.h>

  class wifiPass{

    public:
      const char *network = "put your network name here";
      const char *password = "put network password here";
  }; 

3. add header file name to the .gitignore so you do not share your wifi password(s) on GitHub.
*/
//OLED Display Setup
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

//creating objects
wifiPass creds;
Display clockDisplay;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Wi-fi setup
const char *ssid = creds.network;
const char *password = creds.password;

//setting up the potentiometer to dim the LEDs
#define DIMMER 35
int brightness;

// non blocking timer variables
unsigned long currentTime;
unsigned long previousTime;
unsigned long NTPinterval = 5000;

//NTP server setup
const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;
#define TZ_America_New_York	PSTR("EST5EDT,M3.2.0,M11.1.0")
const char *time_zone = "CET-1CEST,M3.5.0,M10.5.0/3"; 

//arrays that store current hour & minute values
char timeHour[3];
char timeMin[3];

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
};

//gets NTP data and sets variables that are sent to the clock
void setCurrentTime(){
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  strftime(timeHour,3, "%H", &timeinfo);
  strftime(timeMin,3, "%M", &timeinfo);
  
};

// Callback function (gets called when time adjusts via NTP)
void timeavailable(struct timeval *t) {
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
  setCurrentTime();
};

int getPotInput(){
  int potRead = analogRead(DIMMER);
  brightness = potRead / 18.2;
  return brightness;

  Serial.println(brightness);
}

void setup() {
  //disable ESP brownout message
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

  //initialize Serial Monitor
  Serial.begin(115200);

  //initialize LED Pins
  clockDisplay.init();

  Serial.println(WiFi.macAddress());

  //initalize potentiometer pin (Make sure the Vcc pin is connected to 3v3 on the ESP!!!)
  pinMode(DIMMER, ANALOG);

  // First step is to configure WiFi STA and connect in order to get the current time and date.
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);

  esp_sntp_servermode_dhcp(1);  // (optional)

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    clockDisplay.booting();

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
    }
    Serial.println(WiFi.macAddress());

  }
  Serial.println(" CONNECTED!"); //connected to wi-fi, yay!

  sntp_set_time_sync_notification_cb(timeavailable);

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);

  configTzTime(TZ_America_New_York, ntpServer1, ntpServer2);

  //display?
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 10);
}

void loop() {

  //start timer
  currentTime = millis();

  //5 sec non blocking timer for grabbing NTP data
  if((currentTime - previousTime) > NTPinterval){

    //extract data from the most current NTP time and store it in arrays
    setCurrentTime(); 

    //check what the NTP server is returning
    printLocalTime(); 

    //make previous time be the current time
    previousTime = currentTime;
  }
 
  //convert arrays to integers
  int hour = atoi(timeHour);
  int minute = atoi(timeMin);

  //update LED display with the current time
  clockDisplay.updateTime(hour, minute, getPotInput());
}
