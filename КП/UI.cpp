#include "UI.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <map>;
#include "User.h"
using namespace std;

void pause();

void UI::Hello() const
{
	cout << n;

	cout << tab << "____________________________________________________\n" << endl;
	cout << tab << "\t����� ���������� � �TRENDY-�������!!!" << endl;
	cout << tab << "____________________________________________________\n";

	Sleep(2000);
}

void UI::ByeBye() const
{
	system("cls");
	cout << n;
	cout << endl << tab << "___________________ [ ������ ] _____________________\n" << endl;
	cout << tab << "������� �� ��, ��� ������� ���� ����������!:)" << endl;
	cout << tab << "������ ��������� � ����� orders.txt:)" << endl;
	cout << endl << tab << "____________________________________________________\n";
	pause();
}

void UI::StartMenu() const
{
	LoadMenuAnimation();
	cout << n;

	cout << tab << "_______________ [ ����� ���������� ] _______________" << endl << endl;
	cout << tab << "\t\t1. �����" << endl;
	cout << tab << "\t\t2. ������������������" << endl;
	cout << tab << "\t\t0. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

void UI::MainMenu() const
{
	LoadMenuAnimation();
	cout << n;

	cout << tab << "_________________ [ ������� ���� ] _________________" << endl << endl;
	cout << tab << "\t\t1. ������" << endl;
	cout << tab << "\t\t2. ���� ���������" << endl;
	cout << tab << "\t\t3. ������� ���������" << endl;
	cout << tab << "\t\tesc. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

void UI::OrderMenu(const  User* u) const
{
	LoadMenuAnimation();
	cout << n;

	cout << tab << "____________________ [ ������ ] ____________________" << endl;
	cout << endl << tab << "\t\t1. �������� ��� ������" << endl;

	//������ ����������� �����
	if (u->is_admin())
	{
		cout << tab << "\t\t2. �������� �����" << endl;
		cout << tab << "\t\t3. ������� �����" << endl;
		cout << tab << "\t\t4. �������� ���������� ������" << endl;
	}

	cout << tab << "\t\tesc. ����� � ������� ����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

User UI::Autorization() const
{
	system("cls");
	LoadMenuAnimation();

	//��� �������� ������� ������ � ������
	string _login;
	string _password;
	int _sys_admin_code_ = 123;

start_aut:
	//��������� ������ �� ������������
	cout << n;
	cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;

	cout << endl << tab << "\t\t������� �����: ";
	cin >> _login;

	cout << endl << tab << "\t\t������� ������: ";
	cin >> _password;

	/*
		��� ������������ �� ������� �������� �������� ��������������
		����� � ������������ ��� ������ � ������ ��������������, ����� ��� ��������������
	*/

	//��������� ���� ��������������
	cout << endl << tab << "\t\t� ��� ���� ��� ��������������? (y/n)\n";

	int _admin_code = 0;
	bool _continue = true;
	//���� ���� ���, �� ������� ���� ������� � �������� �������� ������
	do
	{
		switch (_getch())
		{
		case 'y':
			cout << endl << tab << "\t\t��� ��������������: ";
			cin >> _admin_code;
			_continue = false;
			break;
		case 'n':
			_continue = false;
			break;
		default: break;
		}
	} while (_continue);

	cout << tab << "____________________________________________________\n\n";

	//�������� ������ �� ������� � ���� ������ � ���� ��������������
	if (_logins.count(_login) > 0 and _logins.at(_login) == _password and _admin_code == _sys_admin_code_)
	{
		cout << tab << "������ �� ������ �������������� ��������";
		cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
		pause();
		return User(true, _login, _password);
	}
	else if (_logins.count(_login) and _logins.at(_login) == _password) //��� ���� �������������� ��� �� ��������
	{
		cout << tab << "������ �� ������ ������������ ��������";
		cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
		pause();
		return User(false, _login, _password);
	}
	else //����������� ������
	{
		cout << endl << tab << "�������� ����� ��� ������.";
		cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
		pause();
		system("cls");
		goto start_aut;
	}
}

void UI::Registration()
{
	do
	{
		system("cls");
		cout << n;
		string _login;
		cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;

		//��������� ������ ������ � ������
		cout << endl << tab << "\t\t������� �����: ";
		cin >> _login;

		string _password;
		cout << endl << tab << "\t\t������� ������: ";
		cin >> _password;

		cout << tab << "____________________________________________________\n";

		//�������� �� ������������� ������ ������
		if (_logins.count(_login))
		{
			cout << endl << tab << "����� ����� ��� ����������.";
			cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
			pause();
		}
		else //����� ���������� � ������������
		{
			cout << endl << tab << "�� ������� ������������������." << endl;
			cout << endl << tab << "��� �����: " << _login << endl;
			cout << endl << tab << "��� ������: " << _password << endl;

			cout << tab << "____________________________________________________\n";

			cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
			pause();

			_logins.insert({ _login, _password });
			SaveLogin(&_login, &_password);
			break;
		}
	} while (true);
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
	cout << endl << tab << "������� ����� ������� ��� ������" << endl;
}

void UI::LoadMenuAnimation() const
{
	system("cls");

	const string load_simb = " - ";

	cout << n;
	cout << tab << "____________________________________________________\n";
	cout << endl << "\t\t\t\t\t\t    ��������..." << endl;
	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "\t  [";
	for (int i = 0; i < 10; i++)
	{
		cout << load_simb;
		Sleep(100);
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

		_logins.insert({ _login, _pass });
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