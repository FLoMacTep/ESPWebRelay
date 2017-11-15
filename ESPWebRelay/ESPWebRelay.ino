#include <ESP8266WiFi.h>
 
const char* ssid = "Wi-Fi Network Name";
const char* password = "Wi-F password";
 
; // 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(13, HIGH);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.hostname("SkyNet-ESP-01-R");
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
 
  if (request.indexOf("/relay1on") > 0)  {
    digitalWrite(5, LOW);
   
  }
  if (request.indexOf("/relay1off") >0)  {
    digitalWrite(5, HIGH);
   
  }

   if (request.indexOf("/relay2on") > 0)  {
    digitalWrite(4, LOW);
   
  }
  if (request.indexOf("/relay2off") >0)  {
    digitalWrite(4, HIGH);
   
  }
    if (request.indexOf("/relay3on") >0)  {
    digitalWrite(0, LOW);
   
  }
  if (request.indexOf("/relay3off") > 0)  {
    digitalWrite(0, HIGH);
   
  }
   if (request.indexOf("/relay4on") > 0)  {
    digitalWrite(13, LOW);
   
  }
  if (request.indexOf("/relay4off") > 0)  {
    digitalWrite(13, HIGH);
   
  }
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
  client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
 client.println("</head>");
  client.println("<body bgcolor = \"#7db6d1\">"); 
  client.println("<hr/><hr>");
  client.println("<h4><center> Esp8266 Electrical Device Control </center></h4>");
  client.println("<hr/><hr>");
  client.println("<br><br>");
  client.println("<br><br>");
  client.println("<center>");
  client.println("Relay 1");
  client.println("<a href=\"/relay1on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/relay1off\"\"><button>Turn Off </button></a><br />");  
  client.println("</center>");   
  client.println("<br><br>");
   client.println("<center>");
   client.println("Relay 2");
  client.println("<a href=\"/relay2on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/relay2off\"\"><button>Turn Off </button></a><br />");  
client.println("</center>"); 
  client.println("<br><br>");
    client.println("<center>");
   client.println("Relay 3");
  client.println("<a href=\"/relay3on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/relay3off\"\"><button>Turn Off </button></a><br />");  
client.println("</center>"); 
  client.println("<br><br>");
   client.println("<center>");
   client.println("Relay 4");
  client.println("<a href=\"/relay4on\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/relay4off\"\"><button>Turn Off </button></a><br />");  
client.println("</center>"); 
  client.println("<br><br>");
  client.println("<center>");
  client.println("<table border=\"5\">");
 client.println("<tr>");
  if (digitalRead(5))
         { 
           client.print("<td>Relay 1 is OFF</td>");
        
         }
          else
          {
            client.print("<td>Relay 1 is ON</td>");
      
        }
     
        client.println("<br />");
             
         if (digitalRead(4))
          { 
           client.print("<td>Relay 2 is OFF</td>");

         }
          else
          {

            client.print("<td>Relay 2 is ON</td>");

          }
          client.println("</tr>");


          client.println("<tr>");

          if (digitalRead(0))

          { 
           client.print("<td>Relay 3 is OFF</td>");

          }

          else

          {
            client.print("<td>Relay 3 is ON</td>");
          }


          if (digitalRead(13))


          { 


           client.print("<td>Relay 4 is OFF</td>");

          }


          else


          {


            client.print("<td>Relay 4 is ON</td>");


          }

          client.println("</tr>");


          client.println("</table>");

          client.println("</center>");
  client.println("</html>"); 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
