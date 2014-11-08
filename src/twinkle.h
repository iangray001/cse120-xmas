#ifndef __twinkle_h
#define __twinkle_h

#include <UTFT.h>
#include <FastLED.h>
#include "menu.h"
#include "boardconfig.h"

void twinkle_start(UTFT lcd);
void twinkle_speed(int dir);
void twinkle_hue(int dir);
void twinkle_brightness(int dir);
void twinkle_twinkle(int dir);
void twinkle_tick();

extern menu_t twinklemenu;


#endif
