#include "Button.h"

Button::Button(int x, int y, int width, int height, bool is_clickable, std::string& texture_file)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->is_clickable = is_clickable;
	this->is_hovered = false;
	this->is_pressed = false;
	sf::Image image;
	image.loadFromFile("Images/" + texture_file);
	this->texture.loadFromImage(image);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(x, y, width, height)); // ??? переделать 
}

void Button::update() {
	if (is_clickable)
		if (is_pressed)
			sprite.setColor(sf::Color::Yellow);
		else if (is_hovered)
			sprite.setColor(sf::Color::Green);
		else
			sprite.setColor(sf::Color(255, 255, 255, 128)); //полупрозрачный
	is_hovered = false;
	is_pressed = false;
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
