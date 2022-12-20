#pragma once
#include "Monster.h"
#include <deque>
#include <SFML/Graphics.hpp>

class Tower
{
private:
	sf::Sprite sprite;

	int x, y;
	bool is_loaded;
	double reloading_time;
	double cringe_time; //�����, � ������� �������� ����� ��� ��������������;
	int damage_radius;
	int damage_value;
	Monster* target;

public:
	Tower(const sf::Texture& tex, int x, int y, double reloading_time, int damage_radius, int damage_value, int cost);
	void choose_target(std::deque<Monster*>& active_monsters);
	void make_damage();
	void target_check();
	void reloading(float time); 
	void draw(sf::RenderWindow& window);
	int cost;
};

