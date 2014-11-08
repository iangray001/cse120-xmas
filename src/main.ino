#include <UTFT.h>
#include <UTouch.h>
#include <FastLED.h>
#include "boardconfig.h"
#include "menu.h"
#include "twinkle.h"


CRGB leds[NUM_LEDS];

extern uint8_t SmallFont[];
extern uint8_t BigFont[];

int pin = 12;
UTFT lcd(ITDB32WC, 38,39,40,41);
UTouch touch(6,5,4,3,2);

//Animations can set this pointer to be called periodically 
typedef void (*animfunc_t)(void);
animfunc_t animation_tick_func;

//The current menu on screen
menu_t *currentmenu;


//Main Menu setup
/*****************************************************************/

void testfunc(void *arg) {
	lcd.setColor(random(255),random(255),random(255));
	lcd.fillRect(390, 230, 400, 240);
}

void leds_off(void *arg) {
	//TODO Turn off leds here
	animation_tick_func = NULL;
}

void switch_twinkle(void *arg) {
	twinkle_start(lcd);
	animation_tick_func = twinkle_tick;
	currentmenu = &twinklemenu;
	drawmenu(lcd, currentmenu);
}

//Declare menu item arrays
menuitem_t mainmenu_items[] = {
	{type_function, "OFF", leds_off, 0, NULL},
	{type_function, "Twinkle", switch_twinkle, 0, NULL}
};

menu_t mainmenu = {"Main Menu", 2, mainmenu_items};



// setup() and loop()
/*****************************************************************/

void setup() {
	pinMode(pin, OUTPUT);
	lcd.InitLCD();
	touch.InitTouch();
	touch.setPrecision(PREC_EXTREME);

	FastLED.addLeds<WS2811, LED_DATA_PIN, RGB>(leds, NUM_LEDS);

	currentmenu = &mainmenu;
	drawmenu(lcd, currentmenu);
}

void loop() {
	while (touch.dataAvailable() == true) {
		checkfortouch(lcd, touch);
	}

	if(animation_tick_func != NULL) animation_tick_func();
}
