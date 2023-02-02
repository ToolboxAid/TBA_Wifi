/*
  TBA_Wifi.cpp - Library for TBA_Wifi code.
  Created by Mr Q, December 2, 2022.
  Released into the public domain.
*/

#ifndef TBA_Wifi_h
#define TBA_Wifi_h

#include "Arduino.h"

#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

class TBA_Wifi
{
public:
  TBA_Wifi();
  void setupWifi();
  void scanWifi();
  void wifiInfo();
  int32_t wifiDB();

private:
  const char *ssid = "change this";
  const char *password = "change this";
  const String default_httpuser = "admin";
  const String default_httppassword = "admin";
  const int default_webserverporthttp = 80;
};

#endif
