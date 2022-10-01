#ifndef wifi_h

    #define wifi_h
        #include <Arduino.h>              // Main Arduino Library
        #include <ESP8266WiFi.h>
        #include "secrets.h"
        

        extern WiFiClient espClient;

        extern String espClientIP;
        extern String espClientMAC;
        extern String espClientMACsimple;
        extern String espClientHostname;

        void wifiConnect();
        void wifiReconnect();

#endif
