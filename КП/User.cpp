#include "User.h"

using namespace std;

void pause();

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
	vector<order> list = restaurant->get_list();

	system("mode con cols=158 lines=50");


	system("cls");

	cout << "\n\n" << '\t' << "____________________________________________________________ [ ��� ������ ] _________________________________________________________________" << endl;
	cout << endl << '\t' << "|  �  | " << "      �����      | " << "                   ���������� ������                    | " << "      C��������       |" << "           ����������           | " << endl;

	COORD c;
	int y = 5;
	int x = 36;


	int yy = y;
	for (const auto& item : list)
	{
		if(_name == item.name_waiter)
		{
			cout << '\t' << "|" << setw(4) << item.order_num + 1 << " |" << setw(17) << item.order_time << " |" << endl;


			c.X = x;
			c.Y = yy;

			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleCursorPosition(h, c);

			string filling = item.filling;


			//����� �����������, ����� � ������ ������ ��������� �������
			for (int j = 0; j < filling.size(); j++)
				if (filling[j] == ',')
				{
					++c.Y;
					yy++;
					SetConsoleCursorPosition(h, c);
				}
				else cout << filling[j];

			COORD cc;
			cc.X = 94;
			cc.Y = yy - 1;

			SetConsoleCursorPosition(h, cc);
			cout << item.price;

			cc.X = 117;
			SetConsoleCursorPosition(h, cc);
			cout << (item.done ? "�����" : "�� �����");

			cc.X = 0;
			cc.Y = ++yy;

			SetConsoleCursorPosition(h, cc);
		}
	}
	cout << "\n\n" << '\t' << "_____________________________________________________________________________________________________________________________________________" << endl;

	cout << "\t ������� ����� �������, ����� �����...";
	pause();

	system("mode con cols=115 lines=30");
}
