#pragma once
#include "includes_file.h"

using namespace std;

class User;

//�����


class Restaurant
{
public:
	struct order
	{
		int order_num;       //����� ������
		string name_waiter;  //��� ���������
		string order_time;   //����� ��������� ������
		bool done;           //������� � ����������
		string filling;		 //���������� ������
		float price;		 //��������� 
	};

	Restaurant() noexcept;

	vector<order> get_list();

	void LoadOrders();		 //��������� ���������� � ������� �� �����
	void LoadMenuData();     //��������� ������ � ���� ���������

	void ShowOrders();       //������� ������ �������
	void ShowMenu();         //������� ����

	void AddOrder(User* u);         //�������� �����
	void DelOrder();         //������� �����
	void CheckMark();        //������� � ����������

	void AddNewMenuItem();   //�������� ����� ����� � ����
	void DelMenuItem();      //������� ����� ����

	void SaveOrders();       //��������� ����� � ����
	void SaveMenuData();     //��������� ���������� � ���� � ����
private:
	//����� ������
	struct ltime 
	{
		int seconds;
		int minutes;
		int hours;

		void SetTime() noexcept;
		string ToString();
	};
		
	ltime _time;
    int _order_index;
	bool _changed;		//���� ��������� ������ �������
	bool _changed_menu; //���� ��������� ����

	unordered_map<string, float> menu_list;

	vector<order> list;						//������ �������

	vector<string> ChooseDishes();								//����� ���� 
	float CalculatePrice(vector<string> keyDishes);				//������� ��������� ������
	bool checkOrder(vector<int> _orderIndexes, int _numOrder);	//�������� ������� ������ �� ������
};
