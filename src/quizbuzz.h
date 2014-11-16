#ifndef __quizbuzz_h
#define __quizbuzz_h

#include <UTFT.h>
#include <FastLED.h>
#include "menu.h"
#include "boardconfig.h"
#include "library.h"

#define NUM_TEAMS 8

class QuizBuzz : public Animation {
public:
	void start();
	void tick(UTFT lcd);
	menu_t *get_menu();
	void play_buzz_anim(int team);
};

extern QuizBuzz *quizbuzz;
extern CRGB teamcol[NUM_TEAMS];

#endif
