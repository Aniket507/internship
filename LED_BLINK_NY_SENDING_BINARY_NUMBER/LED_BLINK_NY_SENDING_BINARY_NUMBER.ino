void setup(){

  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  Serial.begin(9600);
}
void loop(){

  if(Serial.available()>0){
    char state=Serial.read();
    if(state=='0')
    digitalWrite(23,LOW);
    else if(state=='1')
    {
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(27,LOW);
  digitalWrite(14,LOW);
  }
  else if(state=='2')
  {
    digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(27,LOW);
  digitalWrite(14,LOW);
  }
  else if(state=='3')
  {
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(27,LOW);
  digitalWrite(14,LOW);
  }
  else if(state=='4')
  {
    digitalWrite(14,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(27,LOW);
  }
  else if(state=='5')
  {
    digitalWrite(14,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(27,LOW);
  }
  else if(state=='6')
  {
    digitalWrite(14,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(27,LOW);
  digitalWrite(13,LOW);
  }
  else if(state=='7')
  {
  digitalWrite(14,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(27,LOW);
  }
  else if(state=='8')
  {
    digitalWrite(27,HIGH);
  digitalWrite(14,LOW);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  }
  else if(state=='9')
  {
  digitalWrite(27,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(14,LOW);
  digitalWrite(12,LOW);
  }
  }
  delay(1000);
  }
