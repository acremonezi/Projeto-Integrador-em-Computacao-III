#include <Arduino.h>
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup

#include "blink.h"        // Hello World Alcides!!!

void setup() {

  Serial.begin(9600);     // Start Serial Communication 
  pinSetup();             // Pin I/O Mode Setup

}

void loop() {

  blink();                // Hello World Alcides!!!

}