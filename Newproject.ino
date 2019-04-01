String readString;
#include<AFMotor.h>
AF_DCMotor motor1(1);//chose the motor
AF_DCMotor motor2(2);//chose the motor



void setup() {
  Serial.begin(9600);
//  myservo.writeMicroseconds(1500); //set initial servo position if desired
 // myservo.attach(7);  //the pin for the servo control 
  Serial.println("HELLO there :D put nummber between 0-255 to run the Motor"); // so I can keep track of what is loaded
  Serial.println("write down 'stop' to stop the Motor");
  motor1.setSpeed(255);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
      Serial.println(readString);  //so you can see the captured string 
      int n = readString.toInt();  //convert readString into a number
      Serial.print("writing: ");
      Serial.println(n);
      motor1.setSpeed(n);
      motor2.setSpeed(n);
      if(n >=0 && n <=255)
      { //analogWrite(analogValue,speed);// what i have to do here 
        motor1.run(FORWARD);
        motor2.run(FORWARD);
       }
       else if (readString = "stop"){
        Serial.print("Motor stop ");
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        }
     readString=""; //empty for next input
     
    } 
}
