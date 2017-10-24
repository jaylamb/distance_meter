/*********************************************************************
This is 
*********************************************************************/

#include <SPI.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define VOLTAGE_TO_INCHES   0.009765625
#define NUMBER_OF_AVERAGES  4096

// Define SPI Pins
#define OLED_RESET 8
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup()   {        
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done
 
  // Begin normal operation
  display.setTextSize(4);
  display.setTextColor(WHITE);
  
  int sensorValue = 0;
  double voltage = 0.0;
  double distance = 0.0;
  double runningAverage = 0.0;
    
  while(1){
    
    // Clear the buffer
    display.clearDisplay();
    
    // Reset running average
    double runningAverage = 0.0;
    
    for( int i = 0; i < NUMBER_OF_AVERAGES; i++ )
    {
      // read the input on analog pin 0:
      sensorValue = analogRead(A0);
      
      // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      voltage = sensorValue * (5.0 / 1023.0);
      
      // Convert the voltage (0 - 5V) to a distance (inches)
      distance = (voltage / VOLTAGE_TO_INCHES);
      
      // Add distance value to running average
      runningAverage += distance;
    }
    
    // Calculate distance from sensor
    distance = runningAverage / NUMBER_OF_AVERAGES;
    
    // Print distance
    display.setCursor(0,20);
    display.println(distance);
    display.display();
    
  } // while
}

void loop() {
}

