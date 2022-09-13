#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define DHTPIN 4 

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11

// Replace with your network credentials
const char* WIFI_SSID = "OPPO A53";
const char* WIFI_PASSWORD = "aniket123";

// Initialize Telegram BOT
#define BOT_TOKEN "5743869194:AAGpk9yK_fIiUn0Ky29TgUrh7Jk2HRb43N0"
#define CHAT_ID "799232282"


WiFiClientSecure secured_client;

UniversalTelegramBot bot(BOT_TOKEN, secured_client);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN, DHTTYPE);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

float t;
//float temperatureF;
float h;


const int Relay1 = 26;
const int Relay2 = 27;




String Relay1State = "HIGH";
String Relay2State = "HIGH";


// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;
//    text.toUpperCase();   
    delay(10);

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/LIGHT1ON:light1on to turn light1 ON \n";
      welcome += "/LIGHT1OFF:light1off to turn light1 OFF \n";
      welcome += "/LIGHT2ON:light2on to turn light2 ON \n";
      welcome += "/LIGHT2OFF:light2off to turn light2 OFF \n";
      welcome += "/tempC : Temperature in celcius \n";
      welcome += "/tempF : Temperature in faranthit\n";
      welcome += "/humidity : Humidity\n";

      welcome += "/state to request current GPIO state \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/LIGHT1ON") {
      bot.sendMessage(chat_id, "Light1 state set to ON", "");
      Relay1State = "ON";
      digitalWrite(Relay1,HIGH);
    }
     if (text == "/LIGHT1OFF") {
      bot.sendMessage(chat_id, "Light1 state set to OFF", "");
      Relay1State = "OFF";
      digitalWrite(Relay1,LOW);
    }
      if (text == "/LIGHT2ON") {
      bot.sendMessage(chat_id, "Light2 state set to ON", "");
      Relay2State =  "ON";
      digitalWrite(Relay2,HIGH);
    }
     if (text == "/LIGHT2OFF") {
      bot.sendMessage(chat_id, "Light2 state set to OFF", "");
      Relay2State ="OFF";
      digitalWrite(Relay2,LOW);
    }
    
///////////////////////////////////////////////////////////////////////////////////// ////////////////////////////////////

 if (text == "LIGHT1STATE") {
     
  bot.sendMessage(chat_id, "Light1 is " + Relay1State + "");
    } 
     if (text == "LIGHT2STATE") {
     
  bot.sendMessage(chat_id, "Light2 is " + Relay2State + "");
    } 

     if (text == "/tempC")
      {   String msg = "Temperature is ";
          msg += msg.concat(t);
          msg += ("°C");
          bot.sendMessage(chat_id,msg, ""); 
      }
      
      if (text == "/humidity")
      {  
          String msg = "Humidity is ";
          msg += msg.concat(h);
          msg += "%"; 
          bot.sendMessage(chat_id,msg, ""); 
      }

       if (text == "/tempC")
      {   // clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,5);
  display.print(t);
   display.print(" ");
  display.setTextSize(1);

  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
    }

  if (text == "/humidity"){
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 15);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 25);
  display.print(h);
  display.print(" %"); 

  display.display(); 
  }
  if (text == "/LIGHT1ON"){
    display.setTextSize(1);
    display.setCursor(0,35);
    display.print("LIGHT1ON: ");
     display.setTextSize(2);
    display.setCursor(0,45);
    display.print("Relay1state");
    display.print("ON") ;
  }
  if (text == "/LIGHT1OFF"){
    display.setTextSize(1);
    display.setCursor(0,50);
    display.print("LIGHT1OFF: ");
     display.setTextSize(2);
    display.setCursor(0,60);
    display.print("Relay1state");
    display.print("OFF");
  }
  if (text == "/LIGHT2ON"){
    display.setTextSize(1);
    display.setCursor(0,70);
    display.print("LIGHT2ON: ");
     display.setTextSize(2);
    display.setCursor(0,80);
    display.print("Relay2state");
    display.print("ON");
  }
if (text == "/LIGHT2OFF"){
    display.setTextSize(1);
    display.setCursor(0,90);
    display.print("LIGHT2OFF: ");
     display.setTextSize(2);
    display.setCursor(0,100);
    display.print("Relay2state");
    display.print("OFF");
}  
  }
}

void setup() {
  Serial.begin(115200);
   Serial.println(F("DHTxx test!"));

  dht.begin();



  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);

 
  digitalWrite(Relay1, LOW);
  digitalWrite(Relay2, LOW);

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}





void loop() {
   h = dht.readHumidity();
  // Read temperature as Celsius (the default)
   t= dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //temperatureF = dht.readTemperature(true);
  
 if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
     lastTimeBotRan = millis();
  }
}
