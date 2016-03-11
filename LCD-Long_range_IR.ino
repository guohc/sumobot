#include <GP2Y0A02YK0F.h>
#include <LiquidCrystal.h>
#include <DFR_Key.h>
#include <DistanceGP2Y0A21YK.h>

DistanceGP2Y0A21YK Dist;
GP2Y0A02YK0F irSensor;
int distance;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

DFR_Key keypad;

int KeyPress = 0;
String keyString = "";


String SensorType[3] = {"GP2Y0A21YK0F", "GP2Y0A02YK0F", "GP2Y0A41SK0F"};
int i = 0;
int x;
int missing = 0;
int sensor = 0;
int SensorPicked = 1;
int selected = 0;

void setup()
{
  Serial.begin(9600);
  irSensor.begin(A1);  //  Assign A0 as sensor pin
  Dist.begin(A1);
  keypad.setRate(300);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance v1.0");
  lcd.setCursor(0, 1);
  lcd.print("By Leo");
  delay(1000);



};

void loop()
{

  while (selected != 1) {
    delay(60);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Sensor:");
    lcd.setCursor(0, 1);
    lcd.print(SensorType[sensor]);
    KeyPress = keypad.getKey();
    switch (KeyPress) {
      case 1:
        SensorPicked = sensor;
        selected = 1;
        break;
      case 3:
        sensor --;
        delay(200);
        break;
      case 4:
        sensor ++;
        delay(200);
        break;
      default:
        delay(10);
        break;
    }
    if (sensor == -1) {
      sensor = 2;
    }
    else if (sensor == 3) {
      sensor = 0;
    }
  }
  delay(300);

  switch (sensor) {
    case 0:
      distance = Dist.getDistanceCentimeter();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Distance:");
      lcd.setCursor(9, 0);
      lcd.print(distance);
      lcd.setCursor(0, 1);
      if (distance <= 100) {
        for (i = 0; i <= distance; i = i +2) {
          lcd.print("|");
        }
      }
      break;
    case 1:
      distance = irSensor.getDistanceCentimeter();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Distance:");
      lcd.setCursor(9, 0);
      lcd.print(distance);
      lcd.setCursor(0, 1);
      if (distance <= 100) {
        for (i = 0; i <= distance; i = i + 5) {
          lcd.print("|");
        }
      }
      break;
    case 2:
      while (missing == 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Missing data");
        lcd.setCursor(0, 1);
        lcd.print("sheet");
        delay (1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Raw voltage");
        lcd.setCursor(0, 1);
        lcd.print("out put");
        delay (1500);

        KeyPress = keypad.getKey();
        if (KeyPress == 1) {
          missing = 1;
        }
      }
      x = analogRead (1);
      Serial.print (x);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Voltage:");
      lcd.setCursor(9, 0);
      lcd.print(x);

      break;
  }


}
