#include "quizbuzz.h"

QuizBuzz *quizbuzz = new QuizBuzz();

#define NUM_TEAMS 8


void testbuzzeranim(void *arg) {
	quizbuzz->play_buzz_anim(*((int*)arg));
}

menuitem_t quizbuzz_items[] = {
	{type_newmenu, " Back", "to main", NULL, NULL, &mainmenu},
	{type_function, "1", NULL, testbuzzeranim, (void *) 1, NULL},
	{type_function, "2", NULL, testbuzzeranim, (void *) 2, NULL},
	{type_function, "3", NULL, testbuzzeranim, (void *) 3, NULL},
	{type_function, "4", NULL, testbuzzeranim, (void *) 4, NULL},
	nullitem,
	{type_function, "5", NULL, testbuzzeranim, (void *) 5, NULL},
	{type_function, "6", NULL, testbuzzeranim, (void *) 6, NULL},
	{type_function, "7", NULL, testbuzzeranim, (void *) 7, NULL},
	{type_function, "8", NULL, testbuzzeranim, (void *) 8, NULL},
};

menu_t quizbuzzmenu = {"Quiz Buzzer", 10, quizbuzz_items};

typedef struct {
	int st;
	int end;
} bounds_t;

bounds_t teams[NUM_TEAMS] = {
	{2, 4}, //Team 1
	{8, 12}, //Team 2
	{14, 15}, //Team 3
	{17, 22}, //Team 4
	{27, 33}, //Team 5
	{38, 40}, //Team 6
	{42, 45}, //Team 7
	{47, 48}, //Team 8
};


#define NUM_FRAMES 100

void QuizBuzz::play_buzz_anim(int team) {
	if(team < 0 || team >= NUM_TEAMS) return;

	clearLEDs();
	
	int right_dist = (NUM_LEDS - teams[team].end) - 1;

	for(int frame = 0; frame < NUM_FRAMES; frame++) {

		float pos = (float) frame / (float) NUM_FRAMES;

		int leftpos = round((float) teams[team].st * pos);
		int rightpos = (NUM_LEDS - round((float) right_dist * pos)) - 1;



	}

}


void QuizBuzz::start() {
	FastLED.show();
}


void QuizBuzz::tick(UTFT lcd) {

}

menu_t *QuizBuzz::get_menu() {
	return &quizbuzzmenu;
}
