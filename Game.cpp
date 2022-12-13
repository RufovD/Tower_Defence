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
	std::string file1 = "button_level_1.jpg";
	std::vector<Button> buttons;
	Button button1(0, 0, 200, 120, true, 1, file1); //заглушка
	int mouse_x = 0;
	int mouse_y = 0;

	while (is_main_menu) {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				is_main_menu = false;
				window.close();
			}

		sf::Vector2i position = sf::Mouse::getPosition(window);
		std::cout << position.x << " " << position.y << std::endl;
		if (button1.is_clickable &&
			position.x >= button1.x && position.x <= button1.x + button1.width &&
			position.y >= button1.y && position.y <= button1.y + button1.height) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				button1.is_pressed = true;
				std::cout << "Button is pressed!" << std::endl;
			}
			/*else {
				button1.is_hovered = true;
				std::cout << "Button is hovered!" << std::endl;
			}*/
		}

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

void Game::run() {
	run_main_menu(window);
}

void Game::destroy() {

}