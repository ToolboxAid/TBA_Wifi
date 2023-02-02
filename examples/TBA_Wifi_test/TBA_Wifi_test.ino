
#include "Arduino.h"
#include "TBA_Wifi.h"

TBA_Wifi wifi = TBA_Wifi();
void setup()
{
  // Use serial port
  Serial.begin(115200);
  while (!Serial && (millis() <= 1000))
  {
  };

  wifi.scanWifi();
  wifi.setupWifi();
  wifi.wifiInfo();
}

void loop()
{
  Serial.print("Wifi Strength: ");
  Serial.print(wifi.wifiDB());
  Serial.println(" dBm");
  
  delay(250); // Slow down loop
  yield();    // Allow WDT to reset
}
