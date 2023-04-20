#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// USERNAME WIFI
const char* ssid = "medit";
//PASSWORD WIFI
const char* password = "sayaini1";
const int relay1Pin = D5;
const int relay2Pin = D6;
const int relay3Pin = D7;
const int relay4Pin = D8;

ESP8266WebServer server(80);

void setup() {
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);

  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
  digitalWrite(relay3Pin, LOW);
  digitalWrite(relay4Pin, LOW);

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

  if (server.hasArg("relay1")) {
    if (server.arg("relay1") == "on") {
      digitalWrite(relay1Pin, LOW);
    } else if (server.arg("relay1") == "off") {
      digitalWrite(relay1Pin, HIGH);
    }
  }

  if (server.hasArg("relay2")) {
    if (server.arg("relay2") == "on") {
      digitalWrite(relay2Pin, LOW);
    } else if (server.arg("relay2") == "off") {
      digitalWrite(relay2Pin, HIGH);
    }
  }

  if (server.hasArg("relay3")) {
    if (server.arg("relay3") == "on") {
      digitalWrite(relay3Pin, LOW);
    } else if (server.arg("relay3") == "off") {
      digitalWrite(relay3Pin, HIGH);
    }
  }

  if (server.hasArg("relay4")) {
    if (server.arg("relay4") == "on") {
      digitalWrite(relay4Pin, LOW);
    } else if (server.arg("relay4") == "off") {
      digitalWrite(relay4Pin, HIGH);
    }
  }

  String msg = "";
  msg += "<html><body>\n";
  msg += "<center><h1>Control Relay</h1></center>";
  msg += "<center><p>Meydhi Ari Nugroho</p></center>";
  // Relay 1
  msg += "<center><h2>";
  if (digitalRead(relay1Pin) == LOW) {
    msg += "<a href='?relay1=off'/><button style='appearance: button; backface-visibility: hidden; background-color: #405cf5; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 1 On</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";
  } else {
    msg += "<a href='?relay1=on'/><button style='appearance: button; backface-visibility: hidden; background-color: red; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;''>Relay 1 Off</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";
  }
msg += "</h2></center>";

  // Relay 2
  msg += "<center><h2>";
  if (digitalRead(relay2Pin) == LOW) {
    msg += "<a href='?relay2=off'/><button style='appearance: button; backface-visibility: hidden; background-color: #405cf5; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 2 On</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";
  } else {
    msg += "<a href='?relay2=on'/><button style='appearance: button; backface-visibility: hidden; background-color: red; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 2 Off</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";
  }
  msg += "</h2></center>";

// Relay 3
  msg += "<center><h2>";
  if (digitalRead(relay3Pin) == LOW) {
    msg += "<a href='?relay3=off'/><button style='appearance: button; backface-visibility: hidden; background-color: #405cf5; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 3 On</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";
  } else {
    msg += "<a href='?relay3=on'/><button style='appearance: button; backface-visibility: hidden; background-color: red; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 3 Off</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";
  }
  msg += "</h2></center>";

// Relay 4
  msg += "<center><h2>";
  //if you 
  if (digitalRead(relay4Pin) == LOW) {
    msg += "<a href='?relay4=off'/><button style='appearance: button; backface-visibility: hidden; background-color: #405cf5; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 4 On</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>";    
  } else {
    msg += "<a href='?relay4=on'/><button style='appearance: button; backface-visibility: hidden; background-color: red; border-radius: 6px; border-width: 0; box-shadow: rgba(50, 50, 93, .1) 0 0 0 1px inset,rgba(50, 50, 93, .1) 0 2px 5px 0,rgba(0, 0, 0, .07) 0 1px 1px 0; box-sizing: border-box; color: #fff; cursor: pointer; font-family: -apple-system,system-ui,&quot;Segoe UI&quot;,Roboto,&quot;Helvetica Neue&quot;,Ubuntu,sans-serif; font-size: 100%; height: 44px; line-height: 1.15; margin: 12px 0 0; outline: none; overflow: hidden; padding: 0 25px; position: relative; text-align: center; text-transform: none; transform: translateZ(0); transition: all .2s,box-shadow .08s ease-in; user-select: none; -webkit-user-select: none; touch-action: manipulation; width: 50%;'>Relay 4 Off</button></a>";
    msg += "<script>Apakah anda ingin menyalakan tombol on?</script>"; 
  }
  msg += "</h2></center>";
  msg += "<hr>";
  msg += "<p>This is program that can you using for ESP8266</p>";
  server.send(200, "text/html", msg);
}
