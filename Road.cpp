#include "Road.h"

//int Road::abs(int a) {
//    if (a >= 0)
//        return a;
//    else
//        return -a;
//}

Road::Road(const sf::Texture& tex, int start_x, int start_y, int end_x, int end_y) : start_x(start_x), start_y(start_y),
        end_x(end_x), end_y(end_y)
{
    this->sprite.setTexture(tex);
    int x1 = 0, y1 = 0;
    if (end_x - start_x == 0)
        x1 = 20;
    else
        y1 = 20;
    this->sprite.setPosition(start_x - x1, start_y - y1);
    this->sprite.setTextureRect(sf::IntRect(512, 512, end_x - start_x + 2 * x1, end_y - start_y + 2 * y1));
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
