// Main
#include <Arduino.h>              // Main Arduino Library
#include "pinSettings.h"          // Pin Settings Setup

// Features
#include "sensors/DHTxx.h"        // DHTxx Sensor Code
#include "wifi/wifi.h"            // Wifi Connection
#include "mqtt/mqtt.h"            // MQTT Code
#include "display/display.h"      //Display Code


void setup() {

  Serial.begin(9600);             // Start Serial Communication 
  pinSettings();                  // Pin Settings Setup
  DHTxxSetup();                   // DHTxx Sensor Setup
  wifiConnect();                  // Wifi Connection
  mqttConnect();                  // MQTT Setup
  startDisplay();                 // Start and configure display

}

void loop() {
 
  DHTxxRead();                    // DHTxx Sensor Readings
  DHTxxSerialPrint();             // DHTxx Sensor Serial Print
  //mqttPublish();                  // MQTT Publish
  refreshDisplay();               // Show MAC, temperature and humidity in display
  wifiReconnect();                // Wifi Connection
}