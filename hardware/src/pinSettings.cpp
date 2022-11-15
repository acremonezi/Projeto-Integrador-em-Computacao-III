#include <Arduino.h>      // Main Arduino Library
#include "pinSettings.h"  // Pin Settings Setup

// Pin I/O Mode Setup
void pinSettings() {

    // Define the Digital Outputs
    // ----------------------------------------------
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LEDCON, OUTPUT);
    pinMode(LEDDIS, OUTPUT);
}