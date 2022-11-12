#include <Arduino.h>            // Main Arduino Library
#include "pinSettings.h"        // Pin Settings Setup
#include <ESP8266WiFi.h>        // WiFi Library
#include <PubSubClient.h>       // MQTT Library
#include "mqtt.h"               // MQTT Code 
#include "wifi/wifi.h"          // Wifi Code
#include "sensors/DHTxx.h"      // DHTxx Sensor Code
#include <ArduinoJson.h>        // JSON Library


// MQTT Settings
const char *mqtt_username = MQTT_USERNAME;
const char *mqtt_password = MQTT_PASSWD;
const char *mqtt_broker = MQTT_BROKER_SERVER;
const int mqtt_port = MQTT_SERVER_PORT;


PubSubClient client(espClient);


void mqttConnect() {

  // Connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  //client.setCallback(callback);

  

  while (!client.connected()) {

      Serial.printf("The client %s is conneting to the MQTT Broker Server\n", espClientMACsimple.c_str());
      if (client.connect(espClientHostname.c_str(), mqtt_username, mqtt_password)) {




      } else {
          Serial.print("Failed with state: ");
          Serial.print(client.state());
          digitalWrite(LEDDIS, HIGH);
          // delay(2000);
      }
  }
}


void mqttPublish() {

  // Define MQTT Topic
  String device_topic = "sensors/DHTxx/";
  device_topic.concat(espClientMACsimple);

  // Convert String to char
  int stringLength = device_topic.length() + 1; 
  char characterArray[stringLength];
  device_topic.toCharArray(characterArray, stringLength);

  // Define MQTT Topic to Publish
  char *topic = characterArray;


  //Convert float data to strings
  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use https://arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<256> doc;

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument  doc(200);

  // Add values in the document
  doc["Hostname"] = espClientHostname;
  doc["MAC"] = espClientMAC;
  doc["IP"] = espClientIP;
  doc["Topic"] = device_topic;
  doc["Sensor"] = "DHTxx";
  doc["Temperature"] = DHTxxTemperature;
  doc["Humidity"] = DHTxxHumidity;
  doc["HeatIndex"] = DHTxxHeatIndex;
  doc["Battery"] = random(500)/100.5;


  // Generate the minified JSON and send it to the Serial port.
  serializeJson(doc, Serial);

  // Start a new line
  Serial.println();

  char outputJson[256];
  serializeJson(doc, outputJson);
  
  //Publish the data to the topic
  client.publish(topic, outputJson);
  client.loop();
}