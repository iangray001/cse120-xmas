#include "menu.h"

#define WORDS_X_MAX 5
#define WORDS_Y_MAX 3

menuitem_t nullitem = {type_function, "", NULL, NULL, NULL, NULL};


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
		if(menu->items[i].text2 != NULL) 
			lcd.print(menu->items[i].text2, x*80+20, y*80+45);
		x++;
		if(x == WORDS_X_MAX) { x = 0; y++; }
	}

}

/*
 * Check to see if the user has touched a menu item, and if they have, 
 * perform the appropriate action.
 *
 * currentmenu is updated if a new menu was drawn.
 */
void checkfortouch(UTFT lcd, UTouch touch, menu_t **currentmenu) {
	while (touch.dataAvailable() == true) {
		digitalWrite(TOUCH_PIN, LOW); // turn on pullup resistors
		touch.read();
		int x = touch.getX()/80;
		int y = touch.getY()/80;
		int item = y * WORDS_X_MAX + x;

		if(item < (**currentmenu).size) {
			menuitem_t pressed = (**currentmenu).items[item];

			switch(pressed.type) {
				case type_newmenu:
					*currentmenu = pressed.newmenu;
					drawmenu(lcd, pressed.newmenu);
					break;

				case type_function:
					if(pressed.func != NULL) pressed.func(pressed.funcarg);
					break;
			}
		}
	}
}


