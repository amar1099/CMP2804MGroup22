#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "";
const char* password =  "";
 
void setup() {
 
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin(""); //Specify the URL
    int httpCode = http.GET(); //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        switch (payload)
        {
          case 'out': //send bot out
                    break;
          case 'in': //send bot in
          break;
          default : Serial.println("unrecognized command")
        }
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
 
}
/*
 * Sources
 * https://techtutorialsx.com/2017/05/19/esp32-http-get-requests/
 * https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/protocols/esp_http_client.html
 * https://www.arduino.cc/en/Tutorial/HttpClient
 */
