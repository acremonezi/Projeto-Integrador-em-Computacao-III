#ifndef pinSettings_h

    #define pinSettings_h

    // Define the Sensors Pins
    // For ESP8266 use pins 3, 4, 5, 12, 13 or 14 --
    // ----------------------------------------------

    #define DHTPIN    D3    // Pin for DHT Sensor
    #define SDLPIN    D5    // Pin for display
    #define SDAPIN    D6    // Pin for display
    #define LEDCON    D7    // WiFi connected LED
    #define LEDDIS    D8    // WiFi disconnected LED



    // Pin Settings Setup
    void pinSettings();

#endif
