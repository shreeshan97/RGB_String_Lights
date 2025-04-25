// Uncomment the following line to enable serial debug output
#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#endif


// Include librarys
#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <SinricPro.h>
#include <WS2812FX.h>

 // Include headers
#include "RGBController.h"
#include "RGBControllerInit.h"
#include "Defaults.h"
#include "SecretKeys.h"

// Sinric Pro Keys
#define APP_KEY SECRET_APP_KEY
#define APP_SECRET SECRET_APP_SECRET
#define DEVICE_ID SECRET_DEVICE_ID

// Wifi Details
#define SSID SECRET_SSID
#define PASS SECRET_PASSWORD

// Initialize Sinric Pro class variable
RGBController &rgbController = SinricPro[DEVICE_ID];

// Set RGB LED class
WS2812FX ws2812fx = WS2812FX(NUM_LEDS, LED_PIN, NEO_RGB + NEO_KHZ400); 

// ModeController
std::map<String, String> globalModes;

// ModeController
bool onSetMode(const String &deviceId, const String &instance, String &mode)
{
  Serial.printf("[Device: %s]: Modesetting for \"%s\" set to mode %s\r\n", deviceId.c_str(), instance.c_str(), mode.c_str());
  globalModes[instance] = mode;
  return true;
}

// ModeController
void updateMode(String instance, String mode)
{
  rgbController.sendModeEvent(instance, mode, "PHYSICAL_INTERACTION");
}

void setupSinricPro(void) 
{
  // ModeController
  rgbController.onSetMode("modeInstance1", onSetMode);
  SinricPro.onConnected([] {Serial.printf("[SinricPro]: Connected\r\n");});
  SinricPro.onDisconnected([] {Serial.printf("[SinricPro]: Disconnected\r\n");});
  SinricPro.begin(APP_KEY, APP_SECRET);
};

void processCommands(void)
{
  static String last_command = "";
  if(globalModes["modeInstance1"] != last_command)
  {
    if (globalModes["modeInstance1"] == "Off") { ws2812fx.stop(); rgbControl.effect = eEFFECT_STATIC; rgbControl.cycle = false; }
    if (globalModes["modeInstance1"] == "White") { rgbControl.colour = WHITE; rgbControl.effect = eEFFECT_STATIC; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Maximum Speed") { rgbControl.brightness = MAX_SPEED; rgbControl.flag = true; }
    if (globalModes["modeInstance1"] == "Medium Speed") { rgbControl.brightness = MID_SPEED; rgbControl.flag = true; }
    if (globalModes["modeInstance1"] == "Minimum Speed") { rgbControl.brightness = MIN_SPEED; rgbControl.flag = true; }
    if (globalModes["modeInstance1"] == "Maximum Brightness") { rgbControl.brightness = MAX_BRIGHTNESS; rgbControl.flag = true; }
    if (globalModes["modeInstance1"] == "Medium Brightness") { rgbControl.brightness = MID_BRIGHTNESS; rgbControl.flag = true; }
    if (globalModes["modeInstance1"] == "Minimum Brightness") { rgbControl.brightness = MIN_BRIGHTNESS; rgbControl.flag = true; }
    if (globalModes["modeInstance1"] == "Random") { rgbControl.effect = eEFFECT_RANDOM; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Multi Dynamic") { rgbControl.effect = eEFFECT_MULTI_DYNAMIC; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Rainbow") { rgbControl.effect = eEFFECT_RAINBOW; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Rainbow Cycle") { rgbControl.effect = eEFFECT_RAINBOW_CYCLE; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Theatre") { rgbControl.effect = eEFFECT_THEATER_CHASE; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Twinkle") { rgbControl.effect = eEFFECT_TWINKLE; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Blink") { rgbControl.effect = eEFFECT_BLINK; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Colour Sweep") { rgbControl.effect = eEFFECT_COLOUR_SWEEP; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Ambulance") { rgbControl.effect = eEFFECT_AMBULANCE; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Running") { rgbControl.effect = eEFFECT_RUNNING; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Firework") { rgbControl.effect = eEFFECT_FIREWORK; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Merry Christmas") { rgbControl.effect = eEFFECT_MERRY_CHRISTMAS; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Circus") { rgbControl.effect = eEFFECT_CIRCUS; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Halloween") { rgbControl.effect = eEFFECT_HOLLOWEEN; rgbControl.flag = true; }  
    if (globalModes["modeInstance1"] == "Round Robin") { ws2812fx.start(); rgbControl.effect = eEFFECT_STATIC; rgbControl.cycle = true; }  
    last_command = globalModes["modeInstance1"];
  }
}

void initPeripheral(void)
{
  Serial.begin(BAUD_RATE);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void setupWiFi(void)
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

void setupRGB(void)
{  
  ws2812fx.init();
  ws2812fx.setMode(rgbModes[rgbControl.effect]);
  ws2812fx.setBrightness(rgbControl.brightness);
  ws2812fx.setSpeed(rgbControl.speed);
  ws2812fx.setColor(rgbControl.colour);
  ws2812fx.start();
}

void updateRGB(void)
{
  if(rgbControl.flag)
  {
    ws2812fx.setMode(rgbModes[rgbControl.effect]);
    ws2812fx.setBrightness(rgbControl.brightness);
    ws2812fx.setSpeed(rgbControl.speed);
    ws2812fx.setColor(rgbControl.colour);
    ws2812fx.start();
    rgbControl.flag = false;
  }
}

void checkButton(void)
{
  static unsigned long last_press = 0U;
  if(millis() - last_press > DEBOUNCE_TIME)
  {
    if(digitalRead(BUTTON_PIN) == LOW)
    {
      ButtonShortPressFlag = true;
    }
    last_press = millis();
  }
}

void roundRobin(void)
{
  static unsigned long last_change = 0U;
  if(rgbControl.cycle && (millis() - last_change > CYCLE_TIME))
  {
    if(rgbControl.effect++ >= eEFFECT_LAST)
    {
      rgbControl.effect = 1U;
    }
    ws2812fx.setMode(rgbModes[rgbControl.effect]);
    last_change = millis();
  }
}

/********
 * Setup *
 ********/

void setup(void) 
{
  initPeripheral();
  setupWiFi();
  ArduinoOTA.begin();
  setupSinricPro();
  initEffects();
  setupRGB();
}

/********
 * Loop *
 ********/

void loop(void) 
{
  ArduinoOTA.handle();
  SinricPro.handle();
  ws2812fx.service();
  processCommands();
  updateRGB();
  roundRobin();
}