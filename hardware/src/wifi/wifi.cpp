#include "wifi.h"            // Wifi Connection
#include "pinSettings.h"

String espClientIP = "";
String espClientMAC = "";
String espClientMACsimple = "";
String espClientHostname = "";

// Wifi network credentials
const char* ssid     = WIFI_SSID;
const char* password = WIFI_PASSWD;


// Create an WiFiClient class to connect to the MQTT server.
WiFiClient espClient;


void wifiConnect() {
  
  if (WiFi.status() != WL_CONNECTED)
  {
    espClientMAC = String("");
  }

  // Extract Wifi MAC Address
  espClientMAC = String(WiFi.macAddress()).c_str();
  espClientMACsimple = espClientMAC.c_str();
  espClientMACsimple.replace(":", "");

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  
  // Connect in wifi
  WiFi.begin(ssid, password);
  
  // Set Device Hostname
  WiFi.hostname(espClientMACsimple);

  // Extract Wifi IP Address and Hostname
  espClientIP = WiFi.localIP().toString().c_str();
  espClientHostname = WiFi.hostname();

  // Print Wifi Connection Info
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: " + espClientIP);
  Serial.println("Hostname: " + espClientHostname);

}

// Reconnect function
void wifiReconnect()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.reconnect();
  }
}


