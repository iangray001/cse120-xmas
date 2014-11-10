#ifndef __menu_h
#define __menu_h

#include <UTFT.h>
#include <UTouch.h>
#include "boardconfig.h"

// Functions called by the menu system must have this type
typedef void (*menufunc_t)(void *);

//Forward declaration for menu struct
typedef struct menu menu_t;

//What is the type of the menu item?
//type_newmenu items jump to and draw a new menu when pressed
//type_function items call the provided function when pressed
enum item_type { type_newmenu, type_function };

//These are the actual items in the menu
typedef struct menuitem {
	item_type type;
	char *text; //The text to be displayed
	char *text2; //(Optional) second line of text for the item
	menufunc_t func; //The function to be called for type_function items
	void *funcarg; //The argument to the passed to the function
	menu_t *newmenu; //The menu_t to jump to for type_newmenu items
} menuitem_t;

//The menu type itself
typedef struct menu {
	char *name; //Name of the menu, displayed at the top of the screen
	unsigned int size; //Length of the items array
	menuitem_t *items; //An array of menuitem_t instances
} menu_t;


//The NULL menu item, can be used for spacing out menus
extern menuitem_t nullitem;

//The top level main menu (declared in main.ino)
extern menu_t mainmenu;




void drawmenu(UTFT lcd, menu_t *menu);
void checkfortouch(UTFT lcd, UTouch touch, menu_t **currentmenu);

#endif
