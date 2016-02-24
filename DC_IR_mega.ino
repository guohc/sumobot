#include <DistanceGP2Y0A21YK.h>


DistanceGP2Y0A21YK Dist;
int distance;
int proxy=0;


void setup() {
  Serial.begin(9600);
  Dist.begin(0);
  
}

void loop() {
  distance = Dist.getDistanceCentimeter();  
  distance = distance*2;
  Serial.print("\nDistance in centimers: ");
  Serial.print(distance);
  if (proxy < distance){
    proxy = distance;
  }
Serial.print ("\nClosest: ");
Serial.print (proxy)
  

}

