#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// USERNAME WIFI
const char* ssid = "Wifi Username";
//PASSWORD WIFI
const char* password = "Password Your Wifi";
const int relay3Pin = D7;

ESP8266WebServer server(80);

void setup() {
  pinMode(relay3Pin, OUTPUT);
  digitalWrite(relay3Pin, LOW); // Ensure the relay is initially off

  Serial.begin(9600);
  connectToWiFi();

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void connectToWiFi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void handleRoot() {
  Serial.println("Got a Request");

  if (server.hasArg("relay3")) {
    if (server.arg("relay3") == "on") {
      digitalWrite(relay3Pin, LOW);  // Activate the relay (assuming LOW activates the relay)
    } else if (server.arg("relay3") == "off") {
      digitalWrite(relay3Pin, HIGH); // Deactivate the relay
    }
  }

  String msg = "<html><body>\n";
  msg += "<center><h1>Control Relay 3</h1></center>";

  // Relay 3
  msg += "<center><h2>";
  if (digitalRead(relay3Pin) == LOW) {
    msg += "<a href='?relay3=off'/><button style='appearance: button; background-color: red; border-radius: 6px; color: #fff; padding: 0 25px;'>Relay 3 Off</button></a>";
  } else {
    msg += "<a href='?relay3=on'/><button style='appearance: button; background-color: #405cf5; border-radius: 6px; color: #fff; padding: 0 25px;'>Relay 3 On</button></a>";
  }
  msg += "</h2></center>";

  msg += "</body></html>";
  server.send(200, "text/html", msg);
}
