/*   Monarch One Flight Code
     Arduino Variant
     Version 0.0.0
     Connor Huffine
     3/2/15
*/ 

/*  CONFIG  */
// Timings
const int SD_write       = 0;
const int solar_read     = 0;
const int radio_transmit = 0;
const int sensor_read    = 0;

// Time values for subroutines
unsigned long last_time;
unsigned long SD_time;
unsigned long solar_time;
unsigned long radio_time;
unsigned long sensor_time;

void setup() {
  // Initialize all hardware here
  
  // Set initial time to NOW
  last_time   =   micros();
  // Initialize all run times
  SD_time     =   last_time;
  solar_time  =   last_time;
  radio_time  =   last_time;
  sensor_time =   last_time;
}

void loop() {
  // Main loop
  // Subroutines ranked in order of priority
  // 
  // Set last loop time
  last_time   =   micros();
}


