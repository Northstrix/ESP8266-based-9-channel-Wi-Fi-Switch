// ESP8266-based 9 channel Wi-Fi switch
// Developed by Maxim Bortnikov
// For more information and for the circuit of this device visit: https://github.com/Northstrix/ESP8266-based-9-channel-Wi-Fi-switch
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
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta charset=\"utf-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<title>ESP8266-based 9 channel Wi-Fi switch</title>"); // The name of the web page
  client.println("<head> ");
  client.print("<style>");
  client.print(".button {");
  client.print("background-color: #007BEB;");
  client.print("border: none;");
  client.print("color: white;");
  client.print("padding: 12px 28px;");
  client.print("text-align: center;");
  client.print("text-decoration: none;");
  client.print("display: inline-block;");
  client.print("font-size: 16px;");
  client.print("margin: 4px 2px;");
  client.print("cursor: pointer;");
  client.print("}");
  client.print("   body{");
  client.print("   background-color: #121414;"); // Background color
  client.print("} ");
  client.print("   p {");
  client.print( "   color: white;"); // Text color
  client.print("</style>");
  client.print("</head>");
  client.print("<body>");
  client.print("<table style=""width:100%"" text-align: center;>"); // Creating a table to store all the elements
  client.print("  <tr>");
  client.print("  <th>");
  client.print("<p>ESP8266-based 9 channel Wi-Fi switch</p>");
  client.print("<p>Developed by Maxim Bortnikov</p>");
  client.print("<p>For more information visit: https://github.com/Northstrix/ESP8266-based-9-channel-Wi-Fi-switch </p>");
  client.print("  </th>");
  client.print("  </tr>");
  client.print("  <tr>");
    client.print("<th><p> Channel 1 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch1=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
  client.print("<th><p> Channel 2 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch2=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 3 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch3=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 4 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch4=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 5 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch5=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 6 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch6=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 7 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch7=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 8 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch8=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
    client.print("<th><p> Channel 9 ");
  client.print("  </tr>");
  client.print("  <th>");
  client.println("<a href=\"/ch9=sw\"\" class=button>Switch</a>"); // "Switch" button
  client.print("  </th>");
  client.print(" </tr>");
  client.println("</table>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
