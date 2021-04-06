#include "mbed.h"
#include "uLCD_4DGL.h"

DigitalIn up(PC_0);
DigitalIn down(PC_1);
DigitalIn confirm(PC_2);

AnalogOut aout(PA_4);

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

void print(float data[], int sample);

int main(void)
{ 
  int s=100;
  int i;       
  int sample = 1000/s;
  float data[sample];  

  while(1){
      
      //if(up==1 && confirm==1){
          //s=s+20;
      //}

      //if(down==1 && confirm==1){
          //s=s-20;
      //}           
      
    for (int i=0; i<sample; i++){     
          aout = 1.0-float(i*1.0/sample*1.0);                   
          data[i] = 3.3 * aout;                               
          ThisThread::sleep_for(1ms);    
      }
      
    }   

  for(int i=0; i<sample; i++){
        printf("%f\r\n", data[i]);
        //ThisThread::sleep_for(1ms);
  }      
  

  //////////////////////////////////////////////////////
  
  //uLCD.text_width(4); //4X size text
  //uLCD.text_height(4);
  //uLCD.locate(1,2);
  //uLCD.printf("%3d",s);   
  
}


//void print(float data[], int sample){  
    //for(int j=0; j<sample; j++){
        //printf("%f\r\n", data[j]);
        //ThisThread::sleep_for(1ms);
    //}   
//}