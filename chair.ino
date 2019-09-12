#include <Keypad.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}
  
void loop()
{
  char key = keypad.getKey();
  if (Serial.available()>0)
   if(key =='1')
  
  {

      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+919884616665\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("module check from sk");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);

  }
  else if(key=='4')
  {
    Serial.print("sk");
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
        
