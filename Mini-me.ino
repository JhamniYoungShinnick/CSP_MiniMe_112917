//Jhamni Y.S
//12.6.17  
#define trigPin 12 //for ultrasonic sensor
#define echoPin 13
#include <Servo.h>
 Servo myservo1; // for servo motors
 Servo myservo2;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo1.attach(10);
  myservo2.attach(11);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(200);
  }
  delay(200);
  int posL;
  int posR;
  if (distance>18){
    posL = 1500;
    posR = 1500;
  }
  else if(distance<=15){
   posL = 1100;
   posR = 1900;
  }
  myservo1.writeMicroseconds(posL);
  myservo2.writeMicroseconds(posR);
  delay(15);
  }

