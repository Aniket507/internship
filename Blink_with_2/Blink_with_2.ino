void setup ()  
{
  #define L1 27
  #define L2 26
  #define L3 25
  #define L4 33
  #define L5 32
  
pinMode ( L1, OUTPUT);   
pinMode ( L2, OUTPUT);
pinMode ( L3, OUTPUT);
pinMode ( L4, OUTPUT);
pinMode ( L5, OUTPUT); 
}  
void loop ()  
{ 
digitalWrite (L1, HIGH); 

digitalWrite (L2, HIGH);  
delay(100);
digitalWrite (L3, HIGH);
delay(100);
digitalWrite (L4, HIGH);  
delay(100);
digitalWrite (L5, HIGH);  
delay(100);
digitalWrite (L5, LOW);  
delay(100);
digitalWrite (L4, LOW);  
delay(100);
digitalWrite (L3, LOW);  
delay(100);
digitalWrite (L2, LOW);  
delay(100);
digitalWrite (L1, LOW);  
delay(100); 
} 
