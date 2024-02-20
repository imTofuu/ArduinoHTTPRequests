#include "PEAPHTTP.h"
#include <WiFi.h>

// Only here so PEAPHTTP can extend HTTP.
void PEAPHTTP::begin(String SSID, String PASS) {
  Serial.println("This constructor is not supported for PEAP connections.");
  Serial.print("Consider using HTTP.h for non PEAP connections or correcting ");
  Serial.println("network credentials.");
}

/**********
* Some PEAP connections (like at school) either
* do not require a identity and username, or they
* are the same.
**********/
void PEAPHTTP::begin(String SSID, String identity, String PASS) {
  begin(SSID, identity, identity, PASS);
}

void PEAPHTTP::begin(String SSID, String identity, String username, String PASS) {
  Serial.println("Attempting to connect...");
  WiFi.mode(WIFI_STA); // Set connection mode (STAtion : Connect to a network | AccessPoint : Become a network | APSTA : Both)
  WiFi.begin(SSID, WPA2_AUTH_PEAP, identity, username, PASS);

  while(WiFi.status() != WL_CONNECTED) // Wait until connected
    continue;
  Serial.println("Connected.");
  Serial.print("Local ip:");
  Serial.println(WiFi.localIP());
  pinMode(2, OUTPUT);
}