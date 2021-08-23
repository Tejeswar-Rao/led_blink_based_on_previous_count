#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);

int pb = 10;
int count =0,i;

int led = 8;
int b2 = 9;


void setup() {
  // put your setup code here, to run once:
pinMode(pb,INPUT);
pinMode(b2,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);
}


void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(pb)==HIGH){
    count++;
    lcd.print(count);
    while(digitalRead(pb)==HIGH);
  }
if(digitalRead(b2)==HIGH){
  for(i=0;i<count;i++){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }

 while(digitalRead(b2)==HIGH);
}
}
