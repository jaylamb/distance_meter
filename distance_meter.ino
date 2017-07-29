/*********************************************************************
This is 
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


#define OLED_RESET 4
#define VOLTAGE_TO_INCHES 0.009765625
#define CHEAT_FACTOR      3.500000000

Adafruit_SSD1306 display(OLED_RESET);

void setup()   {        
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
          
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
 
  // Begin normal operation
  display.setTextSize(4);
  display.setTextColor(WHITE);
  while(1){
    
    // Clear the buffer.
    display.clearDisplay();
    
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    double voltage = sensorValue * (5.0 / 1023.0);
    // Convert the voltage (0 - 5V) to a distance (inches)
    double distance = (voltage / VOLTAGE_TO_INCHES) + CHEAT_FACTOR;
    
    // print out the value you read:
    //Serial.println(voltage);

    display.setCursor(0,20);
    display.println(distance);
    display.display();
    delay(250);
  }
}

