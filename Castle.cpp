#include "Castle.h"

Castle::Castle(int x, int y) : hp(100), x(x), y(y), is_alive(true) {
    std::string castle = "Castle_sprite.jpg";
    sf::Image image;
    image.loadFromFile("Images/" + castle);
    this->texture.loadFromImage(image);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 465, 500));
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