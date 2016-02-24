int ENA=5;//connected to Arduino's port 5(output pwm)
int IN1=2;//connected to Arduino's port 2
int IN2=3;//connected to Arduino's port 3
int ENB=6;//connected to Arduino's port 6(output pwm)
int IN3=4;//connected to Arduino's port 4
int IN4=7;//connected to Arduino's port 7
int ENC=8;//port8 pwm
int IN5=9;//port9
int IN6=10;//port10
void setup()
{
 pinMode(ENA,OUTPUT);//output
 pinMode(ENB,OUTPUT);
 pinMode(ENC,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(IN5,OUTPUT);
 pinMode(IN6,OUTPUT);
 digitalWrite(ENA,LOW);
 digitalWrite(ENB,LOW);
 digitalWrite(ENC,LOW);//stop driving
 //digitalWrite(IN1,LOW); 
 //digitalWrite(IN2,HIGH);//setting motorA's directon
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);//setting motorB's directon
 digitalWrite(IN5,LOW);
 digitalWrite(IN6,HIGH);//setting motorC's directon
 analogWrite(ENA,255);//start driving motorA
}
void loop()
{
  
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
 
  delay(25);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,HIGH);
  delay(5);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  delay(25);
    digitalWrite(IN2,HIGH);
  digitalWrite(IN1,HIGH);
  delay(5);
  //analogWrite(ENB,255);//start driving motorB
  //analogWrite(ENC,255);//start driving motorC
 
}
