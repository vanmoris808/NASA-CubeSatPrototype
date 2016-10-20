//#include <Adafruit_VC0706.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h> //Lux
#include "TSL2561.h" //Lux
#include <DHT.h> //Temp/Hum
#include <SoftwareSerial.h> 



void setup() {
 pinMode(10, OUTPUT); 
 
  Serial.begin(9600);
  
 Serial.println("Please select as follows:");
 Serial.println("1 for Light");
 Serial.println("2 for Temperature");
 Serial.println("3 for Humidity");
 Serial.println("4 for Camera");
 Serial.println("5 for accelerometer");

 Wire.begin(); // join i2c bus (address optional for master)
}




void loop()
{if (Serial.available() > 0) {
     
       int inByte = Serial.read();
    switch (inByte) {
       case '1':
         
         Wire.beginTransmission(1); // transmit to device #8
         //Wire.write("Sensor pick up");        // sends five bytes
         Wire.write(1);              // sends one byte
         Wire.endTransmission(); // stop transmitting
         //Wire.flush();
         Serial.println("Processing light sensor...");
         break;
       case '2':
         
         Wire.beginTransmission(2); //ransmit to device #8
         //Wire.write("Sensor pick up");        // sends five bytes
         Wire.write(1);              // sends one byte
         Wire.endTransmission();    // stop transmitting
         Wire.flush();
         Serial.println("Processing temperature sensor...");
         break;
       case '3':
         //digitalWrite(3, HIGH);
         //Serial.println("It was B!");
         //sensors();
         Wire.beginTransmission(2); // transmit to device #8
         //Wire.write("Sensor pick up");        // sends five bytes
         Wire.write(2);              // sends one byte
         Wire.endTransmission();    // stop transmitting
         Wire.flush();
         Serial.println("Processing humidity sensor...");
         break;
         case '4':
         //digitalWrite(3, HIGH);
         //Serial.println("It was B!");
         //sensors();
         Wire.beginTransmission(3); // transmit to device #8
         //Wire.write("Sensor pick up");        // sends five bytes
         Wire.write(1);              // sends one byte
         Wire.endTransmission();    // stop transmitting
         Wire.flush();
         Serial.println("Processing camera...");
         break;
         case '5':
         //digitalWrite(3, HIGH);
         //Serial.println("It was B!");
         //sensors();
         Wire.beginTransmission(4); // transmit to device #8
         //Wire.write("Sensor pick up");        // sends five bytes
         Wire.write(1);              // sends one byte
         Wire.endTransmission();    // stop transmitting
         Wire.flush();
         Serial.println("Processing accelerometer...");
         break;
       default:
          Serial.println("Incorrect input - try again!");
  }
}
 
  delay(2000);
}
