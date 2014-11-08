#include "twinkle.h"

UTFT thislcd;

#define SPEED_MAX 100
#define SPEED_INC 10
int speed = 50;


menuitem_t twinkle_items[] = {
	{type_newmenu, "Back", NULL, NULL, &mainmenu},
	{type_function, "Speed+", twinkle_speed, 1, NULL},
	{type_function, "Hue+", twinkle_hue, 1, NULL},
	{type_function, "Brgt+", twinkle_brightness, 1, NULL},
	{type_function, "Twink+", twinkle_twinkle, 1, NULL},
	nullitem,
	{type_function, "Speed-", twinkle_speed, 0, NULL},
	{type_function, "Hue-", twinkle_hue, 0, NULL},
	{type_function, "Brgt-", twinkle_brightness, 0, NULL},
	{type_function, "Twink-", twinkle_twinkle, 0, NULL},
};

menu_t twinklemenu = {"Twinkle", 10, twinkle_items};



void twinkle_start(UTFT lcd) {
	thislcd = lcd;
}

void twinkle_speed(int dir) {
	if(dir) {
		speed -= SPEED_INC;
		if(speed < 0) speed = 0;
	} else {
		speed += SPEED_INC;
		if(speed > SPEED_MAX) speed = SPEED_MAX;
	}
}


void twinkle_hue(int dir) {

}

void twinkle_brightness(int dir) {

}

void twinkle_twinkle(int dir) {

}


void twinkle_tick() {

};


