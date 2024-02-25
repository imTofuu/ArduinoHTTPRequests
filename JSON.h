#include <ArduinoJson.h>

namespace HTTPStructs {
  struct JSONObject {
    void* content;
  };

  struct JSONContents {
    JSONObject *contents;
    unsigned int length;
  };
}
class JSON {
public:
  JSON();

  void begin(JsonDocument *doc);

  void* operator[](String s);
private:
  HTTPStructs::JSONContents *contents;

  void increaseSize();
};