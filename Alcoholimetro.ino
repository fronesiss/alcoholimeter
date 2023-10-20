#include <Servo.h>

byte pinB1 = 2;
byte pinB2= 3;
byte pinBotCom= 4;

byte led1 = 5;
byte ledC1 = 6;
byte ledC2 = 7;
byte led2 = 8;


bool estadoB1;
bool estadoB2;
bool estadoB3;

Servo servo1;
Servo servo2;

void setup()
{
  pinMode(pinB1,INPUT);
  pinMode(pinB2,INPUT);
  pinMode(pinBotCom,INPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(ledC1,OUTPUT);
  pinMode(ledC2,OUTPUT);


  
  servo1.attach(9);
  servo2.attach(10);
  
  Serial.begin(9600);
}

void loop()
{
  estadoB1 = digitalRead(pinB1);
  estadoB2 = digitalRead(pinB2);
  estadoB3 = digitalRead(pinBotCom);

    
  if(estadoB1 == 1)
  {
    digitalWrite(led1, HIGH);
    servo1.write(90);

  }
  
  else
  {
    digitalWrite(led1, LOW);   
    servo1.write(0);
  }
   
  
  
  if(estadoB2 == 1)
  {
    digitalWrite(led2, HIGH);
    servo2.write(90);

  }
  
  else
  {
    digitalWrite(led2, LOW);   
    servo2.write(0);

  }  
  
  
   if(estadoB3 == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(ledC1, HIGH);
    digitalWrite(ledC2, HIGH);


    servo1.write(90);
    servo2.write(90);

  }
  
   else
  {
    
    digitalWrite(ledC1, LOW);
    digitalWrite(ledC2, LOW);

  }  
  
  Serial.print(estadoB1);
  Serial.print(" --- " );
  Serial.print(estadoB2);
  Serial.print(" --- " );
  Serial.println(estadoB3);

}
