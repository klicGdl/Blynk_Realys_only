#include <Arduino.h>
#include "io_expander.h"

#define WIFI_SSID "MEGACABLE-2.4G-55A4"
#define WIFI_PASS "xWdP2SbXMY"
#define BLYNK_TEMPLATE_ID "TMPLmjS3nR7D"
#define BLYNK_DEVICE_NAME "KLIC Test"
#define BLYNK_AUTH_TOKEN "-QZhhsTtiztakhFaa6tAI7GMom2dmIg5"


#if ARDUINO_ARCH_ESP32
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiClient.h>
#elif ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#else
#error "Unsupported ARDUINO architecture"
#endif

BLYNK_CONNECTED () {
  Serial.println("hello -- Blynk connected");
}
 
#define IOEADDRESS  0x38                                       // this is the address if the 3 pins in the IC are tight to ground
#define buttonPin D8


IOExpander IoE;                                               // create an instance of the IO Expander

int buttonState0 = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int i1=0;
int i2=1;
int i3=2;
int i4=3;
int i5=4;

BLYNK_WRITE(V0)
{
  int pinValue0 = param.asInt();
  Serial.print("V0 Slider value is: ");
  Serial.println(pinValue0);
  digitalWrite(buttonState0, pinValue0);
  buttonState0 = digitalRead(pinValue0);    // read the state of the pushbutton value
}
BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue1);
  digitalWrite(buttonState1, pinValue1);
  buttonState1 = digitalRead(pinValue1);    // read the state of the pushbutton value
}

BLYNK_WRITE(V2)
{
  int pinValue2 = param.asInt();
  Serial.print("V2 Slider value is: ");
  Serial.println(pinValue2);
  digitalWrite(buttonState2, pinValue2);
  buttonState2 = digitalRead(pinValue2);    // read the state of the pushbutton value
}
BLYNK_WRITE(V3)
{
  int pinValue3 = param.asInt();
  Serial.print("V3 Slider value is: ");
  Serial.println(pinValue3);
  digitalWrite(buttonState3, pinValue3);
  buttonState3 = digitalRead(pinValue3);    // read the state of the pushbutton value
}
BLYNK_WRITE(V4)
{
  int pinValue4 = param.asInt();
  Serial.print("V4 Slider value is: ");
  Serial.println(pinValue4);
  digitalWrite(buttonState4, pinValue4);
  buttonState4 = digitalRead(pinValue4);    // read the state of the pushbutton value
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
  IoE.init(IOEADDRESS);


}

void loop() {

if (buttonState0 == HIGH) {
    
    IoE.write((IOActionPin_e)i1, buttonState0);
    
  } else {
    
    IoE.write((IOActionPin_e)i1, buttonState0);
  }
  if (buttonState1 == HIGH) {
    
    IoE.write((IOActionPin_e)i2, buttonState1);
    
  } else {
    
    IoE.write((IOActionPin_e)i2, buttonState1);
  }
  
  if (buttonState2 == HIGH) {
    
    IoE.write((IOActionPin_e)i3, buttonState2);
    
  } else {
    
    IoE.write((IOActionPin_e)i3, buttonState2);
  }
  if (buttonState3 == HIGH) {
    
    IoE.write((IOActionPin_e)i4, buttonState3);
    
  } else {
    
    IoE.write((IOActionPin_e)i4, buttonState3);
  }
  if (buttonState4 == HIGH) {
    
    IoE.write((IOActionPin_e)i5, buttonState4);
    
  } else {
    
    IoE.write((IOActionPin_e)i5, buttonState4);
  }

  
 Blynk.run();
 
}
