#ifndef wifi_h

    #define wifi_h
        #include <Arduino.h>              // Main Arduino Library
        #include <ESP8266WiFi.h>
        
        extern WiFiClient espClient;
        extern String clientIP;
        extern String clientMAC;

        void wifiConnect();

#endif
