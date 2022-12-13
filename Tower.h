#pragma once
#include "Monster.h"
#include <deque>

class Tower
{
private:
	int x, y;
	bool is_loaded;
	double reloading_time;
	double cringe_time; //�����, � ������� ��������� ����� ��� ��������������;
	int damage_radius;
	int damage_value;
	Monster* target;

public:
	Tower(int x, int y, double reloading_time, int damage_radius, int damage_value);
	void choose_target(std::deque<Monster>);
	void make_damage();
	void target_check();
	void reloading(double time); 
	//Builing_place destroy();
};

