#include <Servo.h>                           // Include servo library
#include <Ping.h>

Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
Servo servoTurret;  

// defines pins numbers
int trigPin = 2;    //Trig - green Jumper
int echoPin = 3;    //Echo - yellow Jumper
long duration, cm, inches;

void setup()                                 // Built-in initialization block
{
   //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  tone(4, 3000, 1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone

  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
  servoTurret.attach(11);

  // Full speed forward
  servoLeft.writeMicroseconds(1525);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1475);        // Right wheel clockwise
  
  delay(3000);                               // ...for 3 seconds
  //Serial.println(cmDistance+"   ");
  delay(1000);
  servoLeft.detach();                        // Stop sending servo signals
  servoRight.detach();
  servoTurret.detach();
}  
 
void loop()                                  // Main loop auto-repeats
{
  findShortLong();
  return;
}
int ping(){
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
  return cm;
}
void findShortLong(){
  int distance = ping();
  while(distance >6){
      servoLeft.writeMicroseconds(1525);         // Left wheel counterclockwise
      servoRight.writeMicroseconds(1475);        // Right wheel clockwise
      delay(1000);
      distance = ping();
  }
}

