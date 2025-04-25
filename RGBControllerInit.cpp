#include <sys/_intsup.h>
#include "RGBControllerInit.h"
#include "Defaults.h"
#include <modes_esp.h>

// Initialize RGB Controller
TrgbController rgbControl = {false, false, DEFAULT_EFFECT, MAX_BRIGHTNESS, MAX_SPEED, DEFAULT_COLOUR};

// Initialize the RGB Effect array
TUINT8 rgbModes[eEFFECT_LAST] = {0};

// Initialize Button press flag
bool ButtonShortPressFlag = false;
bool ButtonLongPressFlag = false;

// Assign values to the RGB Effect array
void initEffects(void)
{
  rgbModes[eEFFECT_STATIC] = FX_MODE_STATIC;
  rgbModes[eEFFECT_RANDOM] = FX_MODE_RANDOM_COLOR;
  rgbModes[eEFFECT_MULTI_DYNAMIC] = FX_MODE_MULTI_DYNAMIC;
  rgbModes[eEFFECT_RAINBOW] = FX_MODE_RAINBOW;
  rgbModes[eEFFECT_RAINBOW_CYCLE] = FX_MODE_RAINBOW_CYCLE;
  rgbModes[eEFFECT_THEATER_CHASE] = FX_MODE_THEATER_CHASE_RAINBOW;
  rgbModes[eEFFECT_TWINKLE] = FX_MODE_TWINKLE_RANDOM;
  rgbModes[eEFFECT_BLINK] = FX_MODE_BLINK_RAINBOW;
  rgbModes[eEFFECT_CHASE] = FX_MODE_CHASE_RANDOM;
  rgbModes[eEFFECT_COLOUR_SWEEP] = FX_MODE_COLOR_SWEEP_RANDOM;
  rgbModes[eEFFECT_AMBULANCE] = FX_MODE_RUNNING_RED_BLUE;
  rgbModes[eEFFECT_RUNNING] = FX_MODE_RUNNING_RANDOM;
  rgbModes[eEFFECT_FIREWORK] = FX_MODE_FIREWORKS_RANDOM;
  rgbModes[eEFFECT_MERRY_CHRISTMAS] = FX_MODE_MERRY_CHRISTMAS;
  rgbModes[eEFFECT_CIRCUS] = FX_MODE_CIRCUS_COMBUSTUS;
  rgbModes[eEFFECT_HOLLOWEEN] = FX_MODE_HALLOWEEN;
}