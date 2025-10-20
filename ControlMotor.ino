#include<Servo.h>
#define x_pin A0
#define y_pin A1
#define hardcoded_vcc A2
#define hardcoded_gnd A3


Servo myservo;

void setup(){
  Serial.begin(9600);
  pinMode(hardcoded_vcc, OUTPUT);
  pinMode(hardcoded_gnd, OUTPUT);

  digitalWrite(hardcoded_vcc, HIGH);
  digitalWrite(hardcoded_gnd, LOW);
  myservo.attach(6);

}


void loop(){
  int x_value = analogRead(x_pin);
  int y_value = analogRead(y_pin);
  int angle = map(x_value, 0, 1023, 0 , 180);
  myservo.write(angle);
  delay(20);
  Serial.print("(");
  Serial.println(x_value);
  Serial.print(",");
  Serial.println(y_value);
  Serial.print(")");
  delay(250);

}
