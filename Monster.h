#pragma once
#include "Road.h"

class Monster
{
private:

    int hp;
    char direction; //l, r, u, d
    bool is_alive;
    int v, x, y;
    int damage_value;
    int money;
    char type;
    bool movement(int start_const, int end_const, int start_x, int end_x, int c, int& x, int v, char d);

public:
    Monster(char type, int hp, int v, int x, int y, int damage_value, int money); 
    int get_hp();
    char get_type();
    void get_damage(int damage_value);
    int get_x();
    int get_y();
    int make_damage();
    int get_money();
    bool death();
    void go(Road* roads, unsigned int n); //указатель на массив дорог и число элементов массива
};

