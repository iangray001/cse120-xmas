#ifndef __twinkle_h
#define __twinkle_h

#include <UTFT.h>
#include <FastLED.h>
#include "menu.h"
#include "boardconfig.h"
#include "library.h"

class Twinkle : public Animation {
public:
	void start();
	void tick(UTFT lcd);
	menu_t *get_menu();
};

extern Twinkle *twinkle;


#endif
