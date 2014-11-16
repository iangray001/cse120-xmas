#include "quizbuzztest.h"
#include "quizbuzz.h"

QuizBuzzTest *quizbuzztest = new QuizBuzzTest();

void QuizBuzzTest::start() {
	FastLED.show();
}

void QuizBuzzTest::tick(UTFT lcd) {}

void testbuzzeranim(void *arg) {
	play_buzz_anim((int)arg);
}

menuitem_t quizbuzz_items[] = {
	{type_newmenu, " Back", "to main", NULL, NULL, &mainmenu},
	{type_function, "1", NULL, testbuzzeranim, (void *) 0, NULL},
	{type_function, "2", NULL, testbuzzeranim, (void *) 1, NULL},
	{type_function, "3", NULL, testbuzzeranim, (void *) 2, NULL},
	{type_function, "4", NULL, testbuzzeranim, (void *) 3, NULL},
	nullitem,
	{type_function, "5", NULL, testbuzzeranim, (void *) 4, NULL},
	{type_function, "6", NULL, testbuzzeranim, (void *) 5, NULL},
	{type_function, "7", NULL, testbuzzeranim, (void *) 6, NULL},
	{type_function, "8", NULL, testbuzzeranim, (void *) 7, NULL},
};

menu_t quizbuzzmenu = {"Quiz Buzzer", 10, quizbuzz_items};

menu_t *QuizBuzzTest::get_menu() {
	return &quizbuzzmenu;
}
