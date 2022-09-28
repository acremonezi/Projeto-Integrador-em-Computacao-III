#include <Arduino.h>              // Main Arduino Library
#include "pinSettings.h"          // Pin Settings Setup

// Features
#include "sensors/DHTxx.h"        // DHTxx Sensor Code


//Display
#include <Wire.h>
#include "SSD1306Wire.h"
#include <stdio.h>
#include <iostream>
#include <string.h>


    // vars to use with display
    String textTemperatureComplete;
    String textHumidityComplete;
    String textMACComplete;


SSD1306Wire display(0x3c, D6, D5, GEOMETRY_128_64);


void startDisplay()
{
    display.init();
    display.flipScreenVertically();
}


void refreshDisplay()
{
  // display lines
  delay(2000);
  display.clear(); // only first time in loop
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  // MACADRESS
  display.setFont(ArialMT_Plain_10);
  textMACComplete += espClientMAC;
    if (textMACComplete == "")
  {
    textMACComplete += "Not Conected";
  }
  display.drawString(10, 0, textMACComplete);
  Serial.print("MACADRESS: ");
  Serial.println(textMACComplete);
  display.display();
  textMACComplete = "";

  // Temperature
  display.setFont(ArialMT_Plain_16);
  
  
  
  textTemperatureComplete += DHTxxTemperature;
  textTemperatureComplete += " ºC";
  display.drawString(20, 20, textTemperatureComplete);
  display.display();
  textTemperatureComplete = "";

  // Humidity
  display.setFont(ArialMT_Plain_16);
  
  textHumidityComplete += DHTxxHumidity;
  textHumidityComplete += " %";
  display.drawString(70, 40, textHumidityComplete);
  display.display();
  textHumidityComplete = "";

  Serial.println(textTemperatureComplete);
  Serial.println(textHumidityComplete);

}