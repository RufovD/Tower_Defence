#include "Level.h"
#include "Spider.h"
#include "Bat.h"

Level::Level(std::string file_name) : file_name(file_name) {}

void Level::skip_lines(unsigned int n, std::string& line, std::ifstream& f) {
	getline(f, line);
	for (int i = 0; i < n; i++)
		getline(f, line);
};

template <typename T>
std::vector<T> Level::read_after_n_lines(unsigned int n, std::string& line, std::ifstream& f, T c) { //T c ����� �� ������������, c ������ ������ ���� ���� T
	std::vector<T> x;
	T a;
	skip_lines(n, line, f);
	std::istringstream ss(line);
	while (ss >> a)
		x.push_back(a);
	return x;
};

std::deque<Building_place> Level::create_building_places() {
	std::ifstream f(file_name);
	std::deque<Building_place> building_places;
	std::vector<int> x, y;
	std::string line;
	if (f.is_open()) {
		x = read_after_n_lines(1, line, f, 1);
		y = read_after_n_lines(1, line, f, 1);
		for (int i = 0; i < x.size(); i++) {
			Building_place b(x[i], y[i]);
			building_places.push_back(b);
		};
		f.close();
	};
	return building_places;
};

std::vector<Road> Level::create_roads() {
	std::ifstream f(file_name);
	std::vector<Road> roads;
	std::vector<int> x, y;
	std::string line;
	if (f.is_open()) {
		x = read_after_n_lines(5, line, f, 1);
		y = read_after_n_lines(1, line, f, 1);
		for (int i = 0; i < x.size() - 1; i++) {
			Road r(x[i], y[i], x[i+1], y[i+1]);
			roads.push_back(r);
		};
		f.close();
	};
	return roads;
};

Castle Level::create_castle() {
	std::ifstream f(file_name);
	std::vector<int> x, y;
	std::string line;
	if (f.is_open()) {
		x = read_after_n_lines(5, line, f, 1);
		y = read_after_n_lines(1, line, f, 1);
		Castle c(x[x.size() - 1], y[y.size() - 1]);
		f.close();
		return c; //������������, ��� ���������� � ���
	};
};

int Level::get_start_money() {
	std::ifstream f(file_name);
	int m;
	std::string line;
	if (f.is_open()) {
		skip_lines(13, line, f);
		std::istringstream ss(line);
		ss >> m;
		f.close();
	};
	return m;
};

std::vector<double> Level::create_monsters_time(){
	std::ifstream f(file_name);
	std::vector<double> monsters_time;
	std::string line;
	if (f.is_open()) {
		monsters_time = read_after_n_lines(9, line, f, 1.234);
		f.close();
	};
	return monsters_time;
};

std::vector<Monster> Level::create_monsters() {
	std::ifstream f(file_name);
	std::vector<std::string> monsters_type;
	std::vector<Monster> monsters;
	int x0, y0;
	std::string line, a = "qw";
	if (f.is_open()) {
		std::vector<int> x = read_after_n_lines(5, line, f, 1);
		x0 = x[0];
		std::vector<int> y = read_after_n_lines(1, line, f, 1);
		y0 = y[0];
		monsters_type = read_after_n_lines(3, line, f, a);
		f.close();
	};

	std::string spider = "Spider";
	std::string bat = "Bat";

	for (int i = 0; i < monsters_type.size(); i++) {
		if (monsters_type[i] == spider) {
			Spider s(x0, y0);
			monsters.push_back(s);
		}
		else if (monsters_type[i] == bat) {
			Bat b(x0, y0);
			monsters.push_back(b);
		};
	};
	return monsters;
};
