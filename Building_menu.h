#pragma once
#include "Building_place.h"

class Building_menu
{
private:
    Building_place* place;
    int x1, x2, x3, y1, y2, y3, r;
    int cost1, cost2, cost3;
    bool is_pressed(int x, int y, float click_x, float click_y);

public:
    Building_menu(int x2, int y2, Building_place* place);
    bool first_pressed(int click_x, int click_y);
    bool second_pressed(int click_x, int click_y);
    bool third_pressed(int click_x, int click_y);
    Ground_tower build_ground_tower();
    Air_tower build_air_tower();
    Uni_tower build_uni_tower();
};

