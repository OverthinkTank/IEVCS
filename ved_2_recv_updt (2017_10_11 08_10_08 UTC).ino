#include <SoftwareSerial.h>

int green = 7;
int blue = 12; // red is connected to 13
char inP;

void setup()
{
  Serial.begin(9600);//Setting the baud rate of Serial Monitor
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop()
{

  if (Serial.available())
  {

    inP = Serial.read();//string
    if (inP == '1')
    {

      Serial.write(inP);
      Serial.println("accepted");
      delay(2000);
      digitalWrite(13, LOW);
      digitalWrite(blue, HIGH);
      delay(4000);
      digitalWrite(blue, LOW);
      digitalWrite(green, HIGH);
      delay(10000);
      digitalWrite(green, LOW);
      digitalWrite(13, HIGH);
    }
    Serial.write("2");
  }
}
