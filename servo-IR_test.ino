#include <DistanceGP2Y0A21YK.h>
#include <Servo.h>

DistanceGP2Y0A21YK Dist;
int distance;
int pos=0;
Servo myservo;

void setup() {
  Serial.begin(9600);
  Dist.begin(0);
  myservo.attach(2);
  myservo.write(0);
  delay(500);
  
}

void loop() {
  distance = Dist.getDistanceCentimeter();
  Serial.print("\nDistance in centimers: ");
  Serial.print(distance);
  distance = distance*2;
  pos = pos +3;
  myservo.write(pos);
  if (distance <30){
    pos = pos - 4;
  }
  if (pos >170){
    pos = 0;
  }


}
