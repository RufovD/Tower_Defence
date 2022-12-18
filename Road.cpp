#include "Road.h"

int Road::abs(int a) {
    if (a >= 0)
        return a;
    else
        return -a;
}

Road::Road(int start_x, int start_y, int end_x, int end_y) : start_x(start_x), start_y(start_y), 
        end_x(end_x), end_y(end_y), f("Road_sprite.jpg")
{
    this->texture.loadFromFile("Images/" + f);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, abs(end_x - start_x) + 40, abs(end_y - start_y) + 40));
    this->sprite.setPosition(start_x, start_y);
}

int Road::get_start_x() {
    return start_x;
};

int Road::get_start_y() {
    return start_y;
};

int Road::get_end_x() {
    return end_x;
};

int Road::get_end_y() {
    return end_y;
};

void Road::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
