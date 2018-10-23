#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{ int a=0;int b=1;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);

 
while(1){

    if(digitalRead(0) == 1 && digitalRead(0)!=a){
    printf("Alarm\n");
    digitalWrite(2,HIGH);
    digitalWrite(1,LOW);
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/214773840", "Hans", "EECS2031", "NEW MESSAGE");
    a = digitalRead(0);
} 

    if(digitalRead(0) == 0 && digitalRead(0)!=b){
    printf("Waiting for reset\n");
   printf("Waiting for event\n");
    digitalWrite(2,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(1,LOW);

} 
b = digitalRead(0);
       

}
  return 0 ;

}

