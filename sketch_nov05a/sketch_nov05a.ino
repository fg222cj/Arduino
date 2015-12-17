/*
 RGB LED Color Changing
 This example shows how to change the color of a RGB LED
 using the analogWrite() function.
  */

int led1 = 3;           // the pin that the LED1 is attached to
int led2 = 5;           // the pin that the LED2 is attached to
int led3 = 6;           // the pin that the LED3 is attached to
// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 3,5,6 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
int i,j,k=0;
  for(i=0;i<10;i++)
 {
  analogWrite(led1, i*25);
    for(j=0;j<10;j++)
    {
     analogWrite(led2, j*25);
       for(k=0;k<10;k++)
       { 
        analogWrite(led3, k*25);
        delay(10);
       }
    }
 }
}
