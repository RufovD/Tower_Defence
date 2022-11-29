#pragma once

class Tower {
private:
    int x, y;
    int fire_rate;
    double damage_radius;
    int damage_value;
    Monster target;
    std::vector<Monster*> possible_targets;
    void choose_target();

public:
    Tower(int x, int y, int fire_rate, int damage_value, double damage_radius);
    void destroy();
};
