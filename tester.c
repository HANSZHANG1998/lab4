#include <stdio.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
/*
  ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/56-YpOKO17vOh-gimC2xK1qRAhRdzXXXX", "my1", "my 2", "my 333334");
*/

  printf("Trying to connect to server\n");
  ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/214773840", "Hans", "EECS2031", "NEW MESSAGE");
  return 0;
}
