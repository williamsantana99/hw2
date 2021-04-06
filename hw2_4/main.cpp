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
  int i;       
  int sample = 1000/s;
  float data[sample]; 
  int a=0;

  while(a<100){      
            
    for (int i=0; i<sample; i++){     
          aout = 1.0-float(i*1.0/sample*1.0);                   
          data[i] = 3.3 * aout;  
          a++;
          ThisThread::sleep_for(1ms);    
      }
      
   }  
  
  /////////////////////////////////////////////////////////
  for(int i=0; i<sample; i++){
        printf("%f\r\n", data[i]);
        //ThisThread::sleep_for(1ms);
  }      
  

  //////////////////////////////////////////////////////
  
 }

//void print(float data[], int sample){  
    //for(int j=0; j<sample; j++){
        //printf("%f\r\n", data[j]);
        //ThisThread::sleep_for(1ms);
    //}   
//}
