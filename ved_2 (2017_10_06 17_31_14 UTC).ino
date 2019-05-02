 #include <SoftwareSerial.h>
String a;//for input from RFID
int i = 1;
//SoftwareSerial mySerial(9,10);//RX,TX
SoftwareSerial mySerialRF(11,12);//RX,TX
void setup()
{
  
  Serial.begin(9600); //Setting the baud rate of Serial Monitor 
  /*while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }*/
  //mySerial.begin(9600); // Setting the baud rate of Software Serial Library  
  mySerialRF.begin(9600); // Setting the baud rate of Software Serial Library  
 }
void loop()
{
    
 if(mySerialRF.available())
 {
    a = mySerialRF.readString();
    if(a == "5300B8BC4611")
    {
      Serial.println(i);
    //  mySerial.write(i);//send to remote over hc12
      digitalWrite(13,HIGH);
      delay(3000);
      digitalWrite(13,LOW);
    }
 // Serial.write(mySerial.read());
  }
}
