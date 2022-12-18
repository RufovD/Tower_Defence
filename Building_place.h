#pragma once
#include "Building_menu.h"
#include <SFML/Graphics.hpp>

class Building_place
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int x, y, r;

public:
    Building_place(int x, int y);
    int get_x();
    int get_y();
    int get_r();
    bool is_pressed(int click_x, int click_y);
    Building_menu call_menu();
    void draw(sf::RenderWindow& window);
};

