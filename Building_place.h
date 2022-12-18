#pragma once
#include "Building_menu.h"
#include <SFML/Graphics.hpp>

class Building_place
{
private:
    sf::Sprite sprite;
    int x, y, r;

public:
    Building_place(const sf::Texture& tex, int x, int y);
    int get_x();
    int get_y();
    int get_r();
    bool is_pressed(int click_x, int click_y);
    //Building_menu call_menu(const sf::Texture& tex1, const sf::Texture& tex2, const sf::Texture& tex3);
    void draw(sf::RenderWindow& window);
};

