#pragma once
class Castle
{
private:
    int hp;
    bool is_alive;

public:
    Castle(int hp);
    void get_damage(Moster monster);
    int get_hp();
    bool death();
};

