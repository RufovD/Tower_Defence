#include "Road.h"

Road::Road(int start_x, int start_y, int end_x, int end_y) : start_x(start_x), start_y(start_y), end_x(end_x), end_y(end_y) {}

int Road::get_start_x() {
    return start_x;
};

int Road::get_start_y() {
    return start_y;
};

int Road::get_end_x() {
    return end_x;
};

int Road::get_end_y() {
    return end_y;
};
