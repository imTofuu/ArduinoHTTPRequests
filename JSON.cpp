#include "JSON.h"

void JSON::begin(JsonDocument *doc) {
  JSON::contents->length = doc->size();
  JSON::contents->contents = malloc(JSON::contents->length * sizeof(nullptr));
  for(int i = 0; i < doc->size(); i++) {
    JSON::contents->contents[i].content = *(doc)[i];
  }
}

void* JSON::operator[](String s) {
  
}

void* JSON::operator[](unsigned int i) {
  return JSON::contents->contents[i].content;
}