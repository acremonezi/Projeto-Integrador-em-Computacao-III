#include <Arduino.h>
#include "pinSettings.h"  // Pin Settings Setup

#include "blink.h"        // Hello World Alcides!!!

void setup() {

  Serial.begin(9600);     // Start Serial Communication 
  pinSettings();          // Pin Settings Setup

}

void loop() {

  blink();                // Hello World Alcides!!!

}