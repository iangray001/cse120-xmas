#include "library.h"

void setLEDs(CRGB col) {
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = col;
	}
	FastLED.show();
}

void clearLEDs() {
	setLEDs(CRGB(0, 0, 0));
}


Animation::Animation() {}
Animation::~Animation() {}


Parameter::Parameter(int minval, int maxval, int step, int start_val) : step(step), minval(minval), maxval(maxval), val(start_val) {}

void Parameter::inc() {
	val += step;
	if(val > maxval) val = maxval;
}

void Parameter::dec() {
	val -= step;
	if(val < minval) val = minval;
}

int Parameter::get() {
	return val;
}


void param_inc(void *dir) { ((Parameter*)dir)->inc();}
void param_dec(void *dir) { ((Parameter*)dir)->dec();}
