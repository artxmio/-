#include "Restaurant.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "UI.h"
using namespace std;

void pause();
string tab = "\t\t\t\t";

Restaurant::Restaurant() noexcept : _order_index(0)
{
	srand(static_cast<unsigned int>(time(0)));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

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

void Restaurant::DelOrder()
{

}

void Restaurant::ShowOrders()
{
	cout << endl << tab << "_____________________ [ ������ ] ___________________\n" << endl;
	for (int i = 0; i < _order_index; i++)
	{
		cout << tab << "\t����� �" << list.at(i).order_num + 1 << endl;
		cout << tab << "\t��� ���������: " << list.at(i).name_waiter << endl;
		cout << tab << "\t����� �������� ������: " << list.at(i).order_time << endl;
		cout << tab << "\t���������� ������: " << list.at(i).filling << endl;
		cout << tab << "\t����������: " << list.at(i).done << endl;
		cout << tab << "____________________________________________________\n\n";
	}
	pause();
}

void Restaurant::AddOrder()
{
	system("cls");

	order buff;

	cout << endl << tab << "__________________ [ ����� ����� ] _________________" << endl;

	buff.order_num = _order_index; //��������� ������ ������

	_time.SetTime();
	buff.order_time = _time.ToString(); // ��������� ������� ���������� ������

	buff.done = false;

	cout << endl << tab << "������� ��� ���������: ";
	cin >> buff.name_waiter;

	cout << endl << tab << "������� ���������� ������: ";
	cin.get();
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

void Restaurant::AddOrderInFile()
{
	ofstream out("source\\orders.txt", ios::app);

	if (!out) return;
	for (int i = 0; i < _order_index; i++)
	{
		out << list.at(i).order_num << ' ';
		out << list.at(i).name_waiter << ' ';
		out << list.at(i).order_time << '\n';
		out << list.at(i).filling << '\n';
		out << list.at(i).done << '\n';
	}

	out.close();
}

void Restaurant::CheckMark()
{
	int _numorder = 0;
	cout << "������� ����� ������: ";
	cin >> _numorder;
	bool change;
	cout << "��������� ������ �������� �� true (�����)." << endl;
	cout << "��������� ���������?" << endl;
	cout << "1. ��" << endl;
	cout << "0. ���" << endl;
	change = _getch();
	change ? list.at(_numorder - 1).done = true : list.at(_numorder - 1).done = false;
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
