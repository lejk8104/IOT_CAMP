#include<Servo.h>
Servo myservo; 
Servo myservoo;
int servoPin = 13;
int servoPpin = 12; //기울기
int pos = 0; 

void setup() {
  
  Serial.begin(9600); /* PC모니터로 결과를 쉽게 확인하기위해 시리얼 통신을 정의해 줍니다.*/   
  myservo.attach(servoPin); //모터
  myservoo.attach(servoPpin); //보조바퀴 모터

  pinMode(11, INPUT); // 10번 핀으로 데이터를 값을 받습니다.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  //======================================각변화식
  pinMode(8, INPUT); // 8번 핀으로 데이터를 값을 받습니다.
  pinMode(7, INPUT); // 7번 핀으로 데이터를 값을 받습니다.
  pinMode(12, OUTPUT);
}

void loop() {
  
    if (digitalRead(7) == LOW && digitalRead(8) == LOW)
  {
    pos = 60;
    myservoo.write(pos);
    delay(15);
  }
  if (digitalRead(7) == HIGH && digitalRead(8) == LOW)
  {
    pos = 30;
    myservoo.write(pos);
    delay(15);
  }
   if (digitalRead(7) == HIGH && digitalRead(8) == HIGH)
  {
    pos = 0;
    myservoo.write(pos);
    delay(15);
  }
/*조건문인 IF문을 사용하여 빛이 차단되면 
  "CDS OFF"문구가 출력 됩니다.*/
  
  if (digitalRead(11) == HIGH) {
    Serial.println("CDS off");  // 빛이차단되면 출력됩니다
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    myservo.write(0);
 delay(500);
  }
 if(digitalRead(11) == LOW){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    myservo.write(90); 
    delay(15);  
 }
 delay(500);
}
