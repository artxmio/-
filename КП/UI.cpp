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
	cout << tab << "������ ���������." << endl;
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

void UI::MainMenu(User* u)
{
	LoadMenuAnimation();

	if (u->is_admin())
		AdminModeMessage();

	cout << n;

	cout << tab << "_________________ [ ������� ���� ] _________________" << endl << endl;

	cout << tab << "\t\t1. ������" << endl;
	cout << tab << "\t\t2. ����" << endl;
	cout << tab << "\t\t3. ������� ���������" << endl;

	if (!u->is_admin())
		cout << tab << "\t\t4. ����� ��������������" << endl;
	else
		cout << tab << "\t\t4. ����� �� ������ ��������������" << endl;

	cout << tab << "\t\tesc. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

void UI::OrderMenu(const  User* u)
{
	LoadMenuAnimation();

	if (u->is_admin())
		AdminModeMessage();

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

void UI::RMenuMenu(const User* u)
{
	LoadMenuAnimation();

	if (u->is_admin())
		AdminModeMessage();

	cout << n;

	cout << tab << "________________ [ ���� ��������� ] ________________" << endl << endl;

	cout << tab << "\t\t1. ���� ���������" << endl;

	if (u->is_admin())
	{
		cout << tab << "\t\t2. �������� ����� ����" << endl;
		cout << tab << "\t\t3. ������� ����� ����" << endl;
	}

	cout << tab << "\t\tesc. �����" << endl;
	cout << endl << tab << "____________________________________________________\n";
}

User UI::Autorization() const
{
	system("cls");
	LoadMenuAnimation();

	//��� �������� ������� ������ � ������
	string _login;
	string _password;

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
	*/
	cout << tab << "____________________________________________________\n\n";

	//�������� ������ �� ������� � ���� ������ 
	if (_logins.count(_login) and _logins.at(_login) == _password)
	{
		cout << tab << "������ ��������";
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
		cout << "\n\n";
		string _login;
		cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;

		//���������� ����������
		cout << endl << tab << "������� �����������:" << endl;
		cout << endl << tab << " 1. �����(������) ������ ���� �� ����� 5(8) ��������";
		cout << endl << tab << " 2. ����� �� ������ ��������� ������� - ";
		cout << endl << tab << "	!@#$%^&*()-\"\'�;%:?<>/\\" << endl;
		cout << tab << "____________________________________________________\n";

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
			error e = Validation(_login, _password);
			if (e.is)
			{
				cout << endl << tab << e.message << endl;

				cout << tab << "____________________________________________________\n";
				cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
				pause();
				break;
			}


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

error UI::Validation(string _login, string _password)
{
	error e;

	//�������� ������ �� �����
	if (_login.size() < 5)
	{
		e.is = true;
		e.message = "����� ������ ������ ���� ������ ��� ����� 5 ��������";
		return e;
	}
	//�������� ������ �� ����������� �������
	for (const char item : _login)
	{
		size_t pos = e.invalid_symbols.find(item);
		if (pos != string::npos)
		{
			e.is = true;
			e.message = "����� �� ������ ��������� ����������� �������";
			return e;
		}
	}

	//�������� ������ �� �����
	if (_password.size() < 8)
	{
		e.is = true;
		e.message = "����� ������ ������ ���� ������ ��� ����� 8 ��������";
		return e;
	}

	return e;
}

void UI::SingInAdmin(User* u)
{
	system("cls");
	LoadMenuAnimation();

	//��� ��������������
	constexpr int ADMIN = 112233;

	//�������� ��� �� ������������
	bool _continue = true;
	do
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n";
		cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;

		cout << endl << tab << "\t����� �������� ����� ��������������,\n"
			<< tab << "\t���������� ������ ��� ��������������" << endl;
		cout << tab << "____________________________________________________\n";

		cout << endl << tab << "\t���: ";
		int _your_code = 0;
		cin >> _your_code;

		if (_your_code == ADMIN)
		{
			cout << endl << tab << "\t������ �� ������ �������������� ��������\n";
			u->set_admin(true);
			return;
		}
		else
		{
			cout << tab << "____________________________________________________\n";
			cout << endl << tab << "\t�������� ���\n";
		}

		//����� ����������� ��� ��� ������ ���
		cout << tab << "____________________________________________________\n";
		cout << tab << "\n\t����������� ���? (y/n)\n";

		do
		{
			const char __continue = _getch();
			if (__continue == 'n')
			{
				_continue = false;
				break;
			}
			else if (__continue == 'y')
				break;

		} while (true);
	} while (_continue);


	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
	pause();
	system("cls");
}

void UI::ExitAdmin(User* u)
{
	system("cls");
	cout << n;
	cout << endl << tab << "___________________ [ ����� ] __________________" << endl;

	cout << endl << tab << "\t����� ������� �����? (y/n)\n";

	bool _continue = true;
	do
	{
		const char __continue = _getch();
		if (__continue == 'n')
		{
			_continue = false;
			break;
		}
		else if (__continue == 'y') //���� ��, �� ������� ����� ������
		{
			_continue = false;

			u->set_admin(false);

			break;
		}

	} while (_continue);

	cout << tab << "____________________________________________________\n";
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
		Sleep(50);
	}
	cout << "]\n";
	cout << tab << "____________________________________________________\n";
	cout << endl << tab << "�������� ���������." << endl;
	Sleep(1000);
	system("cls");
}

void UI::AdminModeMessage() const
{
	cout << "[admin mode]";
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