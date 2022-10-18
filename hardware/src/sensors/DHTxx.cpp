#include <Arduino.h>      // Main Arduino Library
#include "pinSettings.h"  // Pin Settings Setup
#include "DHTxx.h"        // DHTxx Code

#include "DHT.h"          // DHT Sensor Library


#define DHTTYPE DHT22   // For DHT11, just change it to DHT11.

DHT dht(DHTPIN, DHTTYPE);

// Define Variables values:
float DHTxxTemperature = 0;
float DHTxxHumidity = 0;
float DHTxxHeatIndex = 0;

// DHTxx Sensor Setup
void DHTxxSetup() {
  Serial.begin(9600);
  dht.begin();
}

// DHTxx Sensor Readings
void DHTxxRead() {
  
  // delay(1000); // Wait a few seconds between measurements.
  
  DHTxxHumidity = dht.readHumidity();
  DHTxxTemperature = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(DHTxxHumidity) || isnan(DHTxxTemperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  DHTxxHeatIndex = dht.computeHeatIndex(DHTxxTemperature, DHTxxHumidity, false);

 
}


void DHTxxSerialPrint() {
  Serial.print(F("Humidity: "));
  Serial.print(DHTxxHumidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(DHTxxTemperature);
  Serial.print(F("°C  Heat index: "));
  Serial.print(DHTxxHeatIndex);
  Serial.println(F("°C "));
}






  
