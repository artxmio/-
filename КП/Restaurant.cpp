#include "Restaurant.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <unordered_map>
#include <iomanip>
#include "UI.h"
using namespace std;

void pause();
string tab = "\t\t\t\t";

Restaurant::Restaurant() noexcept : _order_index(0)
{}

void Restaurant::ShowMenu()
{
	system("cls");
	ifstream fs("source\\menu.txt", ios::in | ios::binary);
	string menu;

	if (!fs) return;
	while (getline(fs, menu))
	{
		cout << menu << endl;
		Sleep(100);
	}

	fs.close();
}

void Restaurant::LoadOrders()
{
	ifstream in("source\\orders.txt");

	if (!in) return;

	order buff;
	while (!in.eof() and in.peek() != EOF)
	{
		in >> buff.order_num;
		in >> buff.name_waiter;
		in >> buff.price;
		in >> buff.order_time;
		in.get();
		getline(in, buff.filling);
		in >> buff.done;
		in.get();
		list.push_back(buff);
		_order_index++;
	}
	in.close();
}

void Restaurant::LoadMenuData()
{
	ifstream in("source\\menu_data.txt", ios::in);

	if (!in) return;

	while (!in.eof())
	{
		string _title;
		float _price;

		in.get();
		getline(in, _title);
		in >> _price;

		menu_list.insert({ _title, _price });
	}
}

void Restaurant::DelOrder()
{
	int _numorder;
	cout << endl << tab << "__________________ [ �������� ������ ] ___________________\n" << endl;
	cout << tab << "������� ����� ������: ";
	cin >> _numorder;

	if (_numorder < 0 or _numorder >= list.size() - 1)
	{
		cout << tab << "������ ������ �� ����������. ���������� � ������ ���.";
		pause();
		system("cls");
		return;
	}
	else
	{
		char change;
		cout << tab << "����� �" << _numorder << " �����." << endl;
		cout << tab << "��������� ���������? (��� �������� ������ ����� ��������)" << endl;
		cout << tab << "      1. ��" << endl;
		cout << tab << "      0. ���" << endl;
		cout << endl << tab << "____________________________________________________\n";
		change = _getch();

		if (change == '0') return;

		//�������� ��������

		for (int i = 0; i < _order_index; i++)
			if (_numorder == list.at(i).order_num)
				list.erase(list.begin() + i - 1);

		_order_index--;
		_changed = true;
	}

}

void Restaurant::ChooseDishes()
{
	cout << endl << tab << "_________________ [ ����� ����� ] __________________\n" << endl;
	PrintMenu();
}

void Restaurant::PrintMenu()
{
	for (const auto& dish : menu_list)
		cout << setw(67) << dish.first << setw(10) << dish.second << "BYN" << endl;
}

void Restaurant::ShowOrders()
{
	cout << endl << tab << "_____________________ [ ������ ] ____________________\n" << endl;
	for (int i = 0; i < _order_index; i++)
	{
		cout << tab << "\t����� �" << list.at(i).order_num + 1 << endl;
		cout << tab << "\t��� ���������: " << list.at(i).name_waiter << endl;
		cout << tab << "\t����� �������� ������: " << list.at(i).order_time << endl;
		cout << tab << "\t���������� ������: " << list.at(i).filling << endl;
		cout << tab << "\t���������: " << list.at(i).price << endl;
		cout << tab << "\t����������: " << (list.at(i).done ? "�����" : "�� �����") << endl;
		cout << tab << "____________________________________________________\n\n";
	}
	cout << tab << "������� ����� ������� ��� �����������..." << endl;
	pause();
}

void Restaurant::AddOrder()
{
	system("cls");
	_changed = true;
	order buff;

	cout << endl << tab << "__________________ [ ����� ����� ] _________________" << endl;

	buff.order_num = _order_index; //��������� ������ ������

	_time.SetTime();
	buff.order_time = _time.ToString(); // ��������� ������� ���������� ������

	buff.done = false;

	cout << endl << tab << "������� ��� ���������: ";
	cin >> buff.name_waiter;

	ChooseDishes();
	getline(cin, buff.filling);
	cout << endl << tab << "������� ��������� ������: ";
	cin >> buff.price;

	cout << endl << tab << "____________________________________________________\n";
	cout << endl << tab << "����� ����� ��������.";
	cout << endl << tab << "������� ����� ������� ��� �����������..." << endl;
	pause();
	list.push_back(buff);

	_order_index++;
}

void Restaurant::SaveOrders()
{
	int mode = 0;
	mode = _changed ? ios::out : ios::app;

	ofstream out("source\\orders.txt", mode);

	if (!out) return;

	if (_changed)
		for (int i = 0; i < _order_index; i++)
		{
			out << list.at(i).order_num << ' ';
			out << list.at(i).name_waiter << ' ';
			out << list.at(i).price << ' ';
			out << list.at(i).order_time << '\n';
			out << list.at(i).filling << '\n';
			out << list.at(i).done << '\n';
		}

	out.close();
}

void Restaurant::CheckMark()
{
	_changed = true;
	int _numorder = 0;
	cout << endl << tab << "__________________ [ �������� ������� ] ___________________\n" << endl;
	cout << tab << "������� ����� ������: ";
	cin >> _numorder;

	if (_numorder > size(list) or _numorder < 0)
	{
		cout << "������ ������ �� ����������.\n���������� � ������ ���.";
		pause();
		system("cls");
		return;
	}

	char change;
	cout << tab << "��������� ������ �" << _numorder << " �������� �� '�����'." << endl;
	cout << tab << "��������� ���������? (��� �������� ������ ����� ��������)" << endl;
	cout << tab << "      1. ��" << endl;
	cout << tab << "      0. ���" << endl;
	cout << endl << tab << "____________________________________________________\n";
	change = _getch();

	if (change == '0') return;
	list.at(_numorder - 1).done = true;
}

void Restaurant::ltime::SetTime() noexcept
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	seconds = time.wSecond;
	minutes = time.wMinute;
	hours = time.wHour;
}

string Restaurant::ltime::ToString()
{
	return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}
