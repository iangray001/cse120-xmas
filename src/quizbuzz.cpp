#include "quizbuzz.h"

QuizBuzz *quizbuzz = new QuizBuzz();

void testbuzzeranim(void *arg) {
	quizbuzz->play_buzz_anim((int)arg);
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

typedef struct {
	int st;
	int end;
} bounds_t;

bounds_t teams[NUM_TEAMS] = {
	{5, 13}, //Team 1
	{18, 26}, //Team 2
	{31, 39}, //Team 3
	{44, 52}, //Team 4
	{57, 65}, //Team 5
	{70, 78}, //Team 6
	{83, 91}, //Team 7
	{94, 98}, //Team 8
};

CRGB teamcol[NUM_TEAMS] = {
	CRGB(255,   0,   0), //Team 1 (red)
	CRGB(  0, 255,   0), //Team 2 (green)
	CRGB(  0,   0, 255), //Team 3 (blue)
	CRGB(255, 255,   0), //Team 4 (yellow)
	CRGB(255,   0, 255), //Team 5 (magenta)
	CRGB(  0, 255, 255), //Team 6 (cyan)
	CRGB(128,   0, 255), //Team 7 (purple)
	CRGB(255, 255, 255), //Team 8 (white)
};

#define NUM_FRAMES 100
#define FRAME_DELAY 1
#define SWOOP_TEAM_COLS 1
#define SWOOP_FADE_SPEED 8
#define POST_SWOOP_FADE_SPEED 5

void QuizBuzz::play_buzz_anim(int team) {
	if(team < 0 || team >= NUM_TEAMS) return;

	clearLEDs();

	int right_dist = (NUM_LEDS - teams[team].end) - 1;

	//'Swoop' part of the animation where leds stream from the left and right
	//to focus on the target range
	for(int frame = 0; frame < NUM_FRAMES; frame++) {

		float pos = (float) frame / (float) NUM_FRAMES;

		int leftpos = round((float) teams[team].st * pos);
		int rightpos = (NUM_LEDS - round((float) right_dist * pos)) - 1;

		if(SWOOP_TEAM_COLS) { //Use team colours for the swoop
			leds[leftpos] = teamcol[team];
			leds[rightpos] = teamcol[team];
		} else { //Use random colours
			leds[leftpos] = CHSV(random(255), 255, 255);
			leds[rightpos] = CHSV(random(255), 255, 255);
		}

		fadeAllLeds(SWOOP_FADE_SPEED);	

		FastLED.show();
		delay(FRAME_DELAY);
	}

	//Swoop complete, focus on the target range
	for(int i = teams[team].st; i <= teams[team].end; i++) {
		leds[i] = teamcol[team];
	}
	FastLED.show();

	while(1) {
		int rv1 = fadeLeds(2, 0, teams[team].st - 1);
		int rv2 = fadeLeds(2, teams[team].end + 1, NUM_LEDS - 1);
		if(rv1 == 0 && rv2 == 0) break;
		FastLED.show();
		delay(POST_SWOOP_FADE_SPEED);
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
