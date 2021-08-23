#include<LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);

int button1 = 10;
int count =0;
int state1 =0,state2=0;
int led = 8;
int b2 = 9,i;
int Button =0,fs2=0,ls2=0;

void setup() {
  // put your setup code here, to run once:
pinMode(button1,INPUT);
pinMode(b2,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Button = digitalRead(b2);
  state1 = digitalRead(button1);
  if(state1!=state2 && state1==HIGH){
    count++;
    lcd.print(count);
    
    delay(500);
  }
state2=state1;
fs2=digitalRead(b2);      
if(fs2!=ls2 && fs2==HIGH)
{
  for(i=0;i<count;i++){
    digitalWrite(led,HIGH);
    delay(500);

    digitalWrite(led,LOW);
    delay(500);
  }
 ls2=fs2;
}
}
