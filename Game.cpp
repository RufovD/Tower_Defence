#include "Game.h"
#include "Button.h"
#include "Level.h"


void Game::init_variables() {
	is_main_menu = true;
	curr_level = "null";
}

void Game::init_window() {
	video_mode.height = 1000;
	video_mode.width = 1500;
	window.create(video_mode, "Tower Defence", sf::Style::Titlebar | sf::Style::Close);
}

void Game::run() {
	run_main_menu(window);
	run_level(curr_level);
}

// ??? переделать
void Game::run_main_menu(sf::RenderWindow& window) {
	std::string texture_file1 = "button_level_1.jpg";
	std::string level_file1 = "Levels/level_1.txt";
	std::vector<Button> buttons;
	Button button1(0, 0, 200, 120, true, texture_file1, level_file1); //заглушка
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
				curr_level = level_file1;
				is_main_menu = false;
			}
			/*else {
				button1.is_hovered = true;
				std::cout << "Button is hovered!" << std::endl; // ???
			}*/
		}

		window.clear();

		button1.update();

		button1.draw(window);

		window.display();
	}
}

void Game::run_level(std::string &level_file) {
	Level level(level_file);
	std::deque<Building_place> building_places = level.create_building_places();
	std::vector<Road> roads = level.create_roads();
	Castle castle = level.create_castle();
	std::vector<float> monsters_time = level.create_monsters_time();
	std::vector<Monster> monsters = level.create_monsters();
	int money = level.get_start_money();

	//Создание спрайта травы
	sf::Texture grass_texture;
	grass_texture.loadFromFile("Images/Grass_sprite.png");
	grass_texture.setRepeated(true);
	sf::Sprite grass_sprite;
	grass_sprite.setTexture(grass_texture);
	grass_sprite.setTextureRect(sf::IntRect(0, 0, 1500, 1000));

	sf::Clock clock;
	float time = 0.f; //время, прошедшее с начала игры

	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float elapsed_time = elapsed.asSeconds(); //время, прошедшее за один цикл
		time += elapsed_time;

		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}



		std::cout << "Level is running " << std::endl;

		window.clear();

		window.draw(grass_sprite);

		window.display();
	}
}

Game::Game() {
	init_variables();
	init_window();
}

void Game::destroy() {

}