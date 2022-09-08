
#ifdef ESP32
  #include <WiFi.h>
#else

#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "OPPO A53";
const char* password = "aniket123";

// Initialize Telegram BOT
#define BOTtoken "5737854416:AAEFRIoN2TN1AZ0Nss_6v2yk5VQChYN-ijw"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "799232282"

#include <MQ135.h>
MQ135 mq135_sensor(PIN_MQ135);


WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int sensorPin = 23;
bool sensorState = LOW;

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

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + "******"+ ".\n";
      welcome += "Use the following commands to control yourssss outputs.\n\n";
      welcome += "/led_on to turn GPIO ON \n";
      welcome += "/led_off to turn GPIO OFF \n";
      welcome += "/state to request current GPIO state \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/sensor_on") {
      bot.sendMessage(chat_id, "sensor state set to ON", "");
      sensorState = HIGH;
      digitalWrite(sensorPin, sensorState);
    }

    if (text == "/sensor_off") {
      bot.sendMessage("chat_id,  state set to OFF", "");
      sensorState = LOW;
      digitalWrite(sensorPin, sensorState);
    }

    if (text == "/state") {
      if (digitalRead(sensorPin)){
        bot.sendMessage(chat_id, "sensor is ON", "");
      }
      else{
        bot.sendMessage(chat_id, "sensor is OFF", "");
      }
    }
  }
}

void setup() {
  Serial.begin(115200);


  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin,sensorState);

  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
}

void loop() {
//  Serial.println("Running");/

    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
  //  lastTimeBotRan = millis();

}
