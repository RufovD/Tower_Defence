#include "Tower.h"

Tower::Tower(const sf::Texture& tex, int x, int y, double reloading_time, int damage_radius, int damage_value, int cost):
	x(x), y(y), reloading_time(reloading_time), damage_radius(damage_radius), damage_value(damage_value), cost(cost), 
	target(nullptr), is_loaded(true), cringe_time(0) 
{
	this->sprite.setTexture(tex);
	this->sprite.setPosition(x - 47, y - 125);
}

void Tower::choose_target(std::deque<Monster*> &active_monsters) {
	if (target == nullptr) {
		int index_of_nearset_monster = -1;
		int distance = damage_radius;
		for (int i = 0; i < active_monsters.size(); i++) {
			double r = (x - (*(active_monsters[i])).get_x()) * (x - (*(active_monsters[i])).get_x()) + (y - (*(active_monsters[i])).get_y()) * (y - (*(active_monsters[i])).get_y());
			if (r <= distance * distance) {
				index_of_nearset_monster = i;
				distance = r;
			};
		};
		if (index_of_nearset_monster != -1)
			target = active_monsters[index_of_nearset_monster];
	};
}

void Tower::make_damage() {
	if (target != nullptr && is_loaded == true) {
		target->get_damage(damage_value);
		is_loaded = false;
		cringe_time = 0;
	};
};

void Tower::target_check() {
	if (target != nullptr) {
		if (target->death() || (x - target->get_x()) * (x - target->get_x()) + (y - target->get_y()) * (y - target->get_y()) > damage_radius * damage_radius)
			target = nullptr;
	};
};

void Tower::reloading(float time) {
	if (is_loaded == false) {
		cringe_time += time;
		if (cringe_time >= reloading_time) {
			is_loaded = true;
			cringe_time = 0;
		}
	};
};

void Tower::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}