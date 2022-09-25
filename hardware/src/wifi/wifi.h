#ifndef wifi_h

    #define wifi_h
        #include <Arduino.h>              // Main Arduino Library
        #include <ESP8266WiFi.h>
        
        // Wifi Connectivity Settings
        #define WIFI_SSID "Quantum_IoT"
        #define WIFI_PASSWD "Y7Q9vD8V10b!!!"

        extern WiFiClient espClient;

        extern String espClientIP;
        extern String espClientMAC;
        extern String espClientMACsimple;
        extern String espClientHostname;

        void wifiConnect();

#endif
