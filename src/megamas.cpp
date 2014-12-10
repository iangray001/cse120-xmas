#include "megamas.h"

Megamas *megamas = new Megamas();

//										Min 	Max		Step	Start
static Parameter mmasspeed(	"Speed", 	0, 		100, 	10, 	0);
static Parameter mmasnum(	"Number", 	5, 		50, 	5, 		10);
static Parameter transpeed(	"TSpeed", 	1, 		10, 	1, 		4);

static void reset(void *arg) {
	mmasspeed.reset();
	mmasnum.reset();
	transpeed.reset();
	print_status_bar("Parameters reset.");
}

menuitem_t megamas_items[] = {
	{type_newmenu, " Back", "to main", NULL, NULL, &mainmenu},
	{type_function, "Speed", "  +", param_dec_lcd, (void *) &mmasspeed, NULL},
	{type_function, "Speed", "  -", param_inc_lcd, (void *) &mmasspeed, NULL},
	{type_function, "NumLed", "  +", param_inc_lcd, (void *) &mmasnum, NULL},
	{type_function, "NumLed", "  -", param_dec_lcd, (void *) &mmasnum, NULL},
	{type_function, "TS", "  +", param_inc_lcd, (void *) &transpeed, NULL},
	{type_function, "TS", "  -", param_dec_lcd, (void *) &transpeed, NULL},
};

menu_t megamasmenu = {"Megamas", 7, megamas_items};


static CHSV target[NUM_LEDS];
static CHSV current[NUM_LEDS];


void Megamas::start() {
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CHSV(0, 255, 255);
		target[i] = CHSV(0, 255, 255);
		current[i] = CHSV(0, 255, 255);
	}
	FastLED.show();
}

void Megamas::tick(UTFT lcd) {
	static int framenum;

	framenum++;

	if(framenum > mmasspeed.get()) {
		framenum = 0;
		for(int i = 0; i < mmasnum.get(); i++) {
			switch(random(3)) {
				case 0:
					target[random(NUM_LEDS)] = CHSV(0, 255, 255);
					break;
				case 1:
					target[random(NUM_LEDS)] = CHSV(85, 255, 255);
					break;
				case 2:
					target[random(NUM_LEDS)] = CHSV(170, 255, 255);
					break;
			}
		}
	}

	for(int i = 0; i < NUM_LEDS; i++) {
		if(current[i].h < target[i].h) {
			if(target[i].h - current[i].h < transpeed.get()) {
				current[i].h = target[i].h;
			} else if(current[i].h < (255-transpeed.get())) {
				current[i].h += transpeed.get();
			} else {
				current[i].h = 255;
			}
		}

		if(current[i].h > target[i].h) {
			if(current[i].h - target[i].h < transpeed.get()) {
				current[i].h = target[i].h;
			} else if(current[i].h > transpeed.get()) {
				current[i].h -= transpeed.get();
			} else {
				current[i].h = 0;
			}
		}

		leds[i] = current[i];
	}
	FastLED.show();
}

menu_t *Megamas::get_menu() {
	return &megamasmenu;
}
