#include "HardwareSerial.h"
#include "HTTP.h"
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "JSON.h"
#include <ArduinoJson.h>

/*************
* Gathers credentials about the wifi network
* and connects to it. Uses the WiFi library
* to make connection.
*************/
void HTTP::begin(String SSID, String PASS) {

  Serial.println("Attempting to connect...");
  WiFi.mode(WIFI_MODE_STA);  // Set connection mode (STAtion : Connect to a network | AccessPoint : Become a network | APSTA : Both)
  WiFi.begin(SSID, PASS);

  while (WiFi.status() != WL_CONNECTED)  // Wait until connected
    continue;
  Serial.println("Connected");
  Serial.print("Local ip: ");
  Serial.println(WiFi.localIP());
  pinMode(2, OUTPUT);
}

void HTTP::update() {  // Turn on led when wifi is connected
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

/*************
* Function for making a request and expecting a json in response.
* Needs pointer to JSON instance to write to.  Uses WiFi
* library to check connection.
*************/
void HTTP::makeRequest(String url, void *json) {
  if (WiFi.status() == WL_CONNECTED) {  // Make sure wifi is still connected

    // Deserialise response string into a JSON
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, makeRequest(url));

    if (error) {
      Serial.println("Failed to deserialize JSON.");
    }
  } else {
    Serial.println("Wifi is not connected.");
  }
}

/*************
* Function for making a request and expecting a string response.
* Needs url to esablish the http connection. Uses HTTPClient
* library to make request and WiFi library to check connection, which
* are included when downloading ESP32 from board manager I think
*************/
String HTTP::makeRequest(String url) {
  if (WiFi.status() == WL_CONNECTED) {  // Make sure wifi is still connected
    HTTPClient http;
    http.begin(url);

    int code = http.GET();
    if (code == HTTP_CODE_OK) {  // Make sure the request returned a valid response. If not, print the error code.
      return http.getString();
    } else {
      Serial.print("HTTP response was not normal. Code:");
      Serial.println(code);
    }

    http.end();
  }
}