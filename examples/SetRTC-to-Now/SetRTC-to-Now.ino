#include "RTClib.h"

void setup() {
  //use __DATE__ and __TIME__ variables to set time when this program was compiled  
  int compile_time = DateTime(F(__DATE__), F(__TIME__)).unixtime();
  rtc_set(compile_time+5); // Set real-time clock (RTC) to compile time plus 5 seconds to approximately account for time to upload program.
}

void loop() {
  static unsigned long lastrun = 0;    

  if (millis() > lastrun) { //Run once every 5000ms
    lastrun = millis() + 5000;
    toggleLEDBlue();
    DateTimeFields tm;  //structure to hold date time info
    breakTime(rtc_get(), tm);  // break raw rtc_get() results (seconds since 1970) into DateTimeFields structure
    Serial.printf("Date time is %02d/%02d/%04d %02d:%02d:%02d\n",tm.mon+1,tm.mday,tm.year+1900,tm.hour,tm.min,tm.sec);
  }
}