#include <FastLED.h>

#define BOARD_LED 8
#define DATA_PIN 4
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];

void setup() 
{
  pinMode(BOARD_LED, OUTPUT);
  Serial.begin(115200);
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS); 
  FastLED.setBrightness(200);
}

void loop() 
{
  // Turn the LED on, then pause
  digitalWrite(BOARD_LED, LOW);
  leds[0] = CRGB::Purple;
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  digitalWrite(BOARD_LED, HIGH);
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}
