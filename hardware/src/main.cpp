// Main
#include <Arduino.h>              // Main Arduino Library
#include "pinSettings.h"          // Pin Settings Setup

// Features
#include "sensors/DHTxx.h"        // DHTxx Sensor Code
#include "wifi/wifi.h"            // Wifi Connection
#include "mqtt/mqtt.h"            // MQTT Code


void setup() {

  Serial.begin(9600);             // Start Serial Communication 
  pinSettings();                  // Pin Settings Setup
  DHTxxSetup();                   // DHTxx Sensor Setup
  wifiConnect();                  // Wifi Connection
  mqttConnect();                  // MQTT Setup

}

void loop() {
 
  DHTxxRead();                    // DHTxx Sensor Readings
  DHTxxSerialPrint();             // DHTxx Sensor Serial Print
  mqttPublish();                  // MQTT Publish

}