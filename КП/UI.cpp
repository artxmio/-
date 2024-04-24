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
	cout << tab << "____________________________________________________\n" << endl;

	cout << tab << "\t����� ���������� � �TRENDY-�������!!!" << endl;

	cout << tab << "____________________________________________________\n";

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

	cout << tab << "_________________ [ ������� ���� ] _________________" << endl <<endl;
	cout << tab << "\t\t1. ���� �������" << endl;
	cout << tab << "\t\t2. ���� ���������" << endl;
	cout << tab << "\t\t3. ������� ���������" << endl;
	cout << tab << "\t\t0. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

void UI::OrderMenu()
{
	LoadMenuAnimation();

	cout << tab << "____________________ [ ������ ] ____________________" << endl;
	cout << endl << tab << "\t\t1. �������� ��� ������ �������" << endl;
	cout << tab << "\t\t2. �������� ����� (admin)" << endl;
	cout << tab << "\t\t3. ������� ����� (admin)" << endl;
	cout << tab << "\t\t0. ����� � ������� ����" << endl;
	cout << endl << tab << "____________________________________________________\n";

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
	cout << endl <<tab << "__________________ [ ����������� ] _________________" << endl;
	
	cout << endl << tab << "\t\t������� ���: ";
	cin >> aut._name;

	cout << endl << tab << "\t\t������� �����: ";
	cin >> aut._login;

	cout << endl << tab << "\t\t������� ������: ";
	cin >> aut._password;
	
	cout << tab << "____________________________________________________\n";
	if (aut._login == "admin" && aut._password == "12345")
	{
		cout << endl << tab << "������ �� ������ �������������� ��������." << endl;
		Sleep(2000);
		return User(aut._name, true);
	}
	else if (aut._login == "user" && aut._password == "54321")
	{
		cout << endl << tab << "������ �� ������ ������������ ��������." << endl;
		Sleep(2000);
		return User(aut._name, false);
	}
	else
	{
		cout << endl << tab << "������ ������ ��� ������ �� ����������. ���������� �����." << endl;
		Sleep(2000);
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

	cout << tab << "____________________________________________________\n";
	cout << endl << tab << tab << "    ��������..." << endl;
	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "\t  [";
	for (int i = 0; i < 10; i++)
	{
		cout << load_simb;
		Sleep(200);
	}
	cout << "]\n";
	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "�������� ���������. ������� ����� ������� ��� �����������..." << endl;
	pause();
	system("cls");
}