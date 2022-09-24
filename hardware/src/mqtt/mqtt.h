#ifndef mqtt_h

    #define mqtt_h
        
        // MQTT Settings
        # define MQTT_BROKER_SERVER "mqtt.bee.espertamente.com.br"
        # define MQTT_SERVER_PORT 1883
        # define MQTT_BROKER "mqtt.bee.espertamente.com.br"
        # define MQTT_USERNAME "espertamente";
        # define MQTT_PASSWD "HRdgDOeKASx2YhxavKBa"

        void mqttConnect();
        void mqttPublish();

        

#endif