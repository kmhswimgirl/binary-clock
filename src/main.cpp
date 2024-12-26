#include <Arduino.h>
#include <WiFi.h>
#include <time.h>
#include <esp_sntp.h>
#include <wifi-creds.h> 
#include <clock-display.h>

/*
In order to set up wifi network name and passwords correctly:
1. create the header file wifi-creds.h
2. copy and paste this snippet of code:

  #include <arduino.h>

  class wifiPass{

    public:
      const char *network = "put your network name here";
      const char *password = "put network password here";
  }; 

3. add header file name to the .gitignore so you do not share your wifi password(s) on GitHub.
*/

wifiPass creds;
Display display;

const char *ssid = creds.network;
const char *password = creds.password;

const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;
#define TZ_America_New_York	PSTR("EST5EDT,M3.2.0,M11.1.0")

const char *time_zone = "CET-1CEST,M3.5.0,M10.5.0/3"; 


void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

// Callback function (gets called when time adjusts via NTP)
void timeavailable(struct timeval *t) {
  Serial.println("Got time adjustment from NTP!");
  printLocalTime();
}

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  //initialize LED Pins
  display.init();

  //get rid of serial monitor garbage
  pinMode(15, INPUT_PULLDOWN);
  digitalWrite(15, LOW);

  // First step is to configure WiFi STA and connect in order to get the current time and date.
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);

  esp_sntp_servermode_dhcp(1);  // (optional)

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  Serial.println(" CONNECTED");

  sntp_set_time_sync_notification_cb(timeavailable);

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);
   
  configTzTime(TZ_America_New_York, ntpServer1, ntpServer2);

}

void loop() {
  delay(5000);
  printLocalTime();  
  display.displayDigit(1,0);
  display.displayDigit(3,0);
}

