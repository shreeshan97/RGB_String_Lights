#ifndef _RGBCONTROLLERINIT_H_
#define _RGBCONTROLLERINIT_H_

#include <stdint.h>

typedef uint8_t  TUINT8;
typedef uint16_t TUINT16;
typedef uint32_t TUINT32;

typedef struct
{
  TUINT8  flag;
  TUINT8  cycle;
  TUINT8  effect;
  TUINT8  brightness;
  TUINT16 speed;
  TUINT32 colour;
}TrgbController;

// Declare a struct variable
extern TrgbController rgbControl; 

typedef enum
{
  eEFFECT_STATIC,
  eEFFECT_RANDOM,
  eEFFECT_MULTI_DYNAMIC,
  eEFFECT_RAINBOW,
  eEFFECT_RAINBOW_CYCLE,
  eEFFECT_THEATER_CHASE,
  eEFFECT_TWINKLE,
  eEFFECT_BLINK,
  eEFFECT_CHASE,
  eEFFECT_COLOUR_SWEEP,
  eEFFECT_AMBULANCE,
  eEFFECT_RUNNING,
  eEFFECT_FIREWORK,
  eEFFECT_MERRY_CHRISTMAS,
  eEFFECT_CIRCUS,
  eEFFECT_HOLLOWEEN,
  eEFFECT_LAST,
}TrgbEffect;

// Declare a RGB Mode array
extern TUINT8 rgbModes[eEFFECT_LAST];

// Declare a RGB effect setup function
extern void initEffects(void);

// Button press flag
extern bool ButtonShortPressFlag; 
extern bool ButtonLongPressFlag; 

#endif
