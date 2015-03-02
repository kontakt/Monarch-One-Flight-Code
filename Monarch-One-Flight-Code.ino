/*   Monarch One Flight Code
     Arduino Variant
     Version 0.0.0
     Connor Huffine
     3/2/15
*/ 

/*  CONFIG  */
// DEBUG
const bool DEBUG   =   true;

// Timings ( in Microseconds, 1 second = 1,000,000 micros )
const uint8_t SD_period        = 0;
const uint8_t solar_period     = 0;
const uint8_t radio_period     = 0;
const uint8_t sensor_period    = 0;

// Time values for subroutines
unsigned long last_time;
unsigned long SD_time;
unsigned long solar_time;
unsigned long radio_time;
unsigned long sensor_time;

#include <SPI.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SD.h>

void setup() {
  // Initialize all hardware here
  
  // Set initial time to NOW
  last_time   =   micros();
  // Initialize all run times
  SD_time     =   last_time;
  solar_time  =   last_time;
  radio_time  =   last_time;
  sensor_time =   last_time;
  
  if(DEBUG) Serial.println(F("Setup Complete"));
}

void loop() {
  // Main loop
  // Subroutines ranked in order of priority
  if(last_time > solar_time)
    solar_read();
  if(last_time > sensor_time)
    sensor_poll();
  if(last_time > SD_time)
    SD_write();
  if(last_time > radio_time)
    radio_transmit();
  // Set last loop time
  last_time   =   micros();
}

/*  SUBROUTINES  */
void SD_write() {
  if(DEBUG) Serial.println(F("SD_write"));
  SD_time      +=   SD_period;
}

void solar_read(){
  if(DEBUG) Serial.println(F("Solar_read"));
  solar_time   +=   solar_period;
}

void radio_transmit(){
  if(DEBUG) Serial.println(F("Radio_transmit"));
  radio_time   +=   radio_period;
}

void sensor_poll(){
  if(DEBUG) Serial.println(F("Sensor_poll"));
  sensor_time  +=   sensor_period;
}
