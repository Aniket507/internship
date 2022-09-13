
#define BLYNK_TEMPLATE_ID "TMPL0H8Dop0_"
#define BLYNK_DEVICE_NAME "led on off"
#define BLYNK_AUTH_TOKEN "Tc_61z0fwDgXw_u6aCT7lGpjGEIxiOMD"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int pin = 15;
char auth[] = BLYNK_AUTH_TOKEN;       // You should get Auth Token in the Blynk App.
char ssid[] = "OPPO A53";                    // Your Wi-Fi Credentials
char pass[] = "aniket123";

BLYNK_WRITE(V0){
 int pinValue = param.asInt();
 digitalWrite(pin, pinValue);
 Serial.println("RECIEVED");
 Serial.print(pinValue);
}

void setup() {  
  pinMode(pin, OUTPUT); 
//  pinMode(pin, HIGH);
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("WiFi connected");  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop(){
    Blynk.run();
}
