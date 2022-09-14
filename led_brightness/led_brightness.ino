#define BLYNK_TEMPLATE_ID "TMPLbUWd6nP9"
#define BLYNK_DEVICE_NAME "led brightness"
#define BLYNK_AUTH_TOKEN "yt446J5YR7Qo2gUhQ88zMflxRX6uIYtN" 
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int pin = 15;
char auth[] = BLYNK_AUTH_TOKEN;       // You should get Auth Token in the Blynk App.
char ssid[] = "OPPO A53";                    // Your Wi-Fi Credentials
char pass[] = "aniket123";
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
void loop()
{
  Blynk.run();
}

 BLYNK_WRITE(V0){
 int pinValue = param.asInt();
 analogWrite(pin, pinValue);
 Serial.println("RECIEVED");
 Serial.print(pinValue);
 }
