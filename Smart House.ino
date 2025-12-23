
int led2 = 2;
int echo = 4;
int trig = 3; 
int d ; 
int t ;
int val ;
float temperature ;
#include <Servo.h>

Servo myservo;  
int pos = 0;   

void setup() {
  Serial.begin(9600) ;
  myservo.attach(9);

  pinMode(led2,OUTPUT);
    
  pinMode(trig , OUTPUT) ;
 pinMode(echo ,INPUT) ;
 pinMode(A0,INPUT);
}

void loop() { digitalWrite(trig ,LOW) ;
  delayMicroseconds(5) ;
  digitalWrite(trig ,HIGH) ;
  delayMicroseconds(5) ;
   digitalWrite(trig ,LOW) ;
  delayMicroseconds(5) ;
  
  t= pulseIn(echo,HIGH) ;
  d= (0.0343*t)/2 ;
  if(d<20) {
     myservo.write(0);
     
    
  }
  else{myservo.write(90);}
  val=analogRead(A0) ;
  temperature = val * (5.0 / 1023.0 * 100.0);
    Serial.println(d);
    delay(200);
     

  if(temperature>30 ){
    digitalWrite(led2,HIGH);
    
  }
  else {
   digitalWrite(led2,LOW);
   
  
             
    
}
}
