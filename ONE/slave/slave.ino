#include <Wire.h>

byte temp;               // data received from I2C bus
unsigned long time_start;   // start time in mSec

void setup(){
  Wire.begin(0x08);           // join I2C bus as Slave with address 0x08
  Serial.begin(9600);
  
  // event handler initializations
  Wire.onReceive(dataRcv);    // register an event handler for received data
  
  // initialize global variables
  time_start = millis();

  pinMode(7, OUTPUT);    // set pin 7 as an output
}

void loop(){
Serial.println(temp);
if (temp > 40){
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
  }
  else{
    digitalWrite(7, LOW);
    }
}

//received data handler function
void dataRcv(int numBytes){
  while(Wire.available()) { // read all bytes received
    temp = Wire.read();
  }
}
