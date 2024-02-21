#include <HTTP.h>

void setup() {
  Serial.begin(115200);
  HTTP::begin("ssid", "password"); // Creates wifi connection
}

void loop() {
  HTTP::update(); // Updates built in LED

  if(Serial.available()) {
    if(Serial.read() == 'q') {

      JsonDocument doc;
      //add second param only if you need a json, if the response is plain text / string use HTTP::makeRequest(url) -> String
      HTTP::makeRequest("https://api.polygon.io/v2/aggs/ticker/AAPL/range/1/day/2023-01-09/2023-01-09?adjusted=true&sort=asc&limit=120&apiKey=s8vjoJaJMQHSGvOMxgBGnwAhl1TU0FLz", &doc);

      String ticker = doc["ticker"];
      int resultsCount = doc["resultsCount"];
      double vw = doc["results"][0]["vw"]; // Only because "results" is a 1 object array where the object is a table. For arrays of regular values, remove the [0].

      Serial.println(doc.as<String>());

      Serial.print("ticker: ");
      Serial.println(ticker);
      Serial.print("resultsCount: ");
      Serial.println(resultsCount);
      Serial.print("vw: ");
      Serial.println(vw);
    }
  }
}