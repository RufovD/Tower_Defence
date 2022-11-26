#include "Monster.h"

Monster::Monster(int hp, int v, int x, int y, int damage_value, int money) : hp(hp), v(v), x(x), y(y), damage_value(damage_value), money(money), is_alive(true) {}

int Monster::get_hp() {
    return hp;
};

void Monster::get_damage(int damage_value) {
    hp -= damage_value;
    if (hp <= 0)
        is_alive = false;
};

int Monster::get_x() {
    return x;
};

int Monster::get_y() {
    return y;
};

int Monster::make_damage() {
    return damage_value;
};

int Monster::get_money() {
    return money;
};

bool Monster::death() {
    return !is_alive;
};

bool Monster::movement(int start_const, int end_const, int start_x, int end_x, int c, int& x, int v) {
    if ((c == start_const) && (c == end_const) && ((x >= start_x) && (x < end_x) || (x >= end_x) && (x < start_x))) {
        if (end_x - start_x >= 0) {
            x += v;
            if (x > end_x)
                x = end_x;
        }
        else {
            x -= v;
            if (x < end_x)
                x = end_x;
        };
        return true;
    };
    return false;
};

void Monster::go(Road* roads, unsigned int n) { 
    for (int i = 0; i < n; i++) {
        Road r = roads[i];
        if (movement(r.get_start_y(), r.get_end_y(), r.get_start_x(), r.get_end_x(), y, this->x, v))
            break;
        if (movement(r.get_start_x(), r.get_end_x(), r.get_start_y(), r.get_end_y(), x, this->y, v))
            break;
    };
};