#ifndef __quizbuzztest_h
#define __quizbuzztest_h

#include <UTFT.h>
#include <FastLED.h>
#include "menu.h"
#include "boardconfig.h"
#include "library.h"

/*
This class is used in the Xmas system to test the Quiz Buzzer animation 
code. It is not actually needed by the Quiz Buzzer code.
*/

class QuizBuzzTest : public Animation {
public:
	void start();
	void tick(UTFT lcd);
	menu_t *get_menu();
};

extern QuizBuzzTest *quizbuzztest;

#endif
