#include "Building_menu.h"
#include "Building_place.h"
#include "Ground_Tower.h"
#include "Air_Tower.h"
#include "Uni_Tower.h"

Building_menu::Building_menu(const sf::Texture& tex1, const sf::Texture& tex2, const sf::Texture& tex3, int x, int y, Building_place* place) : 
    x2(x - 34), y2(y - 95), x1(x - 75 - 34), x3(x + 75 - 34), y1(y - 85), y3(y - 85), r(34), cost1(200), cost2(200), cost3(500), place(place) {
    this->sprite1.setTexture(tex1);
    this->sprite2.setTexture(tex2);
    this->sprite3.setTexture(tex3);
    this->sprite1.setPosition(x1, y1);
    this->sprite2.setPosition(x2, y2);
    this->sprite3.setPosition(x3, y3);
};


bool Building_menu::is_pressed(int x, int y, int click_x, int click_y) {
    return (r * r >= (click_x - x) * (click_x - x) + (click_y - y) * (click_y - y));
};

bool Building_menu::first_pressed(int click_x, int click_y) {
    return is_pressed(x1 + r, y1 + r, click_x, click_y);
};

bool Building_menu::second_pressed(int click_x, int click_y) {
    return is_pressed(x2 + r, y2 + r, click_x, click_y);
};

bool Building_menu::third_pressed(int click_x, int click_y) {
    return is_pressed(x3 + r, y3 + r, click_x, click_y);
};

//Ground_Tower Building_menu::build_ground_tower() {
//    int x = place->get_x();
//    int y = place->get_y();
//    Ground_Tower gr_t(x, y);
//    return gr_t;
//};
//
//Air_Tower Building_menu::build_air_tower() {
//    int x = place->get_x();
//    int y = place->get_y();
//    Air_Tower air_t(x, y);
//    return air_t;
//};
//
//Uni_Tower Building_menu::build_uni_tower() {
//    int x = place->get_x();
//    int y = place->get_y();
//    Uni_Tower uni_t(x, y);
//    return uni_t;
//};

Building_place* Building_menu::get_place(){
    return place;
}

void Building_menu::draw(sf::RenderWindow& window) {
    window.draw(sprite1);
    window.draw(sprite2);
    window.draw(sprite3);
}

