//Code_Touch

#include <Servo.h>
Servo myServo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int servoPin = 9;
int touchPin = 2;
int led = 4;
void setup() {
  myServo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(touchPin,INPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  int touchValue = digitalRead(touchPin);
  if (touchValue == 1){
  digitalWrite(led,HIGH);
    //if (touchValue == 0){
    delay(2000);
  myServo.write(0);
  delay(5000);
 myServo.write(180);
  delay(3000);  
  }
}
