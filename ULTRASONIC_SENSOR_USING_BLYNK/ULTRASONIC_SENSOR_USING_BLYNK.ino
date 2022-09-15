#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_TEMPLATE_ID "TMPLlTFHSo9S"
#define BLYNK_DEVICE_NAME "ULTRASONIC SENSOR"
#define BLYNK_AUTH_TOKEN "x18CAkQRPlkr2KwcOf8nYICbPgNq12rc"
#include <BlynkSimpleEsp32.h>

#define  trig  32
#define  echo  33

long duration;
int distance;


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "OPPO A53";  
char pass[] = "aniket123"; 

BlynkTimer timer;

void setup()
{
  // Debug console
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);   
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

 timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
void sendSensor()
{
  digitalWrite(trig, LOW);   
  delayMicroseconds(2);       
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);      
  digitalWrite(trig, LOW);   
  duration = pulseIn(echo, HIGH);   
  distance = duration * 0.034 / 2;  

  Serial.print("Distance = ");        
  Serial.println(distance);


  Blynk.virtualWrite(V0, distance);
  delay(1000);                        //Pause for 3 seconds and start measuring distance again
}
