#ifndef DHTxx_h

    #define DHTxx_h

        #include <Arduino.h>
        #include "pinSettings.h"        // Pin Settings Setup

        #include "DHT.h"

        extern DHT dht;

        extern float DHTxxTemperature;
        extern float DHTxxHumidity;
        extern float DHTxxHeatIndex;

        extern String doc;

        void DHTxxSetup();
        void DHTxxRead();
        void DHTxxSerialPrint();

#endif