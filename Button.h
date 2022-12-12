#pragma once

#include <SFML/Graphics.hpp>

class Button /* : public sf::Drawable*/ { // ??? ��������� �������� � �������������
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	int x, y; //���������� ������ �������� ����
	int width, height; //����� � ������ 
	bool is_clickable; //����� �� ������ ������
	bool is_hovered; //������ �� ������ ���� �� ������
	bool is_pressed; //������ �� ������

	Button(int x, int y, int width, int height, bool is_clickable, std::string& texture_file);

	void update();
	void draw(sf::RenderWindow& window);
};