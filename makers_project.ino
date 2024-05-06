1)
int blinkGap = 1000;
void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(blinkGap);
  digitalWrite(13, LOW);
  delay(blinkGap); 
}


2)
int blinkGap = 1000;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(blinkGap);
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  delay(blinkGap); 
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(blinkGap);
}

3)

int blinkGap = 1000;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(7)==HIGH){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}


4)


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
}

void loop()
{
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  
  if(digitalRead(7)==HIGH){
    digitalWrite(11, HIGH);
  }
 
  if(digitalRead(8)==HIGH){
    digitalWrite(12, HIGH);
  }
  
  if(digitalRead(9)==HIGH){
    digitalWrite(13, HIGH);
  }
  
}

5)

int blinkGap = 1000;
void setup()
{
}

void loop()
{
  analogWrite(3, 255);
  analogWrite(5, 0);
  analogWrite(6, 0);
  delay(blinkGap);
  
  analogWrite(3, 0);
  analogWrite(5, 255);
  analogWrite(6, 0);
  delay(blinkGap); 
  
  analogWrite(3,0);
  analogWrite(5, 0);
  analogWrite(6, 255);
  delay(blinkGap);
}


6)
int wait = 10;
void setup()
{
  
}

void loop()
{
  //PART A : increasing along
  
  for(int i = 0 ; i < 255 ; i++){
  analogWrite(3,i);
    delay(wait);
  }
  
  delay(1000);
  
  //PART B : increasing and then decreasing
   for(int i = 0 ; i < 255 ; i++){
  analogWrite(3,i);
     delay(wait);
  }
  delay(1000);
   for(int i = 255 ; i >=0 ; i--){
  analogWrite(3,i);
     delay(wait);
  }
  delay(1000);
  
}

7)int wait = 10;
void setup()
{
  
}

void loop()
{
  
  
  for(int i = 0 ; i < 255 ; i++){
  analogWrite(3,i);
    delay(wait);
  }
  analogWrite(3,0);
  for(int i = 0 ; i < 255 ; i++){
  analogWrite(5,i);
    delay(wait);
  }
  analogWrite(5,0);
   
  for(int i = 0 ; i < 255 ; i++){
  analogWrite(6,i);
    delay(wait);
  }
  analogWrite(6,0);
  
}

8)
int wait = 0.00000001;
void setup()
{
}

void loop()
{
  //PART A : increasing along
  
  for(int i = 0 ; i < 255 ; i++){
    for(int j = 0 ; j < 255 ; j++){
      for (int k=0 ; k < 255 ; k++){
        analogWrite(3,i);
        analogWrite(5,j);
        analogWrite(6,k);
        delay(wait);
      }
    }
  }
  
}

9)

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello World!!");
}

void loop()
{
 
}

10)

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(analogRead(A2));
  delay(1000);
}

11)
void setup()
{
  pinMode(3,OUTPUT);
  Serial.beegin(9600);
}
void loop()
{
  / Read the value from the potentiometer
    int potValue = analogRead(A2);
    int redIntensity = map(potValue, 0, 1023, 0, 255);
  
  analogWrite(3, redIntensity);
  
  Serial.print(potValue);
  Serial.println(redIntensity);
}

12)
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,8,12,13);

void setup()
{
  lcd.begin();
}
void loop()
{
lcd.print("Hello");
}

13)
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,8,12,13);
void setup()
{
lcd.begin();
Serial.begin(9600);
}
void loop()
{
lcd.print(analogRead(A3);
}

14)
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,8,12,13);
const int threshold = 100;
void setup()
{
lcd.begin();
pinMode(13,OUTPUT);
Serial.begin();

}
void loop()
{
lcd.print(analogRead(A3));
lcd.setCursor(0,1);
if(analogRead(A3)>threshold){
Serial.println("ON");
lcd.print("ON");
}else{
Serial.println("OFF");
lcd.println("OFF");
}
delay(2000);
}

15)
#include <Servo.h>

Servo myservo;
void setup()
{
myservo.attach(5);
}
void loop()
{
for(int i=0; i<=180; i+=10){
myservo.write(i);
delay(50);
}
}

16)
#include <Servo.h>

Servo servo;
void setup()
{
servo.attach(5);
}
void loop()
{
int potvalue = analogRead(A3);
int angle = map(potvalue,0,1023,0,180);
servo.write(angle);
delay(50);
}

17)
#include <Servo.h>
Servo servo;
int pos=0;
void setup()
{
pinMode(7,INPUT_PULLUP);
pinMode(8,INT=PUT_PULLUP);
servo.attach(5);
}
void loop()
{
if(digitalRead(7)==LOW){
pos=pos+2;
servo.write(pos);
}
if(digitalRead(8)==LOW){
pos=pos-2;
servo.write(pos);
}
}

18)

void setup()
{
Serial.begin(9600);
}
void loop()
{
Serial.print(analogRead(A4);
delay(2000);
}

19)
void setup()
{
pinMode(11,OUTPUT);
pinMode(A4,INPUT);
}
void loop()
{
if(analogRead(A4)>100){
digitalWrite(11,LOW);
}else{
digitalWrite(11,HIGH);
}
}

20)

#include <Servo.h>
Servo servo;
void setup()
{
servo.attach(5);
}
void loop()
{
for(int i=0; i<=180; i+=10){
if(objectDetect()){
break;
}
}
}

bool objectDetect()
{
if(analogRead(A4)>100){
return true;
}
else{
return false;
}
}
