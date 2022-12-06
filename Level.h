#pragma once
#include <vector>
#include <deque>
#include "Road.h"
#include "Building_place.h"
#include "Castle.h"
#include <fstream>
#include <string>
#include <sstream>

class Level
{
private:
	std::string file_name;
	template <typename T>
	std::vector<T> read_after_n_lines(unsigned int n, std::string& line, std::ifstream& f, T c);
	void skip_lines(unsigned int n, std::string& line, std::ifstream& f); //пропустить n линий и считать следующую

public:
	Level(std::string file_name);
	std::deque<Building_place> create_building_places();
	std::vector<Road> create_roads();
	Castle create_castle();
	std::vector<double> create_monsters_time();
	std::vector<Monster> create_monsters();
	int get_start_money();
};

