#include "Building_place.h"

Building_place::Building_place(const sf::Texture& tex, int x, int y) : 
    x(x), y(y), r(30) {
    this->sprite.setTexture(tex);
    this->sprite.setPosition(x - 41, y - 12);
}

bool Building_place::operator==(Building_place& b_place) const {
    if ((x == b_place.get_x()) && (y == b_place.get_y()))
        return true;
    else
        return false;
}


int Building_place::get_x() {
    return x;
};

int Building_place::get_y() {
    return y;
};

int Building_place::get_r() {
    return r;
};

bool Building_place::is_pressed(int click_x, int click_y) {
    return ((x - 41 <= click_x) && (click_x <= x + 40) && (y - 12 <= click_y) && (click_y <= y + 11));
};

//Building_menu Building_place::call_menu(const sf::Texture& tex1, const sf::Texture& tex2, const sf::Texture& tex3) {
  //  return Building_menu(tex1, tex2, tex3, x, y - 5, this);
//};

void Building_place::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
