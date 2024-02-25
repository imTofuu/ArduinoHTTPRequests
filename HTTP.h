#include <Arduino.h>

class HTTP {
public:
  static void begin(String SSID, String PASS);
  //Uses void * to avoid conflicts, use JSON class
  static void makeRequest(String url, void *json);
  static String makeRequest(String url);
  static void update();
private:
  HTTP();
};

class PEAPHTTP : public HTTP {
public:
  static void begin(String SSID, String PASS);
  static void begin(String SSID, String identity, String username, String PASS);
  static void begin(String SSID, String identity, String PASS);
private:
  PEAPHTTP();
};