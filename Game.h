#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class Game {
private:
	sf::RenderWindow window;
	sf::VideoMode video_mode;
	bool is_main_menu; //запущено ли главное меню

	void init_variables(); // ??? инициализирует основные переменные игры (что? какие?) 
	void init_window();
	void run_main_menu(sf::RenderWindow& window);

public:
	Game();

	void run();
	void destroy();
};

