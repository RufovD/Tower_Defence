#include "Game.h"
#include "Button.h"
#include "Level.h"
#include "Ground_Monster.h"
#include "Air_Monster.h"


void Game::init_variables() {
	is_main_menu = true;
	is_building_menu = false;
	curr_level = "null";
	is_victory = false;
}

void Game::init_window() {
	video_mode.height = 1000;
	video_mode.width = 1500;
	window.create(video_mode, "Tower Defence", sf::Style::Titlebar | sf::Style::Close);
}

void Game::run() {
	run_main_menu(window);
	run_level(curr_level);
	end_game(is_victory);
}

// ??? переделать
//void Game::run_main_menu(sf::RenderWindow& window) {
//	std::string texture_file1 = "button.jpg";
//	std::string level_file1 = "Levels/level_1.txt";
//	std::vector<Button> buttons;
//	Button button1(0, 0, 200, 120, true, texture_file1, level_file1); //заглушка
//	int mouse_x = 0;
//	int mouse_y = 0;
//
//	while (is_main_menu) {
//		sf::Event event;
//		while (window.pollEvent(event))
//			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//				is_main_menu = false;
//				window.close();
//			}
//
//		sf::Vector2i position = sf::Mouse::getPosition(window);
//		if (button1.is_clickable &&
//			position.x >= button1.x && position.x <= button1.x + button1.width &&
//			position.y >= button1.y && position.y <= button1.y + button1.height) {
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//				button1.is_pressed = true;
//				std::cout << "Button is pressed!" << std::endl;
//				curr_level = level_file1;
//				is_main_menu = false;
//			}
//			/*else {
//				button1.is_hovered = true;
//				std::cout << "Button is hovered!" << std::endl; // ???
//			}*/
//		}
//
//		window.clear();
//
//		button1.update();
//
//		button1.draw(window);
//
//		window.display();
//	}
//}

void Game::run_main_menu(sf::RenderWindow& window) {
	std::string texture_file1 = "button.jpg";
	std::string level_file1 = "Levels/level_1.txt";
	std::string level_file2 = "Levels/level_2.txt";
	std::vector<Button> buttons;
	Button button1(500, 500, 200, 120, true, texture_file1, level_file1); //заглушка
	Button button2(900, 500, 200, 120, true, texture_file1, level_file2); //заглушка
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
		if (button1.cursor_on_the_button(position.x, position.y)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				curr_level = button1.pressing();
				is_main_menu = false;
			}
		}

		if (button2.cursor_on_the_button(position.x, position.y)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				curr_level = button2.pressing();
				is_main_menu = false;
			}
		}

		window.clear();

		button1.update();
		button2.update();

		button1.draw(window);
		button2.draw(window);

		window.display();
	}
}

void Game::run_level(std::string &level_file) {
	Level level(level_file);
	int money = level.get_start_money();
	bool is_money_changed = false;
	std::cout << "Money: " << money << std::endl;
	int ground_cost = 200;
	int air_cost = 200;
	int uni_cost = 500;

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

	//std::deque<Building_place> building_places = level.create_building_places(b_place_texture);
	std::deque<Building_place*> building_places = level.create_building_places(b_place_texture);
	std::vector<Road> roads = level.create_roads(road_texture);
	Castle castle = level.create_castle(castle_texture);
	std::vector<float> monsters_time = level.create_monsters_time(); //моменты появлений монстров в уровне
	std::vector<Monster> monsters = level.create_monsters(spider_texture, bat_texture); //все монстры, которые должны появиться в уровне
	std::deque<Monster*> active_ground; //дека из указателей на активных (рисуемых) наземных монстров
	std::deque<Monster*> active_air; //дека из указателей на активных (рисуемых) наземных монстров
	std::vector<Ground_Tower> ground_towers;
	std::vector<Air_Tower> air_towers;
	std::vector<Uni_Tower> uni_towers;

	grass_texture.setRepeated(true);
	sf::Sprite grass_sprite;
	grass_sprite.setTexture(grass_texture);
	grass_sprite.setTextureRect(sf::IntRect(0, 0, 1500, 1000));

	sf::Clock clock;
	float time = 0.f; //время, прошедшее с начала игры
	int curr_monster = 0; //количество вышедших монстров
	int n_of_deathes = 0;

	int mouse_x = 0;
	int mouse_y = 0;
	std::vector<Building_menu> b_menu_vec; 

	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float elapsed_time = elapsed.asSeconds(); //время, прошедшее за один цикл
		time += elapsed_time;

		if (curr_monster < monsters.size() && time > monsters_time[curr_monster]) {
			switch (monsters[curr_monster].get_type()) {
			case 'g': //Ground_monster
				active_ground.push_back(&monsters[curr_monster]);
				break;
			case 'a': //Air_monster
				active_air.push_back(&monsters[curr_monster]);
				break;
			}
			curr_monster++;
		}

		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		
		sf::Vector2i position = sf::Mouse::getPosition(window);
		mouse_x = position.x;
		mouse_y = position.y;

		if (is_building_menu && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (b_menu_vec[0].first_pressed(mouse_x, mouse_y)) {
				if (ground_cost < money) {
					ground_towers.push_back(Ground_Tower(ground_tower_texture, b_menu_vec[0].get_place()->get_x(), b_menu_vec[0].get_place()->get_y()));
					money -= ground_cost;
					is_money_changed = true;
					for (int i = 0; i < size(building_places); i++)
						if (building_places[i] == b_menu_vec[0].get_place()) {
							building_places.erase(building_places.begin() + i);
							break;
						}
					delete b_menu_vec[0].get_place();
				}
			}
			else if (b_menu_vec[0].second_pressed(mouse_x, mouse_y)) {
				if (air_cost < money) {
					air_towers.push_back(Air_Tower(air_tower_texture, b_menu_vec[0].get_place()->get_x(), b_menu_vec[0].get_place()->get_y()));
					money -= air_cost;
					is_money_changed = true;
					for (int i = 0; i < size(building_places); i++)
						if (building_places[i] == b_menu_vec[0].get_place()) {
							building_places.erase(building_places.begin() + i);
							break;
						}
					delete b_menu_vec[0].get_place();
				}
			}
			else if (b_menu_vec[0].third_pressed(mouse_x, mouse_y)) {
				if (uni_cost < money) {
					uni_towers.push_back(Uni_Tower(uni_tower_texture, b_menu_vec[0].get_place()->get_x(), b_menu_vec[0].get_place()->get_y()));
					money -= uni_cost;
					is_money_changed = true;
					for (int i = 0; i < size(building_places); i++)
						if (building_places[i] == b_menu_vec[0].get_place()) {
							building_places.erase(building_places.begin() + i);
							break;
						}
					delete b_menu_vec[0].get_place();
				}
			}
			b_menu_vec.pop_back();
			is_building_menu = false;
		}

		if (!is_building_menu && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			for (Building_place* b_place : building_places)
				if (b_place->is_pressed(mouse_x, mouse_y)) {
					is_building_menu = true;
					b_menu_vec.push_back(Building_menu(b_menu_ground_texture, b_menu_air_texture, b_menu_uni_texture, b_place->get_x(), b_place->get_y(), b_place));
					break;
				}

		window.clear();

		//Обновление состояний башней, монстров, замка, денег
		std::deque<Monster*> *active_uni = new std::deque<Monster*>;
		*active_uni = active_ground;
		active_uni->insert(active_uni->cend(), active_air.cbegin(), active_air.cend());
		for (Ground_Tower tower : ground_towers) {
			tower.choose_target(active_ground);
			tower.make_damage();
			tower.target_check();
			tower.reloading(elapsed_time);
		}
		for (Air_Tower tower : air_towers) {
			tower.choose_target(active_air);
			tower.make_damage();
			tower.target_check();
			tower.reloading(elapsed_time);
		}
		for (Uni_Tower tower : uni_towers) {
			tower.choose_target(*active_uni);
			tower.make_damage();
			tower.target_check();
			tower.reloading(elapsed_time);
		}
		delete active_uni;

		for (int i = 0; i < active_ground.size(); i++)
			if (active_ground[i]->death()) {
				active_ground.erase(active_ground.begin() + i);
				n_of_deathes++;
			}
		for (int i = 0; i < active_air.size(); i++)
			if (active_air[i]->death()) {
				active_air.erase(active_air.begin() + i);
				n_of_deathes++;
			}
		for (Monster* monster : active_ground)
			if (!monster->is_near_castle)
				monster->update_position(&roads, elapsed_time);
			else
				castle.get_damage(*monster);
		for (Monster* monster : active_air)
			if (!monster->is_near_castle)
				monster->update_position(&roads, elapsed_time);
			else
				castle.get_damage(*monster);

		if (castle.death()) {
			is_victory = false;
			window.close();
		}
		if (n_of_deathes == monsters.size()) {
			is_victory = true;
			window.close();
		}

		//Отрисовка спрайтов и вывод денег в консоль
		if (is_money_changed) {
			std::cout << "Money: " << money << std::endl;
			is_money_changed = false;
		}

		window.draw(grass_sprite);
		for (Road road : roads) road.draw(window);
		if (!castle.death()) castle.draw(window);
		for (Building_place* place : building_places)
			if (place != nullptr)
				place->draw(window);
		for (Ground_Tower tower : ground_towers) tower.draw(window);
		for (Air_Tower tower : air_towers) tower.draw(window);
		for (Uni_Tower tower : uni_towers) tower.draw(window);
		for (Monster* monster : active_ground) monster->draw(window);
		for (Monster* monster : active_air) monster->draw(window);
		if (is_building_menu) b_menu_vec[0].draw(window);

		window.display();
	}
}

void Game::end_game(bool is_victory) {
	if (is_victory)
		std::cout << "WIN !" << std::endl;
	else
		std::cout << "LOST ..." << std::endl;
}

Game::Game() {
	init_variables();
	init_window();
}

void Game::destroy() {

}