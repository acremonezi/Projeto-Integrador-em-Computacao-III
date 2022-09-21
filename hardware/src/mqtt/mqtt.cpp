#include <Arduino.h>      // Main Arduino Library
#include "pinSettings.h"  // Pin Settings Setup

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "mqtt.h"        // MQTT Code 
#include "wifi/wifi.h"   // Wifi Connection
#include "sensors/DHTxx.h"        // DHTxx Sensor Code
#include <ArduinoJson.h>


String client_id = "";
String device_topic = "";


// MQTT Broker
const char *mqtt_broker = "mqtt.bee.espertamente.com.br";

// ----------------------------------------------------------------
// I am Blocked!!! Please Help!!!
// I am Blocked!!! Please Help!!!
// ----------------------------------------------------------------
// Please, how can I change this string "sensors/DHTxx/" bellow
// for the variable {{{device_topic}}} declared above?
const char *topic = "sensors/DHTxx";              // Worked!
//
//Tests Done:
//const char *topic = &device_topic;                   // Did not even compile the code!
//const char *topic = &device_topic.c_str();           // Did not even compile the code!
//const char *topic = device_topic.c_str();            // Did not Work!
// ----------------------------------------------------------------

const char *mqtt_username = "espertamente";
const char *mqtt_password = "HRdgDOeKASx2YhxavKBa";
const int mqtt_port = 1883;


PubSubClient client(espClient);


void mqttConnect() {
  // Connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  //client.setCallback(callback);

  while (!client.connected()) {

      Serial.printf("The client %s connects to the MQTT Broker\n", client_id.c_str());
      if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {

          // Set Client ID variable by reading Wifi Interface MAC Address
          // client_id = String(WiFi.macAddress());
          client_id = clientMAC;
          client_id.replace(":", "");

          // Set UNIQUE Device Topic for MQTT Plublishing
          device_topic = "sensors/DHTxx/";
          device_topic += client_id;

          Serial.println("MQTT Broker Connected");
          Serial.print("MQTT Device Topic: ");
          Serial.println(device_topic);

      } else {
          Serial.print("Failed with state: ");
          Serial.print(client.state());
          delay(2000);
      }
  }
}


void mqttPublish() {

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
  doc["Device"] = client_id;
  doc["MAC"] = clientMAC;
  doc["IP"] = clientIP;
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


