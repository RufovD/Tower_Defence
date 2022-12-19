#pragma once
#include "Monster.h"
class Air_Monster :
    public Monster
{
public:
    Air_Monster(const sf::Texture& tex, int hp, int v, int x, int y, int damage_value, int money);
};

