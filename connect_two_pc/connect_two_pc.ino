void setup(){

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(14,OUTPUT);
  Serial.begin(9600);
  Serial2.begin(115200);
}
void loop()
{

  if(Serial2.available()>0)
  {
    int n=Serial2.read();
    switch(n)
    {
case '0': digitalWrite(13,HIGH);
         digitalWrite(12,LOW);
         digitalWrite(27,LOW);
         digitalWrite(14,LOW);
         Serial.println("zero");
         Serial2.println("SUCCESED");
         break;

case '1': digitalWrite(13,LOW);
         digitalWrite(12,HIGH);
         digitalWrite(27,LOW);
         digitalWrite(14,LOW);
         Serial.println("ONE");
         Serial2.println("SUCCESED");
         break;
         
case '2': digitalWrite(13,HIGH);
         digitalWrite(12,HIGH);
         digitalWrite(27,LOW);
         digitalWrite(14,LOW);
         Serial.println("TWO");
         Serial2.println("SUCCESED");
         break;
         
case '3': digitalWrite(13,LOW);
         digitalWrite(12,LOW);
         digitalWrite(27,HIGH);
         digitalWrite(14,LOW);
         Serial.println("THREE");
         Serial2.println("SUCCESED");
         break;
         
case '4': digitalWrite(13,HIGH);
         digitalWrite(12,LOW);
         digitalWrite(27,HIGH);
         digitalWrite(14,LOW);
         Serial.println("FOUR");
         Serial2.println("SUCCESED");
         break;
         
case '5': digitalWrite(13,LOW);
         digitalWrite(12,HIGH);
         digitalWrite(27,HIGH);
         digitalWrite(14,LOW);
         Serial.println("FIVE");
         Serial2.println("SUCCESED");
         break;
         
case '6': digitalWrite(13,HIGH);
         digitalWrite(12,HIGH);
         digitalWrite(27,HIGH);
         digitalWrite(14,LOW);
         Serial.println("SIX");
         Serial2.println("SUCCESED");
         break;
         
case '7': digitalWrite(13,LOW);
         digitalWrite(12,LOW);
         digitalWrite(27,LOW);
         digitalWrite(14,HIGH);
         Serial.println("SEVEN");
         Serial2.println("SUCCESED");
         break;
         
case '8': digitalWrite(13,HIGH);
         digitalWrite(12,LOW);
         digitalWrite(27,LOW);
         digitalWrite(14,HIGH);
         Serial.println("EIGHT");
         Serial2.println("SUCCESED");
         break;
         
case '9': digitalWrite(13,LOW);
         digitalWrite(12,HIGH);
         digitalWrite(27,LOW);
         digitalWrite(14,HIGH);
         Serial.println("NINE");
         Serial2.println("SUCCESED");
         break;
         
case 'A': digitalWrite(13,HIGH);
         digitalWrite(12,HIGH);
         digitalWrite(27,LOW);
         digitalWrite(14,HIGH);
         Serial.println("TEN");
         Serial2.println("SUCCESED");
         break;
         
case 'B': digitalWrite(13,LOW);
         digitalWrite(12,LOW);
         digitalWrite(27,HIGH);
         digitalWrite(14,HIGH);
         Serial.println("ELEVEN");
         Serial2.println("SUCCESED");
         break;
         
case 'C': digitalWrite(13,HIGH);
         digitalWrite(12,LOW);
         digitalWrite(27,HIGH);
         digitalWrite(14,HIGH);
         Serial.println("TWELVE");
         Serial2.println("SUCCESED");
         break;
         
case 'D': digitalWrite(13,LOW);
         digitalWrite(12,HIGH);
         digitalWrite(27,HIGH);
         digitalWrite(14,HIGH);
         Serial.println("THIRTEEN");
         Serial2.println("SUCCESED");
         break;
         
case 'E': digitalWrite(13,LOW);
         digitalWrite(12,LOW);
         digitalWrite(27,HIGH);
         digitalWrite(14,HIGH);
         Serial.println("FOURTEEN");
         Serial2.println("SUCCESED");
         break; 
         
case 'F': digitalWrite(13,HIGH);
         digitalWrite(12,HIGH);
         digitalWrite(27,HIGH);
         digitalWrite(14,HIGH);
         Serial.println("FIFTEEN");
         Serial2.println("SUCCESED");
         break;
  default:Serial.println("Invalid condition");
          Serial2.println("valid condition=0-9 and A to F");
    }
  }
}  
