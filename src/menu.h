#ifndef __menu_h
#define __menu_h

#include <UTFT.h>
#include <UTouch.h>
#include "boardconfig.h"

typedef void (*menufunc_t)(void *);

typedef struct menu menu_t;

enum item_type { type_newmenu, type_function };

typedef struct menuitem {
	item_type type;
	char *text;
	menufunc_t func;
	void *funcarg;
	menu_t *newmenu;	
} menuitem_t;

typedef struct menu {
	char *name;
	unsigned int size;
	menuitem_t *items;
} menu_t;


//The NULL menu item, can be used for spacing out menus
extern menuitem_t nullitem;

//The main menu must be declared somewhere
extern menu_t mainmenu;

void drawmenu(UTFT lcd, menu_t *menu);
void checkfortouch(UTFT lcd, UTouch touch);

#endif
