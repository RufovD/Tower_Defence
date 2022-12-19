#pragma once
#include "Road.h"

class Monster
{
private:
    sf::Sprite sprite;
    int hp;
    char direction; //l, r, u, d
    int road_n; //номер дороги, на которой находится монстр
    bool is_alive;
    int v;
    double x, y;
    int damage_value;
    int reward; //денежная награда за смерть монстра
    char type;
    bool movement(int start_const, int end_const, int start_x, int end_x, int c, int& x, int v, char d);

public:
    Monster(const sf::Texture& tex, char type, int hp, int v, int x, int y, int damage_value, int money);
    int get_hp();
    char get_type();
    void get_damage(int damage_value);
    int get_x();
    int get_y();
    int make_damage();
    int get_reward();
    bool is_near_castle;
    bool death();

    void update_position(std::vector<Road>* roads, float time);

    void go(std::vector<Road> *roads, unsigned int n); //указатель на массив дорог и число элементов массива
    void draw(sf::RenderWindow& window);
};

