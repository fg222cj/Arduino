int led1 = 3;           // the pin that the LED1 is attached to
int led2 = 5;           // the pin that the LED2 is attached to
int led3 = 6;           // the pin that the LED3 is attached to
// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 3,5,6 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(16,INPUT);
} 

void loop() {
  int brightness1=analogRead(A0);
  int brightness2=analogRead(A1);

  brightness1=map(brightness1, 0, 1023, 0, 255);
  brightness2=map(brightness2, 0, 1023, 0, 255);
  analogWrite(led1,brightness1);  
  analogWrite(led2,brightness2);

  if(digitalRead(16))
  digitalWrite(4,HIGH);
  else
  digitalWrite(4,LOW);

}
