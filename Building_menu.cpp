#include "Building_menu.h"
#include "Building_place.h"
#include "Ground_Tower.h"
#include "Air_Tower.h"
#include "Uni_Tower.h"

Building_menu::Building_menu(int x2, int y2, Building_place* place) : x2(x2), y2(y2), x1(x2 - 3), x3(x2 + 3), y1(y2 - 1), y3(y2 - 1), r(1), cost1(200), cost2(200), cost3(500), place(place) {};


bool Building_menu::is_pressed(int x, int y, int click_x, int click_y) {
    return (r * r >= (click_x - x) * (click_x - x) + (click_y - y) * (click_y - y));
};

bool Building_menu::first_pressed(int click_x, int click_y) {
    return is_pressed(x1, y1, click_x, click_y);
};

bool Building_menu::second_pressed(int click_x, int click_y) {
    return is_pressed(x2, y2, click_x, click_y);
};

bool Building_menu::third_pressed(int click_x, int click_y) {
    return is_pressed(x3, y3, click_x, click_y);
};

Ground_Tower Building_menu::build_ground_tower() {
    int x = place->get_x();
    int y = place->get_y();
    Ground_Tower gr_t(x, y);
    return gr_t;
};

Air_Tower Building_menu::build_air_tower() {
    int x = place->get_x();
    int y = place->get_y();
    Air_Tower air_t(x, y);
    return air_t;
};

Uni_Tower Building_menu::build_uni_tower() {
    int x = place->get_x();
    int y = place->get_y();
    Uni_Tower uni_t(x, y);
    return uni_t;
};
