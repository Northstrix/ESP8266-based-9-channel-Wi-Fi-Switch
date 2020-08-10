// ESP8266-based 9 channel Wi-Fi switch with "New Look" interface
// Developed by Maxim Bortnikov
// For more information and for the circuit of this device visit: https://github.com/Northstrix/ESP8266-based-9-channel-Wi-Fi-switch
// Button template was designed by masuwa. You can find it here: https://codepen.io/ma_suwa/pen/qBBYKNy
#include <ESP8266WiFi.h> 
const char* ssid     = "Blackberry";  // Your SSID (Network's name)
const char* password = "seasidehills99"; // Password from your network
int ch1 = 14; // pin D5
int ch2 = 12; // pin D6
int ch3 = 13; // pin D7
int ch4 = 15; // pin D8
int ch5 = 16; // pin D0
int ch6 = 5;  // pin D1
int ch7 = 4;  // pin D2
int ch8 = 0;  // pin D3
int ch9 = 2;  // pin D4
WiFiServer server(80);

void setup(){
  
  Serial.begin(115200); // Baudrate
  pinMode(ch1, OUTPUT); // Setting all 9 pins as OUTPUTS
  digitalWrite(ch1, LOW); // Setting 0 to all 9 pins
  pinMode(ch2, OUTPUT);
  digitalWrite(ch2, LOW);
  pinMode(ch3, OUTPUT);
  digitalWrite(ch3, LOW);
  pinMode(ch4, OUTPUT);
  digitalWrite(ch4, LOW);
  pinMode(ch5, OUTPUT);
  digitalWrite(ch5, LOW);
  pinMode(ch6, OUTPUT);
  digitalWrite(ch6, LOW);
  pinMode(ch7, OUTPUT);
  digitalWrite(ch7, LOW);
  pinMode(ch8, OUTPUT);
  digitalWrite(ch8, LOW);
  pinMode(ch9, OUTPUT);
  digitalWrite(ch9, LOW);
  Serial.print("Connecting to the Newtork"); // This all will be displayed in the Serial Monitor
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
  server.begin(); // Starting the server
  Serial.println("Server started");
  Serial.print("IP Address of network: ");
  Serial.println(WiFi.localIP());
  Serial.println("/");
}

 

void loop(){

  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())  
  {
    delay(1);
  } 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  if(request.indexOf("/ch1=sw") != -1)

  {
    digitalWrite(ch1, HIGH); // Switch the state of the 1st channel
    delay(1);
    digitalWrite(ch1, LOW);
  }
  if(request.indexOf("/ch2=sw") != -1)

  {
    digitalWrite(ch2, HIGH); // Switch the state of the 2nd channel
    delay(1);
    digitalWrite(ch2, LOW);
  }
    if(request.indexOf("/ch3=sw") != -1)

  {
    digitalWrite(ch3, HIGH); // Switch the state of the 3rd channel
    delay(1);
    digitalWrite(ch3, LOW);
  }
    if(request.indexOf("/ch4=sw") != -1)

  {
    digitalWrite(ch4, HIGH); // Switch the state of the 4th channel
    delay(1);
    digitalWrite(ch4, LOW);
  }
    if(request.indexOf("/ch5=sw") != -1)

  {
    digitalWrite(ch5, HIGH); // Switch the state of the 5th channel
    delay(1);
    digitalWrite(ch5, LOW);
  }
  if(request.indexOf("/ch6=sw") != -1)

  {
    digitalWrite(ch6, HIGH); // Switch the state of the 6th channel
    delay(1);
    digitalWrite(ch6, LOW);
  }
    if(request.indexOf("/ch7=sw") != -1)

  {
    digitalWrite(ch7, HIGH); // Switch the state of the 7th channel
    delay(1);
    digitalWrite(ch7, LOW);
  }
    if(request.indexOf("/ch8=sw") != -1)

  {
    digitalWrite(ch8, HIGH); // Switch the state of the 8th channel
    delay(1);
    digitalWrite(ch8, LOW);
  }
      if(request.indexOf("/ch9=sw") != -1)

  {
    digitalWrite(ch9, HIGH); // Switch the state of the 9th channel
    delay(1);
    digitalWrite(ch9, LOW);
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html"); // All below is a web page code written in HTML
  client.println("");
  client.println("<!DOCTYPE html>\n"
"<html>\n"
"  <head>\n"
"    <style>\n"
"  * {\n"
"  margin: 0;\n"
"  padding: 0;\n"
"}\n"
"\n"
"html,\n"
"body {\n"
"  box-sizing: border-box;\n"
"  height: 100%;\n"
"  width: 100%;\n"
"}\n"
"\n"
"body {\n"
"  background: #121414;\n"
"  font-family: Segoe UI,Frutiger,Frutiger Linotype,Dejavu Sans,Helvetica Neue,Arial,sans-serif; \n"
"  font-weight: 400;\n"
"}\n"
"\n"
".buttons {\n"
"  display: flex;\n"
"  flex-direction: row;\n"
"      flex-wrap: wrap;\n"
"  justify-content: center;\n"
"  text-align: center;\n"
"  width: 100%;\n"
"  height: 100%;\n"
"  margin: 0 auto;\n"
"/*   padding: 2em 0em; */\n"
"}\n"
"\n"
".container {\n"
"  display: inline-block;\n"
"  align-items: center;\n"
"  display: flex;\n"
"  flex-direction: column;\n"
"  justify-content: top;\n"
"  text-align: center;\n"
"  background-color: #EEE;\n"
"  padding:  40px 0px;\n"
"  width: 300px;\n"
"}\n"
"\n"
"h1 {\n"
"  text-align: center;\n"
"  color: #444;\n"
"  letter-spacing: 0.05em;\n"
"  margin: 0 0 0.4em;\n"
"  font-size: 1em;\n"
"}\n"
"\n"
"p {\n"
"  text-align: left;\n"
"  color: #444;\n"
"  letter-spacing: 0.05em;\n"
"  font-size: 0.8em;\n"
"  margin: 0 0 2em;\n"
"}\n"
"\n"
"\n"
".btn {\n"
"  letter-spacing: 0.1em;\n"
"  cursor: pointer;\n"
"  font-size: 14px;\n"
"  font-weight: 400;\n"
"  line-height: 45px;\n"
"  max-width: 160px;\n"
"  position: relative;\n"
"  text-decoration: none;\n"
"  text-transform: uppercase;\n"
"  width: 100%;\n"
"}\n"
".btn:hover {\n"
"  text-decoration: none;\n"
"}\n"
"\n"
"/*btn_background*/\n"
".effect04 {\n"
"  --uismLinkDisplay: var(--smLinkDisplay, inline-flex);\n"
"  display: var(--uismLinkDisplay);\n"
"  color: #000;\n"
"  outline: solid  2px #000;\n"
"  position: relative;\n"
"  transition-duration: 0.4s;\n"
"  overflow: hidden;\n"
"}\n"
"\n"
".effect04::before,\n"
".effect04 span{\n"
"    margin: 0 auto;\n"
"\ttransition-timing-function: cubic-bezier(0.86, 0, 0.07, 1);\n"
"\ttransition-duration: 0.4s;\n"
"}\n"
"\n"
"/* 文字1を上に */\n"
".effect04:hover{\n"
"\n"
"  background-color: #007BEB;\n"
"}\n"
"\n"
"/* HOVERしたら文字1を上に */\n"
".effect04:hover span{\n"
"  -webkit-transform: translateY(-400%) scale(-0.1,20);\n"
"          transform: translateY(-400%) scale(-0.1,20);\n"
"}\n"
"\n"
"/*文字2*/\n"
".effect04::before{\n"
"  content: attr(data-sm-link-text);\n"
"\tcolor: #FFF;\n"
"  position: absolute;\n"
"  left: 0;\n"
"  right: 0;\n"
"  margin: auto;\n"
"  -webkit-transform: translateY(500%) scale(-0.1,20);\n"
"          transform: translateY(500%) scale(-0.1,20);\n"
"}\n"
"\n"
"/* HOVERしたら文字2を上に */\n"
".effect04:hover::before{\n"
"  letter-spacing: 0.05em;\n"
"  -webkit-transform: translateY(0) scale(1,1);\n"
"          transform: translateY(0) scale(1,1);\n"
"}\n"
"    \n"
"</style>\n"
"    <meta charset=\"utf-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width\">\n"
"    <title>ESP8266-based 9 channel Wi-Fi switch</title>\n"
"    \n"
"  </head>\n"
"  <body>\n"
"  <div class=\"buttons\">\n"
"  <div class=\"container\">\n"
"      <h1>ESP8266-based 9 channel Wi-Fi switch</h1>\n"
"      <p>Developed by Maxim Bortnikov</p>\n"
"            <p>Channel 1</p>\n"
"      <a href=\\\"/ch1=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 2</p>\n"
"      <a href=\\\"/ch2=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 3</p>\n"
"      <a href=\\\"/ch3=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 4</p>\n"
"      <a href=\\\"/ch4=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 5</p>\n"
"      <a href=\\\"/ch5=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 6</p>\n"
"      <a href=\\\"/ch6=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 7</p>\n"
"      <a href=\\\"/ch7=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 8</p>\n"
"      <a href=\\\"/ch8=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"            <p>Channel 9</p>\n"
"      <a href=\\\"/ch9=sw\\\"\\\" class=\"btn effect04\" data-sm-link-text=\"Switch\"><span>ON/OFF</span></a>\n"
"      </br>\n"
"  </div>\n"
"</div>\n"
"  </body>\n"
"</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
