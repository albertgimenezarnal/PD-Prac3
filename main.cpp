
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>


extern String HTML; 
// SSID & Password
const char* ssid = "Xiaomi_11T_Pro";  // Enter your SSID here
const char* password = "f5cbd8a82232";  //Enter your Password here
void handle_root();
WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

void setup() {
  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100); 
}

void loop() {
  server.handleClient();
}


// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}


