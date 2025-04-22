// Uncomment the following line to enable serial debug output
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif

// Include required library
#include <Arduino.h>
#include <WiFi.h>
#include <SinricPro.h>
#include <FastLED.h>
#include "SecretKeys.h"
#include "RGBController.h"

// Sinric Pro Keys
#define APP_KEY SECRET_APP_KEY
#define APP_SECRET SECRET_APP_SECRET
#define DEVICE_ID SECRET_DEVICE_ID

// Wifi Details
#define SSID SECRET_SSID
#define PASS SECRET_PASSWORD

// Serial Console Baud Rate
#define BAUD_RATE 115200

// Addressable LED chipset type
#define LED_TYPE WS2812

// Addressable LED digital pin
#define LED_PIN 4U

// Total number of LEDs
#define NUM_LEDS 99U

// Maximum LED brightness
#define MAX_BRIGHTNESS 50U  // Set Brightness

// Initialize Sinric Pro class variable
RGBController &rgbController = SinricPro[DEVICE_ID];

// Configure FastLED pixel array
CRGB leds[NUM_LEDS];

// ModeController
std::map<String, String> globalModes;

// PowerStateController
bool globalPowerState;

// ModeController
bool onSetMode(const String &deviceId, const String &instance, String &mode)
{
  Serial.printf("[Device: %s]: Modesetting for \"%s\" set to mode %s\r\n", deviceId.c_str(), instance.c_str(), mode.c_str());
  globalModes[instance] = mode;
  return true;
}

// PowerStateController
bool onPowerState(const String &deviceId, bool &state) {
  Serial.printf("[Device: %s]: Powerstate changed to %s\r\n", deviceId.c_str(), state ? "on" : "off");
  globalPowerState = state;
  return true;  // request handled properly
}


// ModeController
void updateMode(String instance, String mode) {
  rgbController.sendModeEvent(instance, mode, "PHYSICAL_INTERACTION");
}

// PowerStateController
void updatePowerState(bool state) {
  rgbController.sendPowerStateEvent(state);
}

void setupSinricPro() 
{
  // ModeController
  rgbController.onSetMode("modeInstance1", onSetMode);
  // PowerStateController
  rgbController.onPowerState(onPowerState);
  SinricPro.onConnected([] {Serial.printf("[SinricPro]: Connected\r\n");});
  SinricPro.onDisconnected([] {Serial.printf("[SinricPro]: Disconnected\r\n");});
  SinricPro.begin(APP_KEY, APP_SECRET);
};

void setupWiFi()
{
  WiFi.setSleep(false);
  WiFi.setAutoReconnect(true);
  WiFi.begin(SSID, PASS);
  Serial.printf("[WiFi]: Connecting to %s", SSID);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("Connected\r\n");
}

void setup() 
{
  Serial.begin(BAUD_RATE);
  setupWiFi();
  setupSinricPro();
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds<LED_TYPE, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 1000);
  FastLED.clear();
  FastLED.show();
}

/********
 * Loop *
 ********/

void loop() 
{
  SinricPro.handle();

  if (globalPowerState)
  {
    if (globalModes["modeInstance1"] == "Solid") { AllOn(0, 0, 255); }
    if (globalModes["modeInstance1"] == "Twinkle") { twinkleAnimation(random(256), 255, 20, 50, 50); }
    if (globalModes["modeInstance1"] == "Shooting Star") { shootingStarAnimation(255, 255, 255, random(10, 60), random(5, 40), random(2000, 8000), 1); }
    if (globalModes["modeInstance1"] == "Rainbow") { rainbowAnimation(20); }
    if (globalModes["modeInstance1"] == "Fade") { fadeAnimation(255, 255, 255); }
  }
  else
  {
    FastLED.clear();
    FastLED.show();
  }
}