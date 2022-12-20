#include "Monster.h"

Monster::Monster(const sf::Texture& tex, char type, int hp, int v, int x, int y, int damage_value, int reward) : type(type), hp(hp), v(v), x(x - 28), y(y - 31), damage_value(damage_value),
reward(reward), is_alive(true), direction('r') {
    this->is_near_castle = false;
    this->road_n = 1;
    this->sprite.setTexture(tex);
    this->sprite.setPosition(x - 28, y - 31);
}

int Monster::get_hp() {
    return hp;
}

char Monster::get_type() {
    return type;
}

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

int Monster::get_reward() {
    return reward;
};

bool Monster::death() {
    return !is_alive;
};

bool Monster::movement(int start_const, int end_const, int start_x, int end_x, int c, int& x, int v, char d) {
    if ((c == start_const) && (c == end_const) && ((x >= start_x) && (x < end_x) || (x >= end_x) && (x < start_x))) {
        if (end_x - start_x >= 0) {
            x += v;
            if (x > end_x)
                x = end_x;

            if (d == 'h')
                direction = 'r';
            else
                direction = 'd';
        }
        else {
            x -= v;
            if (x < end_x)
                x = end_x;

            if (d == 'h')
                direction = 'l';
            else
                direction = 'u';
        };
        return true;
    };
    return false;
};

//void Monster::go(std::vector<Road> *roads, unsigned int n) { 
//    for (int i = 0; i < n; i++) {
//        Road r = (*roads)[i];
//        if (movement(r.get_start_y(), r.get_end_y(), r.get_start_x(), r.get_end_x(), y, this->x, v, 'h'))
//            break;
//        if (movement(r.get_start_x(), r.get_end_x(), r.get_start_y(), r.get_end_y(), x, this->y, v, 'v'))
//            break;
//    };
//};

void Monster::update_position(std::vector<Road>* roads, float time) {
    Road curr_road = (*roads)[road_n - 1];
    switch (curr_road.get_direction()) {
    case 'u':
        y -= v * time;
        if (y <= curr_road.get_end_y() + 31) {
            y = curr_road.get_end_y() + 31;
            road_n++;
        }
        break;
    case 'd':
        y += v * time;
        if (y >= curr_road.get_end_y() - 31) {
            y = curr_road.get_end_y() - 31;
            road_n++;
        }
        break;
    case 'r':
        x += v * time;
        if (x >= curr_road.get_end_x() - 28) {
            x = curr_road.get_end_x() - 28;
            road_n++;
        }
        break;
    case 'l':
        x -= v * time;
        if (x <= curr_road.get_end_x() - 28) {
            x = curr_road.get_end_x() - 28;
            road_n++;
        }
        break;
    }

    if (road_n > roads->size())
        is_near_castle = true;
    sprite.setPosition(x, y);
}

void Monster::draw(sf::RenderWindow& window) {
    window.draw(sprite);
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(hp, 10));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(x, y);
    window.draw(rectangle);
}
