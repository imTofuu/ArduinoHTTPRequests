#include "HTTP.h"

class PEAPHTTP : public HTTP {
  public:
  static void begin(String SSID, String PASS);
  static void begin(String SSID, String identity, String username, String PASS);
  static void begin(String SSID, String identity, String PASS);
  private:
  PEAPHTTP();
};