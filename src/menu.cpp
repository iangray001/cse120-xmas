#include "menu.h"

#define WORDS_X_MAX 5
#define WORDS_Y_MAX 3

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern menu_t *currentmenu;
extern int pin;


menuitem_t nullitem = {type_function, "", NULL, NULL, NULL};


void drawmenu(UTFT lcd, menu_t *menu) {

	lcd.clrScr();

	lcd.setFont(BigFont);
	lcd.setColor(255, 255, 255);
	lcd.print(menu->name, 0, 0);

	//lcd.fillRect(10, 20, 390, 230);

	lcd.setFont(SmallFont);

	int x = 0, y = 0;
	for(int i = 0; i < menu->size; i++) {
		lcd.print(menu->items[i].text, x*80+20, y*80+35);
		x++;
		if(x == WORDS_X_MAX) { x = 0; y++; }
	}

}


void checkfortouch(UTFT lcd, UTouch touch) {
	while (touch.dataAvailable() == true) {
		digitalWrite(pin, LOW); // turn on pullup resistors
		touch.read();
		int x = touch.getX()/80;
		int y = touch.getY()/80;
		int item = y*WORDS_X_MAX + x;

		if(item < currentmenu->size) {
			menuitem_t pressed = currentmenu->items[item];

			switch(pressed.type) {
				case type_newmenu:
					currentmenu = pressed.newmenu;
					drawmenu(lcd, currentmenu);
					break;

				case type_function:
					if(pressed.func != NULL) pressed.func(pressed.funcarg);
					break;
			}
		}
	}
}


