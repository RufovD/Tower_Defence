#pragma once
class Button
{
private:
	int x, y, level_number; //���������� ������ �������� ����, ����� ������������ ������
	int lenght_x, lenght_y; //����� �� ����, ����� �� ������ (���� ������ ������� ���, ����� ��������� ���� � ���� �������������� ������ ����� ���� � ������ ���� ��������. ���� ����������, ��� ��� ������� � ��������� � lenght)
	bool pressed; //������ �� ������
public:
	Button(int x, int y, int level); //�� ��������� ������ �� ������
	bool is_pressed(int click_x, int click_y); //���������, ������ �� ������
	int get_level_number(); //���������� ����� ������
	//void draw(); //������ ������;
};

