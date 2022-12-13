#pragma once
#include "Monster.h"

class Castle
{
private:
    int hp, x, y;
    bool is_alive;

public:
    Castle(int x, int y);
    void get_damage(Monster monster);
    int get_hp();
    bool death();
};

