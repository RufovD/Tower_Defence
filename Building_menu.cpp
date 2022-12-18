#include "Building_menu.h"
#include "Building_place.h"
#include "Ground_Tower.h"
#include "Air_Tower.h"
#include "Uni_Tower.h"

Building_menu::Building_menu(int x2, int y2, Building_place* place) : x2(x2), y2(y2), x1(x2 - 3), x3(x2 + 3), y1(y2 - 1), y3(y2 - 1), 
    r(1), cost1(200), cost2(200), cost3(500), place(place) {
    std::string b1 = "Building_menu_Ground_sprite.png";
    std::string b2 = "Building_menu_Air_sprite.png";
    std::string b3 = "Building_menu_Uni_sprite.png";
    sf::Image image1, image2, image3;
    image1.loadFromFile("Images/" + b1);
    image2.loadFromFile("Images/" + b2);
    image3.loadFromFile("Images/" + b3);
    this->texture1.loadFromImage(image1);
    this->texture2.loadFromImage(image2);
    this->texture3.loadFromImage(image3);
    this->sprite1.setTexture(this->texture1);
    this->sprite2.setTexture(this->texture2);
    this->sprite3.setTexture(this->texture3);
    this->sprite1.setPosition(x1, y1);
    this->sprite1.setPosition(x2, y2);
    this->sprite1.setPosition(x3, y3);
};


bool Building_menu::is_pressed(int x, int y, int click_x, int click_y) {
    return (r * r >= (click_x - x) * (click_x - x) + (click_y - y) * (click_y - y));
};

bool Building_menu::first_pressed(int click_x, int click_y) {
    return is_pressed(x1, y1, click_x, click_y);
};

bool Building_menu::second_pressed(int click_x, int click_y) {
    return is_pressed(x2, y2, click_x, click_y);
};

bool Building_menu::third_pressed(int click_x, int click_y) {
    return is_pressed(x3, y3, click_x, click_y);
};

Ground_Tower Building_menu::build_ground_tower() {
    int x = place->get_x();
    int y = place->get_y();
    Ground_Tower gr_t(x, y);
    return gr_t;
};

Air_Tower Building_menu::build_air_tower() {
    int x = place->get_x();
    int y = place->get_y();
    Air_Tower air_t(x, y);
    return air_t;
};

Uni_Tower Building_menu::build_uni_tower() {
    int x = place->get_x();
    int y = place->get_y();
    Uni_Tower uni_t(x, y);
    return uni_t;
};
