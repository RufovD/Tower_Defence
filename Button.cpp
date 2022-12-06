#include "Button.h"

Button::Button(int x, int y, int level_number) : x(x), y(y), level_number(level_number), lenght_x(50), lenght_y(20), pressed(false) {}

bool Button::is_pressed(int click_x, int click_y) {
	if ((x <= click_x) && (click_x <= x + lenght_x) && (y <= click_y) && (click_y <= y + lenght_y))
		pressed = true;
	return pressed;
}; 

int Button::get_level_number() {
	return level_number;
};

