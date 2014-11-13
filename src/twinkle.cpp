#include "twinkle.h"

Twinkle *twinkle = new Twinkle();

//										Min 	Max		Step	Start
Parameter speed(		"Speed", 		0, 		100, 	10, 	10);	//Every speed frames change a target colour
Parameter hue(			"Hue", 			0, 		255, 	10, 	0);		//The hue of the leds
Parameter saturation(	"Saturation", 	0, 		255, 	30, 	0);		//The saturation of the leds
Parameter twinkleamount("Twinkle", 		0, 		255, 	10, 	60);	//The amount to twiddle the value of the leds

#define FADEFRAMES 2


void reset(void *arg) {
	speed.reset();
	hue.reset();
	saturation.reset();
	twinkleamount.reset();
	print_status_bar("Parameters reset.");
}

menuitem_t twinkle_items[] = {
	{type_newmenu, " Back", "to main", NULL, NULL, &mainmenu},
	{type_function, "Speed", "  +", param_dec_lcd, (void *) &speed, NULL},
	{type_function, "Hue", " +", param_inc_lcd, (void *) &hue, NULL},
	{type_function, "Sat", " +", param_inc_lcd, (void *) &saturation, NULL},
	{type_function, "Twink", "  +", param_inc_lcd, (void *) &twinkleamount, NULL},
	{type_function, "Reset", NULL, reset, NULL, NULL},
	{type_function, "Speed", "  -", param_inc_lcd, (void *) &speed, NULL},
	{type_function, "Hue", " -", param_dec_lcd, (void *) &hue, NULL},
	{type_function, "Sat", " -", param_dec_lcd, (void *) &saturation, NULL},
	{type_function, "Twink", "  -", param_dec_lcd, (void *) &twinkleamount, NULL},
};

menu_t twinklemenu = {"Twinkle", 10, twinkle_items};

CHSV target[NUM_LEDS];
CHSV current[NUM_LEDS];

void Twinkle::start() {
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CHSV(hue.get(), saturation.get(), 255);
		target[i] = CHSV(hue.get(), saturation.get(), 255);
		current[i] = CHSV(hue.get(), saturation.get(), 255);
	}
	FastLED.show();
}

void Twinkle::tick(UTFT lcd) {
	static int framenum;
	static int fadeframenum;

	framenum++;
	fadeframenum++;

	if(framenum > speed.get()) {
		framenum = 0;
		target[random(NUM_LEDS)] = CHSV(hue.get(), saturation.get(), 255 - random(twinkleamount.get()));
	}

	if(fadeframenum > FADEFRAMES) {
		fadeframenum = 0;
		for(int i = 0; i < NUM_LEDS; i++) {
			if(current[i].v < target[i].v) current[i].v++;
			if(current[i].v > target[i].v) current[i].v--;
			current[i].s = saturation.get();
			current[i].h = hue.get();
			leds[i] = current[i];
		}
		FastLED.show();
	}
}

menu_t *Twinkle::get_menu() {
	return &twinklemenu;
}
