/*
 * Board configuration. Pin locations etc. 
 */
#ifndef __BOARDCONFIG_H
#define __BOARDCONFIG_H

#include <FastLED.h>
#include <UTFT.h>
#include <UTouch.h>

#define NUM_LEDS 100
#define LED_DATA_PIN 13
#define TOUCH_PIN 12

extern CRGB leds[NUM_LEDS];
extern UTFT lcd;
extern UTouch touch;

//Fonts defined in the UTFT library
extern uint8_t SmallFont[]; 
extern uint8_t BigFont[];

#endif
