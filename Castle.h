#pragma once
#include "Monster.h"
#include <SFML/Graphics.hpp>

class Castle
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int hp, x, y;
    bool is_alive;

public:
    Castle(int x, int y);
    void get_damage(Monster monster);
    int get_hp();
    bool death();
    void draw(sf::RenderWindow& window);
};

