#include "twinkle.h"

Twinkle *twinkle = new Twinkle();

//						Min 	Max		Step	Start
Parameter speed(		0, 		100, 	10, 	50);	//Every speed frames change a target colour
Parameter hue(			0, 		255, 	5, 		160);	//The hue of the leds
Parameter saturation(	0, 		255, 	30, 	0);		//The saturation of the leds
Parameter twinkleamount(0, 		255, 	10, 	40);	//The amount to twiddle the value of the leds

#define FADEFRAMES 5

menuitem_t twinkle_items[] = {
	{type_newmenu, " Back", "to main", NULL, NULL, &mainmenu},
	{type_function, "Speed+", NULL, param_dec, (void *) &speed, NULL},
	{type_function, "Hue+", NULL, param_inc, (void *) &hue, NULL},
	{type_function, "Sat+", NULL, param_inc, (void *) &saturation, NULL},
	{type_function, "Twink+", NULL, param_inc, (void *) &twinkleamount, NULL},
	nullitem,
	{type_function, "Speed-", NULL, param_inc, (void *) &speed, NULL},
	{type_function, "Hue-", NULL, param_dec, (void *) &hue, NULL},
	{type_function, "Sat-", NULL, param_dec, (void *) &saturation, NULL},
	{type_function, "Twink-", NULL, param_dec, (void *) &twinkleamount, NULL},
};

menu_t twinklemenu = {"Twinkle", 10, twinkle_items};

CHSV target[NUM_LEDS];
CHSV current[NUM_LEDS];

int framenum;
int fadeframenum;

void Twinkle::start() {
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CHSV(hue.get(), saturation.get(), 255);
		target[i] = CHSV(hue.get(), saturation.get(), 255);
		current[i] = CHSV(hue.get(), saturation.get(), 255);
	}
	FastLED.show();

	framenum = 0;
	fadeframenum = 0;
}

void Twinkle::tick(UTFT lcd) {
	framenum++;

	if(framenum > speed.get()) {
		framenum == 0;
		target[random(NUM_LEDS)] = CHSV(hue.get(), saturation.get(), 255 - random(twinkleamount.get()));
	}

	if(fadeframenum > FADEFRAMES) {
		fadeframenum == 0;
		for(int i = 0; i < NUM_LEDS; i++) {
			if(current[i].v < target[i].v) current[i].v++;
			if(current[i].v > target[i].v) current[i].v--;
			leds[i] = current[i];
		}
		FastLED.show();
	}
}

menu_t *Twinkle::get_menu() {
	return &twinklemenu;
}
