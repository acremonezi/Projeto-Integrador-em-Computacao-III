#include <Arduino.h>              // Main Arduino Library
#include "pinSettings.h"          // Pin Settings Setup
#include "wifi/wifi.h"            // Wifi Connection

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
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  // MACADRESS
  display.setFont(ArialMT_Plain_10);
  textMACComplete += espClientMAC;
    if ((textMACComplete == "") || (WiFi.status() != WL_CONNECTED))
  {
    textMACComplete = "Not Conected";
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

}