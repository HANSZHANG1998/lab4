#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  while(1) {
    printf("waitting for reset\n");
    if(digitalRead(0)==1){
    printf("Got a 1\n");
    digitalWrite(2,HIGH);
    digitalWrite(1,LOW);
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/214773840", "Hans", "EECS2031", "NEW MESSAGE");
}
   printf("waitting for event\n");
    if(digitalRead(0) == 0){
    printf("Got a 0\n");
    digitalWrite(2,LOW);
    digitalWrite(1,HIGH);delay(100);
    digitalWrite(1,LOW);}
    printf("Alarm\n");
  }
  return 0 ;
}
