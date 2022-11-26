#pragma once
#include "Monster.h"
class Ground_Monster :
    public Monster
{
public:
    Ground_Monster(int hp, int v, int x, int y, int damage_value, int money);
};

