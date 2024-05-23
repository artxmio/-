#include "UI.h"

#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void pause();

//���������� cin
void _getstring(string* str, int max)
{
	while (true)
	{
		const char ch = _getch();
		if (ch == 27)
		{
			*str = "";
			return;
		}
		else if (ch == 8)
		{
			if (!str->empty())
			{
				cout << "\b \b"; // �������� ���������� ������� �� �������
				str->pop_back();
			}
		}
		else if (ch == 13) {// �������� �� Enter
			break;  // ���������� ����� ��� ������� ������� Enter
		}
		else {
			if (size(*str) < max)
			{
				*str += ch;  // ���������� ������� 
				cout << ch;  // ����� �������
			}
		}
	}
}

char UI::change_options(const string* opt, int size, string title, bool admin = false)
{
	int active = 0;
	for (;;)
	{
		if (admin)
			AdminModeMessage();
		cout << n;
		cout << tab << title << endl << endl;
		for (char i = 0; i < size; i++)
		{
			//������� ������� ����������
			if (i == active) cout << tab << "\t" << "->\t" << opt[i] << endl;
			else cout << tab << "\t\t" << opt[i] << endl;
		}
		cout << endl << tab << "____________________________________________________\n";

		char c = _getch();
		if (c == -32) c = _getch();
		switch (c)
		{
		case ESC:
			return 27;
		case UP:
			if (active > 0)
				--(active);
			break;
		case DOWN:
			if (active < size - 1)
				++(active);
			break;
		case ENTER:
			return (active == size - 1) ? 27 : active + 1;
			break;
		default: break;
		}
		system("cls");
	}
}

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

char UI::StartMenu()
{
	const string options[]
	{
		"- �����                -",
		"- ������������������   -",
		"- �����                -"
	};

	system("cls");

	for (;;)
		return change_options(options, size(options), "_______________ [ ����� ���������� ] _______________");
}

char UI::MainMenu(User* u)
{
	const string options[]
	{
		"- ������ � ��������    -",
		"- ������ � ����        -",
		"- ������� ���������    -",
		"- ����� �������������� -",
		"- � ���������          -",
		"- �����                -"
	};

	system("cls");

	return change_options(options, size(options), "_________________ [ ������� ���� ] _________________", u->is_admin());

}

char UI::OrderMenu(const  User* u)
{
	const string options[]
	{
		"- �������� ��� ������        -",
		"- �������� �����             -",
		"- ������� ��������� �����    -",
		"- �������� ���������� ������ -",
		"- �����                      -"
	};

	system("cls");

	return change_options(options, size(options), "____________________ [ ������ ] ____________________", u->is_admin());

}

char UI::RMenuMenu(const User* u)
{

	const string options[]
	{
		"- ���� ���������      -",
		"- �������� ����� ���� -",
		"- ������� ����� ����  -",
		"- �����               -"
	};

	system("cls");

	return change_options(options, size(options), "________________ [ ���� ��������� ] ________________", u->is_admin());

}

void UI::About() const
{
	LoadMenuAnimation();

	ifstream in("source\\about.txt");

	if (!in) return;

	string about;

	while (getline(in, about))
		cout << about << endl;
}

User UI::Autorization()
{
	system("cls");
	LoadMenuAnimation();

	//��� �������� ������� ������ � ������
	string _login;
	string _password;

start_aut:
	//��������� ������ �� ������������
	cout << "\n\n\n\n\n";
	cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;
	cout << endl << tab << "                     esc. �����" << endl;
	cout << tab << "____________________________________________________\n\n";


	cout << tab << "������� �����: ";
	_getstring(&_login, 16);

	if (_login.empty()) return User(false, "", "");

	cout << endl << tab << "������� ������: ";
	_getstring(&_password, 16);

	if (_password.empty()) return User(false, "", "");

	/*
		��� ������������ �� ������� �������� �������� ��������������
	*/
	cout << endl << tab << "____________________________________________________\n\n";

	//�������� ������ �� ������� � ���� ������ 
	if (_logins.count(_login) and _logins.at(_login) == _password)
	{
		cout << tab << "������ ��������";
		cout << endl << tab << "������� ����� ������� ��� �����������" << endl;
		pause();
		return User(false, _login, _password, true);
	}
	else //����������� ������
	{
		cout << tab << "�������� ����� ��� ������.";
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

		cout << endl << tab << "__________________ [ ����������� ] _________________" << endl;

		//���������� ����������
		cout << endl << tab << "������� �����������:" << endl;
		cout << endl << tab << " 1. �����: �� ����� 5 � �� ����� 16 ��������";
		cout << endl << tab << " 1. ������: �� ����� 8 � �� ����� 20 ��������";
		cout << endl << tab << " 2. ����� �� ������ ��������� ������� - ";
		cout << endl << tab << "	!@#$%^&*()-\"\'�;%:?<>/\\" << endl;
		cout << tab << " esc/enter(�������� ������ ������). �����" << endl;
		cout << tab << "____________________________________________________\n";

		//��������� ������ ������ � ������
		string _login;
		cout << endl << tab << "\t\t������� �����: ";
		_getstring(&_login, 16);

		if (_login.empty()) return;

		string _password;
		cout << endl << tab << "\t\t������� ������: ";
		_getstring(&_password, 16);

		if (_password.empty()) return;

		cout << endl << tab << "____________________________________________________\n";

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
	const string ADMIN = "112233";

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
		string _your_code = "";
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
		cout << endl << tab << "\t����������� ��� ? (y / n)\n";

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
	system("mode con cols=115 lines=50");

	string line;

	ifstream in("source\\history.txt");

	if (in.is_open())
		while (getline(in, line))
		{
			cout << line << endl;
			Sleep(100);
		}

	in.close();
	cout << endl << "\t\t\t������� ����� ������� ��� ������" << endl;
	pause();

	system("mode con cols=115 lines=30");
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

	if (!out) return;

	out << *login << ' ';
	out << *pass << '\n';

	out.close();
}