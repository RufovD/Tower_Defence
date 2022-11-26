#pragma once
class Road
{
private:
    int start_x, start_y, end_x, end_y;

public:
    Road(int start_x, int start_y, int end_x, int end_y);
    int get_start_x();
    int get_start_y();
    int get_end_x();
    int get_end_y();
};

