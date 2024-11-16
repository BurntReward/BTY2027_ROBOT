#include<Servo.h>
Servo kapi;
bool kapiAcik=false; 
void kapiyiAc(void)
{
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  for(int d = 5;d<=90;d++)
  {
    kapi.write(d);
    delay(10);
  }
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);

}
      
void kapiyiKapat(void)
{
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  for(int d = 90; d>5;d--)
  {
  kapi.write(d);
  delay(10);
  }
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
}
      
  
void setup(void)
{
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,INPUT);
  pinMode(12,INPUT);
  kapi.attach(3);
  kapi.write(5);
  digitalWrite(7,HIGH);
}
      
void loop(void)
{
  if((digitalRead(8)==1)and(kapiAcik==false))
  {kapiyiAc();kapiAcik=true;}
  if((digitalRead(12)==1)and(kapiAcik==true))
  {kapiyiKapat();kapiAcik=false;}
}
  