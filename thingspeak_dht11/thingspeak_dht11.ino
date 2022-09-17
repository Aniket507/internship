#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
 
const char *ssid =  "OPPO A53";  
const char *pass =  "aniket123";

#define D5 4
 
DHT dht(D5, DHT11);
 
WiFiClient client;
 
long myChannelNumber = 1863215;
const char myWriteAPIKey[] = "48IW87RBQE6XV3PB";
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  ThingSpeak.begin(client);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + (String) t);
  Serial.println("Humidity: " + (String) h);
  ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(2000);
}
