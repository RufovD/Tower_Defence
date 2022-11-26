#include "Castle.h"

Castle::Castle(int hp) : hp(hp), is_alive(true) {}

void Castle::get_damage(Moster monster) {
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