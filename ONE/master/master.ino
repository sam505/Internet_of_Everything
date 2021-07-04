#include <Wire.h>

unsigned long time_start;   // start time in milliseconds
byte value_read;             // potentiometer position

void setup(){
  Wire.begin(); // join I2C bus as the master
  Serial.begin(9600);
  
  // initialize global variables
  time_start = millis();
  
}

void loop(){
  // read potentiometer position
  value_read = analogRead(A1);   // read the voltage at pin A0 (potentiometer voltage)
  float mv = (value_read/1024.0)*5000;
  int cel = mv/10;
  Serial.println(cel);

  // send potentiometer position to Slave device 0x08
  Wire.beginTransmission(0x08); // informs the bus that we will be sending data to slave device 8 (0x08)
  Wire.write(cel);        // send value_pot
  Wire.endTransmission();       // informs the bus and the slave device that we have finished sending data
  
}
