#include <Servo.h>
Servo servo;

static int cout1 = 0;
static int cout2 = 0;

// 모터
const int motor1IN1 = 13;
const int motor1IN2 = 12;
const int PWM_ENA = 6; 

// 조이스틱
const int controller = 5;
int posX;
int posY;

// Define Motor list
static int Movement;
const int Forward = 1;
const int Backward = 2;
const int Stop = 3;

void forward()
{
  digitalWrite(motor1IN1,HIGH);
  digitalWrite(motor1IN2,LOW);
}
void backward()
{
  digitalWrite(motor1IN1,LOW);
  digitalWrite(motor1IN2,HIGH);
}
void stop_()
{
  digitalWrite(motor1IN1, LOW);
  digitalWrite(motor1IN2, LOW);
}

void setMotorControl(unsigned int situation, unsigned int PWM_Value)
{
  analogWrite(PWM_ENA,PWM_Value);
  if (situation == Forward){
  forward();
  }
  else if (situation == Stop) {
    backward();
  } 
  else{
    stop_();
  }
}

void setjoycontroller(){
  pinMode(controller, INPUT_PULLUP);
}

void setup() {
  Serial.begin(9600); 
  setjoycontroller();
  // set MotorConifg
  pinMode(motor1IN1 , OUTPUT);      
  pinMode(motor1IN2 , OUTPUT);
  pinMode(PWM_ENA , OUTPUT);
  unsigned int currentPWM = 0;
  analogWrite(PWM_ENA,currentPWM);
}

void control2motor(int X,int Y){
  if(X==HIGH && Y == HIGH ){
    Movement = Stop;
  }
  if(X==LOW && Y == LOW){
    Movement = Forward ;
  }
  if(X==LOW && Y == HIGH){
    Movement = Backward;
  }
}

void loop() {
  int push = digitalRead(controller);
  posX= digitalRead(4);
  posY= digitalRead(2);
  Serial.print("X: ");
  Serial.print(posX);
  Serial.print("y: ");
  Serial.println(posY);
  delay(1000);
  control2motor(posX,posY);
  setMotorControl(Movement,255);
}
