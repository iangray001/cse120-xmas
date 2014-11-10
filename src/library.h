#ifndef __LIBRARY_H
#define __LIBRARY_H

#include <FastLED.h>
#include "boardconfig.h"
#include "menu.h"

void clearLEDs();

/*
Base animation class.
*/
class Animation {
public:
	Animation();
	virtual void tick(UTFT lcd) = 0;
	virtual void start() = 0;
	virtual menu_t *get_menu() = 0;
	virtual ~Animation();
};



/*
Simple utility class for storing a parameter that can be incremented and 
decremented easily.
*/
class Parameter {
public:
	Parameter(int minval, int maxval, int step, int start_val);
	void inc();
	void dec();
	int get();
private:
	int val;
	int step;
	int minval;
	int maxval;
};

void param_inc(void *dir);
void param_dec(void *dir);

#endif
