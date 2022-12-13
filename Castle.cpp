#include "Castle.h"

Castle::Castle(int x, int y) : hp(100), x(x), y(y), is_alive(true) {}

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