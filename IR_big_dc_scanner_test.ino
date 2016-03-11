#include <DistanceGP2Y0A21YK.h>


DistanceGP2Y0A21YK Dist;
int distance;
int proxy = 100;
int led = 13;
int i = 0;


void setup() {
  Serial.begin(9600);
  Dist.begin(0);
  pinMode(led, OUTPUT);
}

void loop() {
  distance = Dist.getDistanceCentimeter();
  distance = distance * 2;
  if (distance <= 80) {
    for (i = 0; i <= distance; i++) {
      Serial.print("|");
    }
  }
  else {
    Serial.print("----------------------------------------------");
  }
  Serial.print("\nDistance in centimers: ");
  Serial.print(distance);
  //  if (distance > 10 && proxy > distance ){
  //    proxy = distance;
  //  }
  //Serial.print ("  Closest: ");
  //Serial.print (proxy);
  if (proxy <= 14) {
    digitalWrite(led, HIGH);
  }


}

