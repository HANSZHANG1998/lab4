
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
 
int main(int argc, char *argv[])
{
    char path[50] = "/sys/bus/w1/devices/";
    char rom[20];
    char buf[100];
    DIR *dirp;
    struct dirent *direntp;
    int fd =-1;
    char *temp;
    float value;
    int lowtemp = 40;
    int hightemp = 0; 
  int tempstate = 0;
   int temper =0;   
 char a[20],b[20],c[20];
    if((dirp = opendir(path)) == NULL)
    {   
        printf("opendir error\n");
        return 1;
    }
    while((direntp = readdir(dirp)) != NULL)
    {   
         if(strstr(direntp->d_name,"28-021313482eaa"))
        {   
            strcpy(rom,direntp->d_name);
            printf(" rom: %s\n",rom);
        }
    }
    closedir(dirp);
    strcat(path,rom);
    strcat(path,"/w1_slave");
    while(1)
    {   
        if((fd = open(path,O_RDONLY)) < 0)
        {   
            printf("open error\n");
            return 1;
        }
     if(read(fd,buf,sizeof(buf)) < 0)
        {   
            printf("read error\n");
            return 1;
        }
               temp = strchr(buf,'t');
        sscanf(temp,"t=%s",temp);
    value = atof(temp)/1000;
         temper = (int)value;
  if(temper<=lowtemp){
 lowtemp = temper;
}       
if(temper>=hightemp){
hightemp = temper;
}

 if(temper != tempstate){ printf(" Temperature : %d °C Highest Temperature : %d °C Lowest Temperature : %d °C;\n",temper,hightemp,lowtemp);
   sprintf(a, "Highest temp %d °C", hightemp);   
    sprintf(b, "Temp now %d °C", temper); 
 sprintf(c, "Lowest temp %d °C", lowtemp);  
  ifttt("https://maker.ifttt.com/trigger/event/with/key/c_fSJ1txFjQCh0w1yFkUyqUIcst9v8ezlx0ap9G_LCM",a,b,c);


}
   tempstate = temper;
        
}
    return 0;
}

