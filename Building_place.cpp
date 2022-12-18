#include "Building_place.h"

Building_place::Building_place(const sf::Texture& tex, const sf::Texture& tex1, const sf::Texture& tex2, const sf::Texture& tex3, int x, int y) : 
    x(x), y(y), tex1(tex1), tex2(tex2), tex3(tex3), r(2) {
    this->sprite.setTexture(tex);
    this->sprite.setPosition(x, y);
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
    return (r * r >= (click_x - x) * (click_x - x) + (click_y - y) * (click_y - y));
};

Building_menu Building_place::call_menu(const sf::Texture& tex1, const sf::Texture& tex2, const sf::Texture& tex3) {
    return Building_menu(tex1, tex2, tex3, x, y - 5, this);
};

void Building_place::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
