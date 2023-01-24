#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define WIFI_SSID "test"
#define WIFI_PASSWORD "bismillahsukses"
const String YOUR_PHONE = "628xxxxxxxxx"; //Without +
const String YOUR_APIKEY = "xxxxxxxxx"; //Your API KEY
const String URL = "https://api.whatabot.net/whatsapp/sendMessage?apikey=xxxxxxx&text=Hello%20from%20Whatabot&phone=628xxxxxx";

String messageToSend = "";

WiFiUDP ntpUDP;


void wifiConnect() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  Serial.println(" ...");
  byte teller = 0;
  while (WiFi.status() != WL_CONNECTED) {  // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++teller);
    Serial.print(' ');
    if (teller % 40 == 0) {
      teller = 0;
      Serial.println();
    }
  }
  Serial.println('\n');
  Serial.println("Connection established");
  Serial.print("IP address: \t");
  Serial.println(WiFi.localIP());
}


void sendWhatsapp(String text) {
  WiFiClient client;
  HTTPClient https;
  String url = URL + text + "&apikey=" + YOUR_APIKEY + "&phone=" + YOUR_PHONE;
  https.begin(client, url);
  int httpCode = https.GET();
  https.end();
}


void setup() {
  Serial.begin(115200);
  
  wifiConnect(); 
}

void loop() {
//  while (Serial.available() == 0)   
//  {   
//    Serial.println("Enter your message: ");  
//    while (Serial.available() == 0) {}  
//    messageToSend = Serial.readString();  
//    
//    Serial.println(messageToSend);
//  }
  
  
//  sendWhatsapp(messageToSend);
}
