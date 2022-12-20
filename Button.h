#pragma once

#include <SFML/Graphics.hpp>

class Button /* : public sf::Drawable*/ { // ??? ��������� �������� � �������������
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int x, y; //���������� ������ �������� ����
	int width, height; //����� � ������ 
	bool is_clickable; //����� �� ������ ������
	bool is_hovered; //������ �� ������ ���� �� ������
	bool is_pressed; //������ �� ������
	std::string level_file;

public:
	Button(int x, int y, int width, int height, bool is_clickable,
		   std::string &texture_file, std::string &level_file);

	bool cursor_on_the_button(int cursor_x, int cursor_y);
	std::string pressing();
	void update();
	void draw(sf::RenderWindow& window);
};