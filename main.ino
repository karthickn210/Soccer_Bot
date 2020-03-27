#include <Servo.h> // import the servo library
Servo myServo;
int incoming = 0;

void setup() 
{
 myServo.attach(3); // initialize servo pin
 myServo.write(100); // set the servo to 100 degrees
pinMode(13, OUTPUT); // set all the pins as output
pinMode(4, OUTPUT); 
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
Serial1.begin(9600); // connect to Bluetooth module
}
   
void loop() 
{
 if(Serial1.available() > 0) // check if data is available
{
 incoming = Serial1.read(); // read the data
 digitalWrite(13, HIGH);
}

switch(incoming)
{

  case 'F': // move forward
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
break;


case 'B': // move backwards
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
break;

case 'R': // move right
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
break;

case 'L': // move left

digitalWrite(4, LOW);
digitalWrite(5, HIGH);
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
break;

case 'S': // stop

digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
break;

case 'X': // kick
  myServo.write(180);
  delay(750);
  myServo.write(100);
  delay(1000);
  break;
}
}
