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
	void skip_lines(unsigned int n, std::string& line, std::ifstream& f); //?????????? n ????? ? ??????? ?????????

public:
	Level(std::string &file_name);
	std::deque<Building_place*> create_building_places(const sf::Texture& tex);
	std::vector<Road> create_roads(const sf::Texture& tex);
	Castle create_castle(const sf::Texture& tex);
	std::vector<float> create_monsters_time();
	std::vector<Monster> create_monsters(const sf::Texture& tex_spider, const sf::Texture& tex_bat);
	int get_start_money();	
};

