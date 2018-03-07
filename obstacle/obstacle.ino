#include <Sparki.h>
void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int f_dist,l_dist;
  int count = 0;
  sparki.servo(SERVO_CENTER);
  delay(100);
  f_dist = sparki.ping();
  if(f_dist < 10){
    sparki.moveRight(90);
    l_dist = 0;
    sparki.servo(SERVO_LEFT);
    delay(100);
    while(l_dist < 20){
      sparki.moveForward(3);
      count++;
      l_dist = sparki.ping();
      delay(100);
    }
    sparki.moveForward(10);
    delay(100);
    sparki.moveLeft(90);
    sparki.moveForward(15);
    l_dist=0;
    while(l_dist < 20){
      sparki.moveForward(3);
      delay(100);
      l_dist = sparki.ping();
      delay(100);
    }
    sparki.moveForward(10);
    delay(100);
    sparki.servo(SERVO_CENTER);
    delay(100);
    sparki.moveLeft(90);
    sparki.moveForward(count*3+10);
    sparki.moveRight(90);
  }
  else{
    sparki.moveForward();
  }
  delay(100);
  
}
