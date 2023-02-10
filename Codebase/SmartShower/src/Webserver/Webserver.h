#ifndef WEBSERVER_H
#define WEBSERVER_H


#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>

#define SHOWER 26
#define TIMEOUTTIME 2000



class Webserver
{
    private:
    // Replace with your network credentials
    const char* ssid;
    const char* password;
    WiFiServer *server;
    String header;
    String SHOWERState;
    uint64_t previousTime;
    bool alpha;
    bool beta;
    
 
    public:
    Webserver();
    void tick();
    bool getAlpha();
};

#endif