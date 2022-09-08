#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Wifi network station credentials
#define WIFI_SSID "OPPO A53"
#define WIFI_PASSWORD "aniket123"
// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5790034183:AAHQguwHziAq8WBdZQ_fMjDUQfWPHTObfeE"
#define chat_id "799232282"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

#define trigger_pin 5
#define echo_pin 18
long duration;
int distance;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(trigger_pin,OUTPUT);
  digitalWrite(echo_pin,INPUT);

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
}

void loop()
{
   digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
   delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW); 
  duration=pulseIn(echo_pin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance\n");
  Serial.print(distance);
  Serial.print("cm");
  delay(1000);
  String Dist = "Distance : "+ String(distance)+"cm";
  
  

  
  
   bot.sendMessage(chat_id, Dist, "");
}
