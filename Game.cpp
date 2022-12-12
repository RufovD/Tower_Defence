#include "Game.h"
#include "Button.h"


void Game::init_variables() {
	is_main_menu = true;
}

void Game::init_window() {
	video_mode.height = 540;
	video_mode.width = 960;
	window.create(video_mode, "Kinda game", sf::Style::Titlebar | sf::Style::Close);
}

// ??? переделать
void Game::run_main_menu(sf::RenderWindow& window) {
	std::string file1 = "button_level_1";
	Button button1(0, 0, 200, 120, true, file1); //заглушка
	int mouse_x, mouse_y;

	while (is_main_menu) {
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

		mouse_x = event.mouseButton.x;
		mouse_y = event.mouseButton.y;
		if (button1.is_clickable &&
			mouse_x >= button1.x && mouse_x <= button1.x + button1.width &&
			mouse_y >= button1.y && mouse_y <= button1.y + button1.height)
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				button1.is_pressed = true;
				std::cout << " нопка нажата!" << std::endl;
			}
			else
				button1.is_hovered = true;

		
		window.clear();

		button1.update();

		button1.draw(window);

		window.display();
	}
}

Game::Game() {
	init_variables();
	init_window();
}

void Game::run_game() {
	run_main_menu(window);
}

void Game::destroy() {
	
}

