#include "CTBot.h"
#include <SoftwareSerial.h>


CTBot myBot;
SoftwareSerial s1(D6,D5); //rx tx
int statusambulan;
String ssid = "Tamu";     // REPLACE mySSID WITH YOUR WIFI SSID
String pass = "akuanakbaik"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "1005053479:AAFajeHnXMSYeRwXoXI3CtPAXYYGTMSvGpg";   // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN
				

void setup() {
	// initialize the Serial
	Serial.begin(9600);
	Serial.println("Starting TelegramBot...");

	// connect the ESP8266 to the desired access point
	myBot.wifiConnect(ssid, pass);

	// set the telegram bot token
	myBot.setTelegramToken(token);

	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");

}

void loop() {
	// a variable to store telegram message data
	TBMessage msg;
  String reply;
	// if there is an incoming message...
	if (myBot.getNewMessage(msg)) {
		if (msg.text.equalsIgnoreCase("/start")) {
      reply = (String)"Selamat Datang di Trafficbot " + msg.sender.username 
            + (String)"\n /Jalur1 : untuk membuka jalur 1"
            + (String)"\n /Jalur2 : untuk membuka jalur 2"
            + (String)"\n /Jalur3 : untuk membuka jalur 3";
			myBot.sendMessage(msg.sender.id, reply);  
		}
		else if (msg.text.equalsIgnoreCase("/Jalur1")) {      
			myBot.sendMessage(msg.sender.id, "Jalur 1 siap dibuka\n"); 
      Serial.println("jalur 1 buka");
      statusambulan = 1;
      if(s1.available()>0)
        {
          Serial.println(statusambulan);
          s1.write(statusambulan);
		    }
		}else if (msg.text.equalsIgnoreCase("/Jalur2")) {      
     myBot.sendMessage(msg.sender.id, "Jalur 2 siap dibuka\n"); 
      Serial.println("jalur 2 buka");
      statusambulan = 2;
      if(s1.available()>0)
        {
          Serial.println(statusambulan);
          s1.write(statusambulan);
        }
    }else if (msg.text.equalsIgnoreCase("/Jalur3")) {      
     myBot.sendMessage(msg.sender.id, "Jalur 3 siap dibuka\n"); 
      Serial.println("jalur 3 buka");
      statusambulan = 3;
      if(s1.available()>0)
        {
          Serial.println(statusambulan);
          s1.write(statusambulan);
        }
    }else if (msg.text.equalsIgnoreCase("/Semula")) {      
     myBot.sendMessage(msg.sender.id, "Jalur Semula\n"); 
      Serial.println("jalur Semula");
      statusambulan = 0;
      if(s1.available()>0)
        {
          Serial.println(statusambulan);
          s1.write(statusambulan);
        }
    }            
	}
	// wait 500 milliseconds
	delay(200);
}
