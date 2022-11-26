#pragma once
#include "Building_menu.h"

class Building_place
{
private:
    int x, y, r;
    Building_place(int x, int y);

public:
    int get_x();
    int get_y();
    int get_r();
    bool is_pressed(int click_x, int click_y);
    Building_menu call_menu();
};

