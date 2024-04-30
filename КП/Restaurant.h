#pragma once
#include <string>
#include <vector>
#include <unordered_map>
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
		int order_num;       //����� ������
		string name_waiter;  //��� ���������
		string order_time;   //����� ��������� ������
		bool done;           //������� � ����������
		string filling;		 //���������� ������
		float price;		 //��������� 
	};
	ltime _time;
    int _order_index;
	bool _changed;

	unordered_map<string, float> menu_list; //���� ���������
	vector<order> list;		 //������ �������

	void PrintMenu();        //����� ����
	vector<string> ChooseDishes();     //����� ���� 
	float CalculatePrice(vector<string> keyDishes);    //������� ��������� ������

public:
	Restaurant() noexcept;

	void LoadOrders();		 //��������� ���������� � ������� �� �����
	void LoadMenuData();     //��������� ������ � ���� ���������

	void ShowOrders();       //������� ������ �������
	void ShowMenu();         //������� ����

	void AddOrder();         //�������� �����
	void SaveOrders();       //��������� ����� � ����

	void DelOrder();         //������� �����
	void CheckMark();        //������� � ����������
};
