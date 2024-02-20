#include <ArduinoJson.h>

class HTTP {
  public:
  static void begin(String SSID, String PASS);
  static void makeRequest(String url, JsonDocument *doc);
  static String makeRequest(String url);
  static void update();
  private:
  HTTP();
};