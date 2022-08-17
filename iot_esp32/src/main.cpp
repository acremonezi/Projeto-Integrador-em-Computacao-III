#include <Arduino.h>        // Main Arduino library
#include "WiFiSetup.h"      // Setup WiFi Interface


void setup() {
  Serial.begin(115200);
  WiFiSetup();              // Setup WiFi Interface

}

void loop() {
  //printCurrentNet();
}