#pragma once
#include "Air_Monster.h"
#include <SFML/Graphics.hpp>

class Bat :
    public Air_Monster
{
public:
    Bat(const sf::Texture& tex, int x, int y);
};

