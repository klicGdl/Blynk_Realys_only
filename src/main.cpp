#include <Arduino.h>

#include "io_expander.h"

#define WIFI_SSID "MEGACABLE-2.4G-55A4"
#define WIFI_PASS "xWdP2SbXMY"
#define BLYNK_TEMPLATE_ID "TMPLmjS3nR7D"
#define BLYNK_DEVICE_NAME "KLIC Test"
#define BLYNK_AUTH_TOKEN "-QZhhsTtiztakhFaa6tAI7GMom2dmIg5"

#if ARDUINO_ARCH_ESP32
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <WiFiClient.h>
#elif ARDUINO_ARCH_ESP8266
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#else
#error "Unsupported ARDUINO architecture"
#endif

#define IOEADDRESS 0x38  // this is the address if the 3 pins in the IC are tight to ground
#define buttonPin D8

IOExpander IoE;  // create an instance of the IO Expander

int buttonState0 = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int i1 = 0;
int i2 = 1;
int i3 = 2;
int i4 = 3;
int i5 = 4;

BLYNK_CONNECTED() {
  Serial.println("hello -- Blynk connected");
}

BLYNK_WRITE_DEFAULT() {
  uint8_t pin = request.pin;
  int pinValue = param.asInt();
  Serial.println(pinValue);

  switch (pin) {
    case V0:  // Save
      buttonState0 = param.asInt();
      break;
    case V1:
      buttonState1 = param.asInt();
      break;
    case V2:
      buttonState2 = param.asInt();
      break;
    case V3:
      buttonState3 = param.asInt();
      break;
    case V4:
      buttonState4 = param.asInt();
      break;
    default:
      break;
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
  IoE.init(IOEADDRESS);
}

void loop() {

  IoE.write((IOActionPin_e)i1,buttonState0);
  IoE.write((IOActionPin_e)i2,buttonState1);
  IoE.write((IOActionPin_e)i3,buttonState2);
  IoE.write((IOActionPin_e)i4,buttonState3);
  IoE.write((IOActionPin_e)i5,buttonState4);

  Blynk.run();
}
