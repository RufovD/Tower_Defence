#pragma once
#include "Monster.h"
#include <deque>
#include <SFML/Graphics.hpp>

class Tower
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int x, y;
	bool is_loaded;
	double reloading_time;
	double cringe_time; //�����, � ������� ��������� ����� ��� ��������������;
	int damage_radius;
	int damage_value;
	Monster* target;
	int cost;

public:
	Tower(int x, int y, double reloading_time, int damage_radius, int damage_value, int cost, std::string& texture_file);
	void choose_target(std::deque<Monster>);
	void make_damage();
	void target_check();
	void reloading(double time); 
	void draw(sf::RenderWindow& window);
	//Builing_place destroy();
};

