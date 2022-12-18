#include "Castle.h"

Castle::Castle(const sf::Texture& tex, int x, int y) : hp(100), x(x), y(y), is_alive(true) {
    this->sprite.setTexture(tex);
    this->sprite.setPosition(x, y);
}

void Castle::get_damage(Monster monster) {
    hp -= monster.make_damage();
    if (hp <= 0)
        is_alive = false;
};

int Castle::get_hp() {
    return hp;
};

bool Castle::death() {
    return !is_alive;
};

void Castle::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}