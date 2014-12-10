#ifndef __megamas_h
#define __megamas_h

#include <UTFT.h>
#include <FastLED.h>
#include "menu.h"
#include "boardconfig.h"
#include "library.h"

class Megamas : public Animation {
public:
	void start();
	void tick(UTFT lcd);
	menu_t *get_menu();
};

extern Megamas *megamas;


#endif
