#include "mbed.h"
#include "uLCD_4DGL.h"

DigitalIn up(PC_0);
DigitalIn down(PC_1);
DigitalIn confirm(PC_2);

AnalogOut aout(PA_4);

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;


int main(void)
{ 
  int s=100;  
  
  if(up==1 && confirm==1){
    s=s+20;
  }

  if(down==1 && confirm==1){
    s=s-20;
  }
  
  float k=(s/1000);  
  ////////*********display uLCD**********////////////////
  uLCD.text_width(4); //4X size text
  uLCD.text_height(4);
  uLCD.locate(1,2);
  uLCD.printf("%2d",s);

  ////////*********waveform**************///////////////
  while(1){
      for (float i=1.0f; i>=0.0f; i=i-0.1){
          aout = 0.9*i; 
          printf("%f\n", aout.read() * 3.3f);        
          ThisThread::sleep_for(1ms);
      }
  }
  //////////////////////////////////////////////////////


}