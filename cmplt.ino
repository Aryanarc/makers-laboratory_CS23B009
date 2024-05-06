#include <Servo.h>
#include <LiquidCrystal.h>
#include <tcs3200.h>

int red, green, blue, white;

tcs3200 tcs(8,9,11,4,10); // (S0, S1, S2, S3, output pin)

LiquidCrystal lcd(2,3,4,8,12,13); //LCD Ports
Servo myservo1; 
int pos = 0;
int sensorPin = 4; 
int threshold = 100; //For proximity
/*RED = 1
GREEN = 2
BLUE = 3*/
int inputcolor1; 
int inputcolor2;

#define S0  8
#define S1  9
#define S2  10
#define S3  2
#define OUT 11

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
// const int RED_LOW = 2500;
// const int RED_HIGH = 4000;
// const int GREEN_LOW = 1500;
// const int GREEN_HIGH = 2500;
// const int BLUE_LOW = 800;
// const int BLUE_HIGH = 1500;


void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Setup Complete");
  myservo1.attach(6);
  pinMode(sensorPin, INPUT_PULLUP);
}
void loop(){
  myservo1.attach(6);
  for(int i=0; i<=180; i+=10){
    myservo1.write(i);
    if(getColor()==inputcolor1){
      lcd.print(getColorName(getColor()));
      moveMiniServo();
    }
    moveMiniServo();
  }
  for(int i=180; i>=0; i-=10){
    myservo1.write(i);
    if(getColor()==inputcolor2){
      moveMiniServo();
      lcd.print(getColorName(getColor()));
    }
  }
}

String getColorName(int color){
  switch(color){
    case 1:
      return "RED";
      break;
    case 2:
      return "GREEN";
      break;
    case 3:
      return "BLUE";
      break;
  }
}


int getColor() {
  red = tcs.colorRead('r');   //reads color value for red
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("    ");
  
  green = tcs.colorRead('g');   //reads color value for green
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("    ");

  blue = tcs.colorRead('b');    //reads color value for blue
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("    ");

  white = tcs.colorRead('c');    //reads color value for white(clear)
  Serial.print("W(clear)= ");
  Serial.print(white);
  Serial.print("    ");

  Serial.println();

  delay(200);
  if(red>blue && red>green){
    digitalWrite(3,HIGH);
    return 1;
  }else if(green>red && green>blue){
    digitalWrite(4,HIGH);
    return 2;
  }else{
    digitalWrite(5,HIGH);
    return 3;
  }
}

void moveMiniServo() {
  Servo myservo;
  myservo.attach(5);
  for (int pos = 0; pos <= 180; pos++) {
    myservo.write(pos);
    delay(20);
    if (detectObject()) {
      break;
    }
  }
  
  for(int pos = 180; pos>=0; pos--){
    myservo.write(pos);
    delay(20);
    if(detectObject()){
      break;
    }
  }
}

bool detectObject() {
  int sensorValue = analogRead(sensorPin);
  if (sensorValue < threshold) {
    return true;
  } else {
    return false;
  }
}