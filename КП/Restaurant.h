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
		int price; //��������� 
	};
	ltime _time;
    int _order_index;
	bool _changed;

	vector<order> list; //������ �������
	
public:
	Restaurant() noexcept;

	void LoadOrders(); //��������� ���������� � ������� �� �����
	void ShowOrders(); //������� ������ �������
	void ShowMenu(); //������� ����
	void AddOrder(); //�������� �����
	void SaveOrders(); //�������� �����
	void DelOrder(); //������� �����
	void CheckMark(); //������� � ����������
};
