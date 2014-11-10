/*
 * Board configuration. Pin locations etc. 
 */
#ifndef __BOARDCONFIG_H
#define __BOARDCONFIG_H

#include <FastLED.h>

#define NUM_LEDS 50
#define LED_DATA_PIN 7
#define TOUCH_PIN 12

extern CRGB leds[NUM_LEDS];

#endif
