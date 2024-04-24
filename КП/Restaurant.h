#pragma once
#include <string>
#include <vector>
using namespace std;

class Restaurant
{
private:
	struct ltime 
	{
		int seconds;
		int minutes;
		int hours;

		void SetTime();
		string ToString();
	};
	struct order
	{
		int order_num; //����� ������
		string name_waiter; //��� ���������
		ltime order_time; //����� ��������� ������
		bool done; //������� � ����������
		string filling; //���������� ������
	};

	string menu; //���� ���������
    int order_index;
	vector<order> list; //������ �������

	void AddOrder();
public:
	Restaurant();
	
	void ShowOrders(); //������� ������ �������
	void ShowMenu(); //������� ����
	void AddOrderInFile(); //�������� �����
	void DelOrder(); //������� �����
	void CheckMark(); //������� � ����������
};
