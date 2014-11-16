#include <UTFT.h>
#include <UTouch.h>
#include <FastLED.h>
#include "boardconfig.h"
#include "library.h"
#include "menu.h"
#include "twinkle.h"
#include "quizbuzz.h"


CRGB leds[NUM_LEDS];
UTFT lcd(ITDB32WC, 38,39,40,41);
UTouch touch(6,5,4,3,2);

//The current LED animation
Animation *currentanim;

//The currently displayed menu
menu_t *currentmenu;

//Main Menu setup
/*****************************************************************/

void testfunc(void *arg) {
	lcd.setColor(random(255),random(255),random(255));
	lcd.fillRect(390, 230, 400, 240);
}

void leds_off(void *arg) {
	clearLEDs();
	currentanim = NULL;
}

void switch_animation(void *arg) {
	currentanim = (Animation *) arg;
	currentanim->start();
	if(currentanim->get_menu() != NULL) {
		currentmenu = currentanim->get_menu();
		drawmenu(lcd, currentmenu);
	}
}

//Declare menu item arrays
menuitem_t mainmenu_items[] = {
	{type_function, "LEDs", "OFF", leds_off, 0, NULL},
	{type_function, "Twinkle", NULL, switch_animation, (void *)twinkle, NULL},
	{type_function, "Quiz", "Buzz", switch_animation, (void *)quizbuzz, NULL},
};

menu_t mainmenu = {"Main Menu", 3, mainmenu_items};



// setup() and loop()
/*****************************************************************/

void setup() {
	pinMode(TOUCH_PIN, OUTPUT);
	lcd.InitLCD();
	touch.InitTouch();
	touch.setPrecision(PREC_EXTREME);

	FastLED.addLeds<WS2811, LED_DATA_PIN, RGB>(leds, NUM_LEDS);

	currentanim = NULL;
	currentmenu = &mainmenu;
	drawmenu(lcd, &mainmenu);
}

void loop() {
	while (touch.dataAvailable() == true) {
		checkfortouch(lcd, touch, &currentmenu);
	}

	if(currentanim != NULL) currentanim->tick(lcd);
}
