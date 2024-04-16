#pragma once
#include <string>
using namespace std;

struct order
{
	int order_num; //����� ������
	string name_waiter; //��� ���������
	time_t order_time; //����� ��������� ������
	bool done; //������� � ����������
	string filling; //���������� ������
};

class Restaurant
{
private:
	string path_orders; 
	string path_menu;
	string menu; //���� ���������
	order list[100];
	int i = 0; //����� ������ � �������
public:
	Restaurant();
	void ShowOrders(); //������� ������ �������
	void ShowMenu(); //������� ����
	void Add(); //�������� �����
	void Del(); //������� �����
	void CheckMark(); //������� � ����������
};
