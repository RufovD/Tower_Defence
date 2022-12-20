#pragma once

#include <SFML/Graphics.hpp>

class Button /* : public sf::Drawable*/ { // ??? возникают проблемы с конструктором
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int x, y; //координаты левого верхнего края
	int width, height; //длина и ширина 
	bool is_clickable; //можно ли нажать кнопку
	bool is_hovered; //наведён ли курсор мыши на кнопку
	bool is_pressed; //нажата ли кнопка
	std::string level_file;

public:
	Button(int x, int y, int width, int height, bool is_clickable,
		   std::string &texture_file, std::string &level_file);

	bool cursor_on_the_button(int cursor_x, int cursor_y);
	std::string pressing();
	void update();
	void draw(sf::RenderWindow& window);
};