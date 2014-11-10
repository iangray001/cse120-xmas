#include "twinkle.h"

Twinkle *twinkle = new Twinkle();

Parameter speed(0, 100, 10, 50);
Parameter hue(0, 100, 10, 50);
Parameter brightness(0, 100, 10, 50);
Parameter twinkleamount(0, 100, 10, 50);

menuitem_t twinkle_items[] = {
	{type_newmenu, " Back", "to main", NULL, NULL, &mainmenu},
	{type_function, "Speed+", NULL, param_inc, (void *) &speed, NULL},
	{type_function, "Hue+", NULL, param_inc, (void *) &hue, NULL},
	{type_function, "Brgt+", NULL, param_inc, (void *) &brightness, NULL},
	{type_function, "Twink+", NULL, param_inc, (void *) &twinkleamount, NULL},
	nullitem,
	{type_function, "Speed-", NULL, param_dec, (void *) &speed, NULL},
	{type_function, "Hue-", NULL, param_dec, (void *) &hue, NULL},
	{type_function, "Brgt-", NULL, param_dec, (void *) &brightness, NULL},
	{type_function, "Twink-", NULL, param_dec, (void *) &twinkleamount, NULL},
};

menu_t twinklemenu = {"Twinkle", 10, twinkle_items};


void Twinkle::start() {}

void Twinkle::tick(UTFT lcd) {

}

menu_t *Twinkle::get_menu() {
	return &twinklemenu;
}
