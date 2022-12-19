#pragma once
#include <SFML/Graphics.hpp>

class Road
{
private:
    sf::Sprite sprite;
    int start_x, start_y, end_x, end_y;
    char direction; //l, r, u, d

public:
    Road(const sf::Texture& tex, int start_x, int start_y, int end_x, int end_y);
    int get_start_x();
    int get_start_y();
    int get_end_x();
    int get_end_y();
    void draw(sf::RenderWindow& window);
    char get_direction();
    //int abs(int a);
};

