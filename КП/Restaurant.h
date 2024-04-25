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

		void SetTime() noexcept;
		string ToString();
	};
	struct order
	{
		int order_num; //����� ������
		string name_waiter; //��� ���������
		string order_time; //����� ��������� ������
		bool done; //������� � ����������
		string filling; //���������� ������
	};
	ltime _time;
	string menu; //���� ���������
    int order_index = 0;
	vector<order> list; //������ �������

	
public:
	Restaurant() noexcept;

	void LoadOrders(); //��������� ���������� � ������� �� �����
	void ShowOrders(); //������� ������ �������
	void ShowMenu(); //������� ����
	void AddOrder();
	void AddOrderInFile(); //�������� �����
	void DelOrder(); //������� �����
	void CheckMark(); //������� � ����������
};
