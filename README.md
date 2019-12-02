# Distance Meter

Distance Meter is an Arduino project consisting of a single source file. Current
software is located [here](https://github.com/jaylamb/distance_meter.git).

### Required hardware:
* 1x Adafruit Metro Mini (ATMEGA328P)
* 1x MaxBotix LV-MaxSonar-EZ SONAR range finder
* 1x Adafruit 0.96" monochrome 128x64 OLED graphic display

## Required Libraries 

[Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306.git)
[Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library.git)

## Usage
Download and install the required libraries within ArduinoIDE, and download the
project software. Setting the "board" within ArduinoIDE to "Arduino UNO" will
allow ArduinoIDE to correctly identify the hardware. Upload the software to the
Metro Mini. The distance from the SONAR range finder will begin to be reported.
The distance will be updated indefinitely until power is removed from the
system. 

## License [Apache 2.0](http://www.apache.org/licenses/)
