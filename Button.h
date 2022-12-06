#pragma once
class Button
{
private:
	int x, y, level_number; //координаты левого верхнего края, номер запускаемого уровня
	int lenght_x, lenght_y; //длина по иксу, длина по игреку (есть способ сделать так, чтобы некоторое поле у всех представителей класса имело одно и только одно значение. надо посмотреть, как это сделать и применить к lenght)
	bool pressed; //нажата ли кнопка
public:
	Button(int x, int y, int level); //по умолчанию кнопка не нажаты
	bool is_pressed(int click_x, int click_y); //проверяет, нажата ли кнопка
	int get_level_number(); //возвращает номер уровня
	//void draw(); //рисует кнопку;
};

