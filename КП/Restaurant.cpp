#include "Restaurant.h"
using namespace std;

void _getstring(string* str, int max);

void pause();

string tab = "\t\t\t\t"; //������

//����������� ������������� �������� ������ ������ � ������ � 0
Restaurant::Restaurant() noexcept : _order_index(0)
{}

vector<Restaurant::order> Restaurant::get_list()
{
	return this->list;
}

//����� ���� �� ����� menu.txt
void Restaurant::ShowMenu()
{
	system("cls");

	int i = 0;
	cout << endl << tab << "______________________ [ ���� ] _____________________" << endl << endl;

	for (const auto& dish : menu_list)
	{
		i++;
		cout << setw(34) << i << ". " << setw(35) << dish.first << setw(10) << dish.second << " BYN" << endl;
	}
	cout << tab << "_____________________________________________________\n\n";
}

//�������� ������� �� ����� orders.txt
void Restaurant::LoadOrders()
{
	ifstream in("source\\data\\orders.txt");

	if (!in) throw;

	order buff; //��������� ���������� ��� ������ ������ �� ������

	while (!in.eof() and in.peek() != EOF) //�������� �� ������ ����
	{
		in >> buff.order_num;
		in >> buff.name_waiter;
		in >> buff.price;
		in >> buff.order_time;
		in.get();
		getline(in, buff.filling);
		in >> buff.done;
		in.get();

		list.push_back(buff); //���������� ������ � ������

		
	}
	if (list.empty()) _order_index = 0;
	else _order_index = ((list.end() - 1)->order_num) + 1;		  //���������� ������� �� 1
	in.close();
}

//���������� �������� ���� � ��� � ������� (����:��������, ��������:����)
void Restaurant::LoadMenuData()
{
	ifstream in("source\\data\\menu_data.txt", ios::in);

	if (!in) throw;

	while (!in.eof())
	{
		string _title;
		float _price;

		in.get();
		getline(in, _title);
		in >> _price;

		menu_list.insert({ _title, _price }); //���������� ���� � �������
	}
}

//�������� �� ������� ������ � ������ �� ��� ������ (order.numorder)
bool Restaurant::checkOrder(vector<int> _orderIndexes, int _numOrder)
{
	//������������ ������� ��������: ���� ����� ���� � ������ - true, � ��������� ������ - false
	return (find(begin(_orderIndexes), end(_orderIndexes), _numOrder) != end(_orderIndexes));
}

//������� �������� ������
void Restaurant::DelOrder()
{
	while (true)
	{
		cout << endl << tab << "__________________ [ �������� ������ ] ____________________\n" << endl;

		//����� ��������� (��������� � ������) ������� �� ��������

		//���� ������ ����, ������ ��� ������ ���� (return)
		vector<int> availableOrders{};
		cout << endl << tab << "��������� ������:" << endl << tab;
		if (list.empty())
		{
			cout << "���� ��� ������� ���" << endl;
			pause();
			return;
		}
		else
			for (int i = 0; i < list.size(); i++)
			{
				availableOrders.push_back(list.at(i).order_num);
				cout << list.at(i).order_num + 1 << " ";
			}

		cout << endl << tab << "������� ����� ������: ";

		string numorder;
		_getstring(&numorder, 4);

		if (numorder.empty())
			return;

		int _numorder = 0;

		try
		{
			_numorder = stoi(numorder);
		}
		catch (const exception& e)
		{
			cout << endl << tab << "�������� ��������" << endl;
			pause();
			return;
		}

		if (!(checkOrder(availableOrders, _numorder - 1)))
		{
			cout << endl << tab << "������ ������ �� ����������. ���������� � ������ ���.";
			pause();
			system("cls");
			return;
		}
		//������������� ��������
		char _change;
		cout << endl << tab << "����� �����." << endl;
		cout << tab << "��������� ���������? (��� �������� ������ ����� ��������)" << endl;
		cout << tab << "      y. ��" << endl;
		cout << tab << "      n. ���" << endl;
		cout << endl << tab << "___________________________________________________________\n";

		for (;;)
		{
			_change = _getch();
			if (_change == 'n') return;
			else if (_change == 'y') break;
		}

		//�������� ��������


		for (int i = 0; i < list.size(); i++)
		{
			if (list.at(i).order_num == (_numorder - 1))
			{
				list.erase(list.begin() + i);
				break;
			}
		}

		_changed = true; //����� � ��������� ������

		system("cls");
		SaveOrders();
		return;
	}
}

//����� ���� (��������� ������� AddOrder())
vector<string> Restaurant::ChooseDishes()
{
	//��������� �����
	vector<string> dishes{};

	bool _continue = true;
	do
	{
		system("cls");
		cout << endl << tab << "_________________ [ ����� ����� ] __________________\n" << endl;

		//����� ����
		ShowMenu();

		//����� ���������� � ������� �� ���� � ������
		cout << tab << "������� ��� �����:\n";
		cout << tab;

		string dish;
		_getstring(&dish, 4);

		if (dish.empty()) return vector<string>();

		int _dish = 0;

		try
		{
			_dish = stoi(dish);
		}
		catch (const exception& ex)
		{
			cout << tab << "�������� ��������." << endl;
			cout << tab << "������� ����� ������� ��� �����������" << endl;
			pause();
			continue;
		}

		//�� ������, ��� � ������ ����
		if (_dish <= 0 or _dish > menu_list.size())
		{
			cout << tab << "��� ������ �����." << endl;
			cout << tab << "������� ����� ������� ��� �����������" << endl;

			pause();
			continue;
		}

		//����� ����� �� ������ � ������
		string keyDish;
		int counter = 0;
		for (auto& d : menu_list)
			if (counter != _dish - 1)
			{
				counter++;
				continue;
			}
			else
			{
				keyDish = d.first;
				break;
			}

		dishes.push_back(keyDish);
		cout << endl  << tab << "��� ��? (y/n)" << endl;

		do
		{
			const char __continue = _getch();
			if (__continue == 'y')
			{
				_continue = false;
				break;
			}
			else if (__continue == 'n')
				break;

		} while (true);

	} while (_continue);

	//������������ ������ � �������
	return dishes;
}

//������� ���� ������ �� ��������� ������
float Restaurant::CalculatePrice(vector<string> keyDishes)
{
	float _price = 0;
	for (int i = 0; i < keyDishes.size(); i++)
	{
		_price += menu_list[keyDishes.at(i)];
	}
	return _price;
}

//����� ���� ������� �� �����
void Restaurant::ShowOrders()
{
	//��������� �� ��������� ��������� � ������
	if (list.empty())
	{
		cout << endl << tab << "_____________________ [ ������ ] ____________________\n" << endl;
		cout << tab << "���� ��� ������� ���" << endl;
		cout << tab << "������� ����� ������� ��� �����������..." << endl;
		pause();
		return;
	}

	int i = 0;

	for (;;)
	{
		system("cls");
		cout << endl << "\n\n" << tab << "_____________________ [ ������ ] ____________________\n" << endl;

		cout << tab << "\t����� �" << list.at(i).order_num + 1 << endl;
		cout << tab << "\t���: " << list.at(i).name_waiter << endl;
		cout << tab << "\t����� �������� ������: " << list.at(i).order_time << endl;

		//����� ����������� ������
		cout << tab << "\t���������� ������:\n";

		cout << tab << '\t';
		string filling = list.at(i).filling;

		//����� �����������, ����� � ������ ������ ��������� �������
		cout << "\n" << tab << "\t   ";
		for (int j = 0; j < filling.size(); j++)
			if (filling[j] == ',') cout << endl << tab << "\t   ";
			else cout << filling[j];

		cout << endl;
		cout << tab << "\t���������: " << list.at(i).price << "BYN" << endl;
		cout << tab << "\t����������: " << (list.at(i).done ? "�����" : "�� �����") << endl;
		cout << tab << "____________________________________________________\n\n";
		cout << tab << " ��������� �����/������: ����������/��������� �����\n";
		cout << tab << " esc: �����\n\n";
		
		//esc
		if (_getch() == 27) return;

		const char _code_key = _getch();

		//���������� ���������
		if (_code_key == 75)
			i--;
		else if (_code_key == 77)
			i++;

		//�������� �� ����� �� ������� ������
		if (i < 0) i = 0;
		else if (i >= list.size()) i = list.size() - 1;
	}

}

//���������� ������ ������
void Restaurant::AddOrder(User* u)
{
	system("cls");
	system("mode con cols=115 lines=40");
	_changed = true;

	order buff;

	cout << endl << tab << "__________________ [ ����� ����� ] _________________" << endl;

	buff.order_num = _order_index; //��������� ������ ������

	_time.SetTime();
	buff.order_time = _time.ToString(); // ��������� ������� ���������� ������

	buff.done = false;

	buff.name_waiter = u->_login;

	if (buff.name_waiter.empty())
	{
		system("mode con cols=115 lines=30");
		return;
	}

	//���������� ������
	vector<string> _dishes = ChooseDishes();

	if (_dishes.empty())
	{
		system("mode con cols=115 lines=30");
		return;
	}

	for (const auto& dish : _dishes)
		buff.filling += dish + ",";

	//��������� ������
	buff.price = CalculatePrice(_dishes);

	cout << endl << tab << "____________________________________________________\n";
	cout << endl << tab << "����� ����� ��������.";
	cout << endl << tab << "������� ����� ������� ��� �����������..." << endl;
	pause();

	list.push_back(buff);

	_order_index++;
	SaveOrders();
	system("mode con cols=115 lines=30");
}

//���������� ������ � ������ � ����
void Restaurant::SaveOrders()
{
	if (!_changed) return;

	const int mode = ios::out;

	ofstream out("source\\data\\orders.txt", mode);

	if (!out) return;

	for (const auto& item: list)
	{
		out << item.order_num << ' ';
		out << item.name_waiter << ' ';
		out << item.price << ' ';
		out << item.order_time << '\n';
		out << item.filling << '\n';
		out << item.done << '\n';
	}

	out.close();
}

//���������� ������ � ����
void Restaurant::SaveMenuData()
{
	if (!_changed_menu) return;

	const int mode = ios::out;

	ofstream out("source\\data\\menu_data.txt", mode);

	if (!out) return;

	for (auto& item : menu_list)
	{
		out << endl << item.first;
		out << endl << item.second;
	}

	out.close();
}

//��������� ���������� ������
void Restaurant::CheckMark()
{
	if (list.empty())
	{
		cout << tab << "���� ��� ������� ���" << endl;
		pause();
		return;
	}

	_changed = true;

	while (true)
	{
		system("cls");

		cout << endl << tab << "__________________ [ �������� ������� ] ___________________\n";

		cout << endl << tab << "	�������� ���������� �������" << endl;
		cout << endl << tab << "	esc: �����" << endl;
		cout << endl << tab << "___________________________________________________________\n";

		vector<int> availableOrders{};
		cout << endl << tab << "��������� ������:" << endl << tab;
		if (list.empty())
		{
			cout << "���� ��� ������� ���" << endl;
			pause();
			return;
		}
		else
			for (int i = 0; i < list.size(); i++)
			{
				if(!list.at(i).done)
				{
					availableOrders.push_back(list.at(i).order_num);
					cout << list.at(i).order_num + 1 << " ";
				}
			}

		if (availableOrders.empty())
		{
			cout << "���� ��� ������� ��� ��� ��� ��� ������" << endl;
			pause();
			return;
		}

		cout << endl << tab << "������� ����� ������: ";

		string numorder;
		_getstring(&numorder, 4);

		if (numorder.empty())
			return;

		int _numorder = 0;

		try
		{
			_numorder = stoi(numorder);
		}
		catch (const exception& e)
		{
			cout << endl << tab << "�������� ��������" << endl;
			pause();
			continue;
		}

		if (!(checkOrder(availableOrders, _numorder - 1)))
		{
			cout << endl << tab << "������ ������ �� ����������. ���������� � ������ ���.";
			pause();
			system("cls");
			return;
		}

		cout << endl << tab << "��������� ������ �" << _numorder << " �������� �� '�����'." << endl;
		cout << tab << "��������� ���������? (��� �������� ������ ����� ��������)" << endl;
		cout << tab << "      y. ��" << endl;
		cout << tab << "      n. ���" << endl;
		cout << endl << tab << "___________________________________________________________\n";

		for (;;)
		{
			const char _change = _getch();
			if (_change == 'n') return;
			else if (_change == 'y') break;
		}

		for (auto& item : list)
		{
			if (item.order_num == (_numorder - 1))
			{
				item.done = true;
				break;
			}
		}
		break;
	}
	SaveOrders();
}

//�������� ����� ����� ����
void Restaurant::AddNewMenuItem()
{
	_changed_menu = true;

	bool _continue = true;
	do
	{
		system("cls");
		cout << endl << tab << "____________________ [ ���� ] ___________________" << endl;

		//�������� �����
		string dish_title = "";
		cout << endl << tab << "�������� �����: \n";
		cout << tab;

		_getstring(&dish_title, 30);

		if (dish_title.empty()) return;

		//����
		string price;

		cout << endl << tab << "���� ����� (�������� 14.88): \n" << tab;

		_getstring(&price, 30);

		if (price.empty()) return;

		float _price = 0.0;
		try
		{
			_price = stof(price);
		}
		catch (const exception& ex)
		{
			cout << endl << tab << "____________________________________________________\n\n";
			cout << tab << "�������� ��������." << endl;
			cout << tab << "������� ����� ������� ��� �����������" << endl;
			pause();
			continue;
		}

		if (_price <= 0)
		{
			cout << endl << tab << "____________________________________________________\n\n";
			cout << tab << "�������� ��������" << endl;
			pause();
			system("cls");
			continue;
		}

		//���������� �� 2 ������ ����� �������
		_price = round((_price * 100)) / 100.0;

		cout << endl << tab << "____________________________________________________\n\n";

		cout << tab << "����� ����� ���� ��������" << endl;

		menu_list.insert({ dish_title, _price });
		cout << tab << "������� ����� �������, ����� �����" << endl;
		pause();
		_continue = false;
	} while (_continue);

}

//������� ����� ���� �� �������� �����
void Restaurant::DelMenuItem()
{
	system("mode con cols=115 lines=50");

	cout << endl << tab << "______________________ [ ���� ] ______________________" << endl;

	if (menu_list.empty())
	{
		cout << "���� ��� ������� ���" << endl;
		pause();
		return;
	}

	ShowMenu();

	cout << tab << "��� �������� ����� �� ������ ���������� ������\n" << tab << "��� ��������";
	cout << endl << tab << "_____________________________________________________\n";

	//�������� �����
	string dish_title = "";
	cout << endl << tab << "�������� �����: \n";
	cout << tab;


	_getstring(&dish_title, 25);

	if (dish_title.empty()) return;

	if (!menu_list.count(dish_title))
	{
		cout << endl << tab << "_____________________________________________________\n";
		cout << tab << "������ ����� �� ����������" << endl;
		pause();
		system("mode con cols=115 lines=30");
		return;
	}

	//������������� ��������
	cout << endl << tab << "_____________________________________________________\n";

	cout << endl << tab << dish_title << " �����." << endl;
	cout << tab << "��������� ���������? (��� �������� ������ ����� ��������)" << endl;
	cout << tab << "      y. ��" << endl;
	cout << tab << "      n. ���" << endl;
	cout << endl << tab << "_____________________________________________________\n";

	for (;;)
	{
		const char _change = _getch();
		if (_change == 'n') return;
		else if (_change == 'y') break;
	}

	menu_list.erase(dish_title);

    system("mode con cols=115 lines=30");
}

//��������� ������� ���������� ������
void Restaurant::ltime::SetTime() noexcept
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	seconds = time.wSecond;
	minutes = time.wMinute;
	hours = time.wHour;
}

//������� ������� � ������
string Restaurant::ltime::ToString()
{
	return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}