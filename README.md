# ArduinoHTTPRequests

This library was made to simplify HTTP requests by using basic default settings as a tradeoff for code readability and simplicity. 
Should work for any microchips that support the WiFi library.

Currently, there is only support for get requests.\
There is planned future support for:
* Other types of HTTP methods
* XML responses.
* A better, more secure way of logging in to network.

## Usage:

**This documentation applies to this version only. For older versions, read the README.md in the root folder of that version.**

After adding the zip file to library manager, the process of using the library is mostly the same for both types of supported networks
except for the setup. For anyone who needs support, see example.ino (for regular connections) and examplepeap.ino (for peap connections)
or by opening the file or finding them in the examples menu in the Arduino IDE.

Remember to include the correct file:
```c
#include <HTTP.h>
```
**As of v1.1.2, PEAPHTTP.h and HTTP.h have been merged.**

### WPA
Establish the connection (and set the pinmode for the built in led):
```c
void setup() {
  HTTP::begin(ssid, password);
}
```

### PEAP
The connection can be established in 2 different ways. Choose that which applies to your specific network:
```c
void setup() {
  PEAPHTTP::begin(ssid, identity, username, password); // For if your network requires that identity and username be different
  PEAPHTTP::begin(ssid, identity / username, password); // For if your network either does not require a identity / username or if they are the same.
}
```

### Making a Request
For any uses of HTTP, replace with the type you are using (HTTP / PEAPHTTP).

#### Expecting String response
```c
String response = HTTP::makeRequest(url);
```

#### Expecting JSON response
Expecting a JSON response requires a bit more work to get data. For support,
see examples for this library in the Arduino IDE example menu.
```c
JsonDocument doc;
HTTP::makeRequest(url, &doc);
```
##### Example
To print values to Serial from `{"name": "John Doe", "age": 30, "children": 2.5}`:
```c
JsonDocument doc; // Assuming it already contains the example JSON
Serial.println(doc["name"].as<String>()); // Can be String or const char*
Serial.println(doc["age"].as<int>());
Serial.println(doc["children"].as<float>());

//Alternatively
String name = doc["name"];
int age = doc["age"];
float children = doc["children"];

Serial.println(name);
Serial.println(age);
Serial.println(children);
```

## Credits
[ArduinoJson](https://arduinojson.org/) for providing a way to serialize and deserialize 
JSONs. This library was used to make functionality for the methods in JSON.h.