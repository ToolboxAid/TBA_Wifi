/*
  TBA_Wifi.cpp - Library for TBA_Wifi code.
  Created by Mr Q, December 2, 2022.
  Released into the public domain.
*/

#include "Arduino.h"
#include "TBA_Wifi.h"

TBA_Wifi::TBA_Wifi()
{
}

void TBA_Wifi::setupWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
//    Serial.print(".");
  }
  /*
     if (WiFi.waitForConnectResult() != WL_CONNECTED) {
         Serial.printf("WiFi Failed!\n");
         return;
     }
  */
}

int32_t  TBA_Wifi::wifiDB(){
  return WiFi.RSSI();
}
void TBA_Wifi::wifiInfo()
{
  Serial.println("-----------------------");
  Serial.println("Network Configuration:");
  Serial.println("- - - - - - - - - - - -");

  Serial.print("         SSID: ");
  Serial.println(WiFi.SSID());
  Serial.print("  Wifi Status: ");
  Serial.println(WiFi.status());
  Serial.print("Wifi Strength: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  Serial.print("          MAC: ");
  Serial.println(WiFi.macAddress());
  Serial.print("           IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("       Subnet: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("      Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("        DNS 1: ");
  Serial.println(WiFi.dnsIP(0));
  Serial.print("        DNS 2: ");
  Serial.println(WiFi.dnsIP(1));
  Serial.print("        DNS 3: ");
  Serial.println(WiFi.dnsIP(2));
}

/* Need to change this to return a list of networks & then remove println*/
void TBA_Wifi::scanWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int networks = WiFi.scanNetworks();
  if (networks == 0)
  {
    Serial.println("-----------------------");
    Serial.println("no networks found");
    Serial.println("- - - - - - - - - - - -");

  }
  else
  {
    Serial.println("-----------------------");
    Serial.print(networks);
    Serial.println(" networks found");
    Serial.println("- - - - - - - - - - - -");

    for (int  network = 0;  network < networks; ++network)
    {
      // Print SSID and RSSI for each network found
      Serial.print( network + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID( network));
      Serial.print(" (");
      Serial.print(WiFi.RSSI( network));
      Serial.print(")");
      Serial.println((WiFi.encryptionType( network) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }

  Serial.println("- - - - - - - - - - - -");
  Serial.println("scan done");
  Serial.println("- - - - - - - - - - - -");
}
