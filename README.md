# ESPWebRelay

ESP controlled 4 channel relay module SRD-05VDC-SL-C

To setup environment you will need:

      ☼ ESP8266 
      ☼ Relay module
      ☼ USB or Power Supply 5V 
      ☼ Arduino IDE with ESP8266WiFi library:

Connect pins (review pins layout for your ESP board)

	☼ GPIO5 - Relay 1
	☼ GPIO4 - Relay 2
	☼ GPIO0 - Relay 3
	☼ GPIO13 - Relay 4

! Please pay attention that electric consumer should be connected to NO (normaly open) relay output !
	  
To adapt code please edit this lines -
     
     
     	03   const char* ssid = "Wi-Fi Network Name";  //Input your Wi-Fi SSID 
          	04   const char* password = "Wi-Fi password";  //Input your Wi-Fi password
            26   WiFi.hostname("----"); // Your ESP board network name
		  
 Open in browser http://"ESP board IP address"/
 
 GET query is looks like http://192.168.1.131/relay2on or http://192.168.1.131/relay2off

  
 Please write your comments to improve arduino code
 
 Scheme

![espwebrelay_bb](https://user-images.githubusercontent.com/26871772/32985598-e1c9beba-cccf-11e7-9ab1-12539ad3a3fd.jpg)
