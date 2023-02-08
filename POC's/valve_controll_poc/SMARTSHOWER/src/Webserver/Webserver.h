#ifndef WEBSERVER_H
#define WEBSERVER_H


#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>

#define OUTPUT26 26
#define OUTPUT27 27
#define TIMEOUTTIME 2000



class Webserver
{
    private:
    // Replace with your network credentials
    const char* ssid;
    const char* password;
    WiFiServer *server;
    String header;
    String OUTPUT26State;
    String OUTPUT27State;
    uint64_t previousTime;
    bool alpha;
    bool beta;
    
 
    public:
    Webserver();
    void tick();
    bool getAlpha();
    bool getBeta();
};

#endif