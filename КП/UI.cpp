#include "UI.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <map>
#include "User.h"
using namespace std;

void pause();

void UI::MainMenu()
{
	LoadMenuAnimation();

	cout << "------------------ [ ������� ���� ] ------------------" << endl <<endl;
	cout << "\t\t1. ���� �������" << endl;
	cout << "\t\t2. ���� ���������" << endl;
	cout << "\t\t3. ������� ���������" << endl;
	cout << "\t\t0. �����" << endl;
}

void UI::OrderMenu()
{
	LoadMenuAnimation();

	cout << "--------------------- [ ������ ] ---------------------" << endl;
	cout << "\t\t1. ���������� �������" << endl;
	cout << "\t\t2. �������� ����� (admin)" << endl;
	cout << "\t\t3. ������� ����� (admin)" << endl;
	cout << "\t\t0. ����� � ������� ����" << endl;
}

struct autorization
{
	string _login;
	string _password;
	string _name;
};

User UI::Autorization()
{
	autorization aut;
	start_aut:
	cout << "------------------ [ ����������� ]------------------" << endl;
	
	cout << "\n\t\t������� ���: ";
	cin >> aut._name;

	cout << "\n\t\t������� �����: ";
	cin >> aut._login;

	cout << "\n\t\t������� ������: ";
	cin >> aut._password;
	
	cout << "____________________________________________________\n";
	if (aut._login == "admin" && aut._password == "12345")
	{
		cout << "\n������ �� ������ �������������� ��������." << endl;
		return User(aut._name, true);
	}
	else if (aut._login == "user" && aut._password == "54321")
	{
		cout << "\n������ �� ������ ������������ ��������." << endl;
		return User(aut._name, false);
	}
	else
	{
		cout << "\n������ ������ ��� ������ �� ����������. ���������� �����." << endl;
		pause();
		system("cls");
		goto start_aut;
	}
}

void UI::RestaurantHistory()
{
	LoadMenuAnimation();

	string line;

	ifstream in("source\\history.txt");
	if (in.is_open())
		while (getline(in, line))
		{
			cout << line << endl;
			Sleep(100);
		}
	in.close();
}

void UI::LoadMenuAnimation()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("cls");

	const string load_simb = " - ";

	cout << "��������..." << endl;
	cout << "\n[";
	for (int i = 0; i < 10; i++)
	{
		cout << load_simb;
		Sleep(300);
	}
	cout << "]";
	cout << "\n\n�������� ���������. ������� ����� ������� ��� �����������..." << endl;
	pause();
	system("cls");
}