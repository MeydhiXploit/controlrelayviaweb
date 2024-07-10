#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// USERNAME WIFI
const char* ssid = "medit";
// PASSWORD WIFI
const char* password = "sayaini1";
const int relayPin = D5;

ESP8266WebServer server(80);

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

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

  if (server.hasArg("relay")) {
    if (server.arg("relay") == "on") {
      digitalWrite(relayPin, LOW);
    } else if (server.arg("relay") == "off") {
      digitalWrite(relayPin, HIGH);
    }
  }

  String msg = "";
  msg += "<html><body>\n";
  msg += "<center><h1>Control Relay</h1></center>";
  msg += "<center><p>Meydhi Ari Nugroho</p></center>";
  msg += "<center><h2>";
  if (digitalRead(relayPin) == LOW) {
    msg += "<a href='?relay=off'/><button style='appearance: button; backface-visibility: hidden; background-color: #405cf5; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay On</button></a>";
  } else {
    msg += "<a href='?relay=on'/><button style='appearance: button; backface-visibility: hidden; background-color: red; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay Off</button></a>";
  }
  msg += "</h2></center>";
  msg += "<hr>";
  msg += "<p>This is a program that you can use for ESP8266</p>";
  server.send(200, "text/html", msg);
}
