// Main
#include <Arduino.h>              // Main Arduino Library
#include "pinSettings.h"          // Pin Settings Setup

// Features
#include "sensors/DHTxx.h"        // DHTxx Sensor Code
#include "wifi/wifi.h"            // Wifi Connection
#include "mqtt/mqtt.h"            // MQTT Code
#include "display/display.h"      // Display Code

// Time
#include <ctime>                  // To use in place of delay

int timeStatus = 1;               // When 1, timeStart can be update
time_t timeStart, timeNow;        // To control time elapsed
int timeControl = 5;              // Time elapsed to new read

void setup() {

  Serial.begin(115200);           // Start Serial Communication 
  pinSettings();                  // Pin Settings Setup
  DHTxxSetup();                   // DHTxx Sensor Setup
  wifiConnect();                  // Wifi Connection
  mqttConnect();                  // MQTT Setup
  startDisplay();                 // Start and configure display

}

void loop() {

  if (timeStatus == 1)
  {
    timeStart = time(0);
    timeNow = time(0);
    timeStatus = 0;               // cant time update
  }

  timeNow = time(0);              // time elapsed update




  if ((timeNow - timeStart) >= timeControl)
  {
    Serial.println("Read Sensor");
    DHTxxRead();                    // DHTxx Sensor Readings
    DHTxxSerialPrint();             // DHTxx Sensor Serial Print
    

    // Verify internet connection to publish the reads
    if (WiFi.status() == WL_CONNECTED)
    {
      mqttPublish();                  // MQTT Publish
      
    }
    else
    {
      wifiReconnect();                // Wifi Reconnect
      if (WiFi.status() == WL_CONNECTED)
      {
        mqttPublish();                  // MQTT Publish
      }
    }
    refreshDisplay();               // Show MAC, temperature and humidity in display
    timeStatus = 1;                 // can time update
  }
  
  
  wifiReconnect();                // Wifi Reconnect

  //LED indicator
  if (WiFi.status() == WL_CONNECTED){
    digitalWrite(LEDCON, HIGH);
    digitalWrite(LEDDIS, LOW);
  }
  
  if (digitalRead(LEDCON == HIGH)){
    digitalWrite(LEDDIS, LOW);
  }
  else{
    digitalWrite(LEDDIS, HIGH);
  }
  

//LED indicator
  if (WiFi.status() == WL_CONNECTED){
    digitalWrite(LEDCON, HIGH);
    digitalWrite(LEDDIS, LOW);
  }
  
}