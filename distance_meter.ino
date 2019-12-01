#include <SPI.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define VOLTAGE_TO_INCHES   0.009765625
#define NUMBER_OF_AVERAGES  4096

// SPI Pins
#define OLED_RESET  8
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12

// Conversion constants
#define COUNTS_MAX 1023.0
#define VOLTS_MAX     5.0

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup()   {        
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC);
 
  display.setTextSize(3);
  display.setTextColor(WHITE);
  
  int    sensorValue    =   0;
  double voltage        = 0.0;
  double distance       = 0.0;
  double runningAverage = 0.0;
    
  while(true){
    
    display.clearDisplay();
    
    runningAverage = 0.0;
    
    for( int i = 0; i < NUMBER_OF_AVERAGES; i++ )
    {
      sensorValue = analogRead(A0);
      
      // convert the ADC reading to voltage
      voltage = sensorValue * (5.0 / 1023.0);
      
      // convert the voltage to a distance in inches
      distance = (voltage / VOLTAGE_TO_INCHES);
      
      // add distance value to running average
      runningAverage += distance;
    }
    
    distance = runningAverage / NUMBER_OF_AVERAGES;
    
    display.setCursor(20,5);
    display.println(distance);
    display.display();
    
  } // while
}

void loop() {
}
