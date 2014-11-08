#ifndef __twinkle_h
#define __twinkle_h

#include <UTFT.h>
#include <FastLED.h>
#include "menu.h"
#include "boardconfig.h"

void twinkle_start(UTFT lcd);
void twinkle_speed(void *dir);
void twinkle_hue(void *dir);
void twinkle_brightness(void *dir);
void twinkle_twinkle(void *dir);
void twinkle_tick();

extern menu_t twinklemenu;


#endif
