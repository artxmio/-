#pragma once
#include <string>
using namespace std;

class Restaurant
{
private:
	struct order
	{
		int order_num = 0; //����� ������
		string name_waiter = "non"; //��� ���������
		time_t order_time = 0.0; //����� ��������� ������
		bool done = false; //������� � ����������
		string filling = "non"; //���������� ������
	};

	string menu; //���� ���������
	order list[100];
public:
	Restaurant();
	void ShowOrders(); //������� ������ �������
	void ShowMenu(); //������� ����
	void AddOrder(); //�������� �����
	void DelOrder(); //������� �����
	void CheckMark(); //������� � ����������
};
