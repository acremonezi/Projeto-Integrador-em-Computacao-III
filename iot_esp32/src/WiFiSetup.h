#ifndef WiFiSetup_h

  #define WiFiSetup_h

  extern char ssid[];
  extern char pass[];
  //extern int status;

  // Setup WiFi Interface
  void WiFiSetup();
  void printCurrentNet();
  void printWifiData();

#endif