#ifndef _DEFAULTS_H_
#define _DEFAULTS_H_

#include <WS2812FX.h>

// Brightness values of the LED
#define MAX_BRIGHTNESS  250U
#define MID_BRIGHTNESS  125U
#define MIN_BRIGHTNESS  25U

// Speed values of the LED effects
#define MAX_SPEED       800U
#define MID_SPEED       500U
#define MIN_SPEED       200U

// Serial Console Baud Rate
#define BAUD_RATE       115200

// Addressable LED chipset type
#define LED_TYPE        WS2812

// Addressable LED digital pin
#define LED_PIN         4U

// Onboard Boot button
#define BUTTON_PIN      9U

// Total number of LEDs
#define NUM_LEDS        99U

// Default LED effect
#define DEFAULT_EFFECT  0U

// Default LED colour
#define DEFAULT_COLOUR  WHITE

// Button debounce time (millisecond)
#define DEBOUNCE_TIME   200U

// Button long press time (millisecond)
#define LONG_PRESS_TIME 2000U

// Effect cycle time (milliseconds)
#define CYCLE_TIME      60000U

#endif
