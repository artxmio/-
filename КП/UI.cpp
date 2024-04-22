#include "UI.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;

void pause();

void UI::Hello()
{
	cout << "____________________________________________________\n";

	cout << "\n\t����� ���������� � �TRENDY-�������!!!" << endl;

	cout << "____________________________________________________\n";

	Sleep(2000);
}

void UI::ByeBye()
{
	system("cls");
	cout << "������� �� ��, ��� ������� ���� ����������!:)";
	pause();
}

void UI::MainMenu()
{
	LoadMenuAnimation();

	cout << "---------------- [ ������� ���� ] ------------------" << endl <<endl;
	cout << "\t\t1. ���� �������" << endl;
	cout << "\t\t2. ���� ���������" << endl;
	cout << "\t\t3. ������� ���������" << endl;
	cout << "\t\t0. �����" << endl;
	cout << "\n____________________________________________________\n";
}

void UI::OrderMenu()
{
	LoadMenuAnimation();

	cout << "------------------- [ ������ ] ---------------------" << endl;
	cout << "\n\t\t1. ���������� �������" << endl;
	cout << "\t\t2. �������� ����� (admin)" << endl;
	cout << "\t\t3. ������� ����� (admin)" << endl;
	cout << "\t\t0. ����� � ������� ����" << endl;
	cout << "\n____________________________________________________\n";

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
	cout << "\n------------------ [ ����������� ] -----------------" << endl;
	
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
	system("cls");

	const string load_simb = " - ";

	cout << "____________________________________________________\n";
	cout << "\n\t\t    ��������..." << endl;
	cout << "____________________________________________________\n";
	cout << "\n\t  [";
	for (int i = 0; i < 10; i++)
	{
		cout << load_simb;
		Sleep(300);
	}
	cout << "]\n";
	cout << "____________________________________________________\n";
	cout << "\n�������� ���������.\n������� ����� ������� ��� �����������..." << endl;
	pause();
	system("cls");
}