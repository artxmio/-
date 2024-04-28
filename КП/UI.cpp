#include "UI.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <map>;
#include <utility>
#include "User.h"
using namespace std;

void pause();

void UI::Hello() const
{
	cout << tab << "____________________________________________________\n" << endl;

	cout << tab << "\t����� ���������� � �TRENDY-�������!!!" << endl;

	cout << tab << "____________________________________________________\n";

	Sleep(2000);
}

void UI::ByeBye() const
{
	system("cls");
	cout << endl << tab << "__________________ [ ������ ] ___________________\n" << endl;
	cout << tab << "������� �� ��, ��� ������� ���� ����������!:)" << endl;
	cout << tab << "������ ��������� � ����� orders.txt:)";
	pause();
}

void UI::StartMenu() const
{
	LoadMenuAnimation();

	cout << tab << "_______________ [ ����� ���������� ] _______________" << endl << endl;
	cout << tab << "\t\t1. �����" << endl;
	cout << tab << "\t\t2. ������������������" << endl;
	cout << tab << "\t\t0. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

void UI::MainMenu() const
{
	LoadMenuAnimation();

	cout << tab << "_________________ [ ������� ���� ] _________________" << endl <<endl;
	cout << tab << "\t\t1. ������" << endl;
	cout << tab << "\t\t2. ���� ���������" << endl;
	cout << tab << "\t\t3. ������� ���������" << endl;
	cout << tab << "\t\t0. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

void UI::OrderMenu() const
{
	LoadMenuAnimation();

	cout << tab << "____________________ [ ������ ] ____________________" << endl;
	cout << endl << tab << "\t\t1. �������� ��� ������" << endl;
	cout << tab << "\t\t2. �������� ����� (admin)" << endl;
	cout << tab << "\t\t3. ������� ����� (admin)" << endl;
	cout << tab << "\t\t4. �������� ���������� ������ (admin)" << endl;
	cout << tab << "\t\t0. ����� � ������� ����" << endl;
	cout << endl << tab << "____________________________________________________\n";

}

User UI::Autorization() const
{
	system("cls");
	string _login;
	string _password;
	start_aut:
	cout << endl <<tab << "__________________ [ ����������� ] _________________" << endl;

	cout << endl << tab << "\t\t������� �����: ";
	cin >> _login;

	cout << endl << tab << "\t\t������� ������: ";
	cin >> _password;
	
	int _admin_code = 0;
	cout << endl << tab << "\t\t������� ��� ��������������?\n"
		<< tab << "(���� ��� ���, �������� ������ ������): ";
	cin >> _admin_code;

	cout << tab << "____________________________________________________\n";

	if (_logins.count(_login) > 0 and _logins.at(_login) == _password and _admin_code == 1488)
	{
		cout << tab << "������ �� ������ �������������� ��������";
		return User(true, _login, _password);
	}
	else if (_logins.count(_login) and _logins.at(_login) == _password)
	{
		cout << tab << "������ �� ������ �������������� ��������";
		return User(true, _login, _password);
	}
	else
	{
		cout << "�������� ����� ��� ������.";
		pause();
		system("cls");
		goto start_aut;
	}
}

User UI::Registration()
{
	system("cls");
	string _login;
	cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;
	cout << endl << tab << "\t\t������� �����: ";
	cin >> _login;

	string _password;
	cout << endl << tab << "\t\t������� ������: ";
	cin >> _password;

	cout << tab << "____________________________________________________\n";

	_logins.insert({_login, _password});
	SaveLogin(&_login, &_password);
	return Autorization();
}

void UI::RestaurantHistory() const
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

void UI::LoadMenuAnimation() const
{
	system("cls");

	const string load_simb = " - ";

	cout << tab << "____________________________________________________\n";
	cout << endl << "\t\t\t\t\t\t    ��������..." << endl;
	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "\t  [";
	for (int i = 0; i < 10; i++)
	{
		cout << load_simb;
		Sleep(200);
	}
	cout << "]\n";
	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "�������� ���������." << endl;
	Sleep(1000);
	system("cls");
}

void UI::LoadLogins()
{
	ifstream in("source\\logins.txt");
	string _login;
	string _pass;
	while (!in.eof() and in.peek() != EOF)
	{
		in >> _login;
		in >> _pass;
		
		_logins.insert({_login, _pass});
	}
	in.close();
}

void UI::SaveLogin(const string* login, const string* pass)
{
	ofstream out("source\\logins.txt", ios::app);

	out << *login << ' ';
	out << *pass << '\n';

	out.close();
}