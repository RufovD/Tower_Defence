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
	std::string texture_file1 = "button.jpg";
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

	sf::Texture b_place_texture, b_menu_ground_texture, b_menu_air_texture, b_menu_uni_texture,
				ground_tower_texture, air_tower_texture, uni_tower_texture, bat_texture, 
				spider_texture, road_texture, castle_texture, grass_texture, money_texture;
	b_place_texture.loadFromFile("Images/building_place.png");
	b_menu_ground_texture.loadFromFile("Images/building_menu_ground.png");
	b_menu_air_texture.loadFromFile("Images/building_menu_air.png");
	b_menu_uni_texture.loadFromFile("Images/building_menu_uni.png");
	ground_tower_texture.loadFromFile("Images/ground_tower.png");
	air_tower_texture.loadFromFile("Images/air_tower.png");
	uni_tower_texture.loadFromFile("Images/uni_tower.png");
	bat_texture.loadFromFile("Images/bat.png");
	spider_texture.loadFromFile("Images/spider.png");
	road_texture.loadFromFile("Images/road.jpg");
	castle_texture.loadFromFile("Images/castle.png");
	grass_texture.loadFromFile("Images/grass.png");
	money_texture.loadFromFile("Images/money.png");

	std::deque<Building_place> building_places = level.create_building_places(b_place_texture);
	std::vector<Road> roads = level.create_roads(road_texture);
	Castle castle = level.create_castle(castle_texture);
	std::vector<float> monsters_time = level.create_monsters_time();
	std::vector<Monster> monsters = level.create_monsters();

	int money = level.get_start_money();

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

		//Рендеринг спрайтов
		window.draw(grass_sprite);
		for (Road road : roads)
			road.draw(window);
		castle.draw(window);
		for (Building_place b_place : building_places)
			b_place.draw(window);


		window.display();
	}
}

Game::Game() {
	init_variables();
	init_window();
}

void Game::destroy() {

}