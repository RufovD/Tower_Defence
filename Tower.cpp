#include "Tower.h"

void Tower::choose_target() {
    bool comp(const Monster* m1, const Monster* m2) {
        double r1, r2;
        r1 = (x - m1.x) * (x - m1.x) + (y - m1.y) * (y - m1.y);
        r2 = (x - m2.x) * (x - m2.x) + (y - m2.y) * (y - m2.y);
        return r1 < r2;
    }
    target = std::min(possible_targets.begin(), possible_targets.end(), comp);
}

Tower::Tower(int x, int y, int fire_rate, int damage_value, double damage_radius):
    x(x), y(y), fire_rate(fire_rate), damage_value(damage_value), damage_radius(damage_radius) {}

void Tower::destroy() {
    // этот tower должен удаляться из общего списка tower-ов
    // на месте этого tower должен создаться building_place
}
