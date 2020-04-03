/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  NOTE:
  BlynkTimer provides SimpleTimer functionality:
    http://playground.arduino.cc/Code/SimpleTimer

  App project setup:
    Value Display widget attached to Virtual Pin V5
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define aref_voltage 3.3


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a23584e57c144bbe8d4bcf5633f31576";

// Your WiFi credentials.a23584e57c144bbe8d4bcf5633f31576
// Set password to "" for open networks.
char ssid[] = "FreeboxLB";
char pass[] = "uQsy4blRnJnLHpra";

float tempReading = 0;

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial

// or Software Serial on Uno, Nano...
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

// Set your ESP-01 baud rate to 9600 with this command AT+UART_DEF=9600,8,1,0,0
// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,0,100), 8442);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
  analogReference(EXTERNAL);
}

void loop()
{
  tempReading = analogRead(0);  
 
  // converting that reading to voltage, which is based off the reference voltage
  float voltage = tempReading * aref_voltage;
  voltage /= 1024.0; 
 
  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 - 2;
  Serial.print(temperatureC);
  Blynk.virtualWrite(0, temperatureC);
  Serial.print("\n\r");
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

  
  /*tmp = analogRead(0) * aref_voltage;
  Blynk.virtualWrite(0, (tmp*(5000/1024)-500)/10);
  Serial.print((tmp*(5000/1024)-500)/10);
  Serial.print("\n\r");
  Blynk.run();
  timer.run(); // Initiates BlynkTimer*/
}
