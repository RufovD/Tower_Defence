#include "Building_place.h"

Building_place::Building_place(int x, int y) : x(x), y(y), r(2) {}

int Building_place::get_x() {
    return x;
};

int Building_place::get_y() {
    return y;
};

int Building_place::get_r() {
    return r;
};

bool Building_place::is_pressed(int click_x, int click_y) {
    return (r * r >= (click_x - x) * (click_x - x) + (click_y - y) * (click_y - y));
};

Building_menu Building_place::call_menu() {
    return Building_menu(x, y - 5, Building_place * this);
};
