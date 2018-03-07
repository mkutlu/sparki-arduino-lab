#include <Sparki.h>
int center_distance,right_distance,left_distance,left_preserve,right_preserve;
char hand;
void setup() {
  // robotu herhangi bir oryantasyonla önünde gördüğü duvara 10 cm yakınlaştır.
    /*sparki.servo(SERVO_CENTER);
    delay (100);
    center_distance = sparki.ping();
    if(center_distance < 10)
      sparki.moveBackward(10-center_distance);
    else
      sparki.moveForward(center_distance-10);
    delay (100);*/
    
    // sol sağ yakın olan tarafı kontrol et
    sparki.servo(SERVO_LEFT);
    delay (500);
    left_distance = sparki.ping();
    delay (500);
    sparki.servo(SERVO_RIGHT);
    delay (500);
    right_distance = sparki.ping();
    delay (500);
    
    if(right_distance>left_distance){ //rotate for left-handy position
        /*sparki.servo(SERVO_CENTER);
        delay (100);
        int min=10000;
        for(int i=0;i<90;i++){
          sparki.servo(-i);
          delay (100);
          int current = sparki.ping();
          if(current<min)
            min = current;
          delay(100);
        }
        sparki.servo(SERVO_CENTER);
        delay (100);
        int rotate_angle = findAngle(min/10);
        sparki.moveRight(90-rotate_angle);
        delay(100);*/
        hand = 'l';

        //Duvar takip ederken koruyacağımız mesafe
        
    }
    else{
      //rotate for right-handy position
      /*
       sparki.servo(SERVO_CENTER);
        delay (100);
        int min=10000;
        for(int i=0;i<90;i++){
          sparki.servo(i);
          delay (100);
          int current = sparki.ping();
          if(current<min)
            min = current;
          delay(100);
        }
        sparki.servo(SERVO_CENTER);
        delay (100);
        int rotate_angle = findAngle(min/10);
        sparki.moveLeft(90-rotate_angle);
        delay(100);*/
        hand='r';
    }    
}

void loop() {
  // now robot must be parallel to wall
  sparki.servo(SERVO_CENTER);
  delay (100);
  center_distance = sparki.ping();
  
  if(center_distance >10){//sola dönüş yok ama sağa eğim olabilir.
    sparki.moveForward(2);
    if(hand=='r'){
      sparki.servo(SERVO_RIGHT);
      delay (100);
      right_distance = sparki.ping();
      delay (100);
      if(right_distance>10)
        sparki.moveRight(3);
      else
        sparki.moveLeft(3);
    }
    else{
        sparki.servo(SERVO_LEFT);
        delay (100);
        left_distance = sparki.ping();
        delay (100);
        if(left_distance>10)
          sparki.moveLeft(3);
        else
          sparki.moveRight(3);
    }
  }
  else{ // duvar ile karşılaşma dönüş
    if(hand=='r'){
      sparki.moveLeft(90);
    }
    else{
      sparki.moveRight(90);
    }
  }
  
   
}

double findAngle(double value){
        return calculateSqrt((int)(7*(1000-1000*value)))-1/2;
}
double calculateSqrt (int n) {      
        double rootValue = 1.00;
        double num = n;
         
        for (int i = 0; i < n; i++) {
             
            rootValue = 0.5 * (rootValue + num/rootValue);
        }   
        int returnValue = (int)(rootValue * 1000);  
        rootValue = returnValue;
        rootValue /=1000;
         
        return rootValue;
}
