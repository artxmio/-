#include "User.h"

using namespace std;

void pause();

static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


void User::PrintVertucalLine(int x, int y)
{
	COORD c;
	c.X = x;
	y++;

	for (int i = y; i > 2; i--)
	{	
		c.Y = y--;

		SetConsoleCursorPosition(h, c);
		
		cout << "|";
	}
}

User::User()
{}


User::User(bool is_admin, string login, string pass, string name, bool u) : _is_admin(is_admin), _login(login), _password(pass), _name(name), user_alive(u)
{}

bool User::is_admin() const noexcept
{
	return _is_admin;
}

void User::set_admin(bool w)
{
	this->_is_admin = w;
}

bool User::alive()
{
	return user_alive;
}

void User::PrintInfo() const
{
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t" << "_________________ [ ������ ������� ] _________________" << endl;

	cout << endl << "\t\t\t\t\t\t" << " �����: " << _login << endl;
	cout << "\t\t\t\t\t\t" << "������: " << _password << endl;
	cout << "\t\t\t\t\t\t" << "   ���: " << _name << endl;
	cout << endl << "\t\t\t\t" << "____________________________________________________\n";

	cout << endl << "\t\t\t\t" << "������� ����� �������, ����� �����";
}

void User::ShowMyOrders(Restaurant* restaurant)
{
	vector<Restaurant::order> list = restaurant->get_list();

	system("mode con cols=158 lines=50");


	system("cls");

	cout << "\n\n" << '\t' << "____________________________________________________________ [ ��� ������ ] _________________________________________________________________" << endl;
	cout << endl << '\t' << "|  �  | " << "      �����      | " << "                   ���������� ������                    | " << "      C��������       |" << "           ����������           | " << endl << endl;

	COORD c;
	const int y = 6;
	const int x = 36;


	int yy = y;
	for (const auto& item : list)
		if(_name == item.name_waiter)
		{
			cout << '\t' << "|" << setw(3) << item.order_num + 1  << setw(14) << item.order_time << endl;

			c.X = x;
			c.Y = yy;

			SetConsoleCursorPosition(h, c);

			string filling = item.filling;
			COORD cc;

			//����� �����������, ����� � ������ ������ ��������� �������
			for (int j = 0; j < filling.size(); j++)
			{
				if (filling[j] == ',')
				{
					++c.Y;
					yy++;
					SetConsoleCursorPosition(h, c);
				}
				else 
					cout << filling[j];
			}

			cc.X = 91;
			cc.Y = yy - 1;

			SetConsoleCursorPosition(h, cc);
			cout << "          " <<  item.price;

			cc.X = 115;
			SetConsoleCursorPosition(h, cc);
			cout << "             " << (item.done ? "�����" : "�� �����");
			

			cc.X = 0;
			cc.Y = ++yy;

			SetConsoleCursorPosition(h, cc);
		}
	cout << "\n\n" << '\t' << "_____________________________________________________________________________________________________________________________________________" << endl;

	
	PrintVertucalLine(8, yy);
	PrintVertucalLine(14, yy);
	PrintVertucalLine(33, yy);
	PrintVertucalLine(91, yy);
	PrintVertucalLine(115, yy);
	PrintVertucalLine(148, yy);

	c.X = 10;
	c.Y = yy + 1;
	SetConsoleCursorPosition(h, c);
	cout << "������� ����� �������, ����� �����...";
	pause();

	system("mode con cols=115 lines=30");
}
