#pragma once
#include "User.h"
#include <map>;
using namespace std;

class error
{
	friend class UI;
private:
	const string invalid_symbols = "!@#$%^&*()-\"\'�;%:?<>/\\";
public:
	string message;
	bool is;

	error() noexcept : message("success"), is(false)
	{}
};

class UI
{
private:
	map<string, string> _logins;

	const string tab = "\t\t\t\t";         //������ �� �����������
	const string n = "\n\n\n\n\n\n\n\n\n"; //������ �� ���������
public:
	void Hello() const;  //����� ��� ������� ���������
	void ByeBye() const; //����� ��� �������� ���������

	void StartMenu() const; //��������� ���
	char MainMenu(User* u); //������� ����
	void OrderMenu(const User* u); //���� ��� ������ ������ "������ � ��������"
	void RMenuMenu(const User* u); //���� ��� ������ ������ "������ � ����"

	void About() const; //���������� � ���������

	User Autorization();
	void Registration();
	error Validation(string _login, string password);

	void SingInAdmin(User* u); //���� ��� �����
	void ExitAdmin(User* u);   //����� �� admin mode

	void RestaurantHistory() const; //����� � �������� ���������

	void LoadMenuAnimation() const; //�������� �������� (����� � ���������� "�������� �������� ����� ������")
	void AdminModeMessage() const; //��������� � ���, ��� ������ �� ���������� ��� ������� ������� ��������������

	void LoadLogins(); //�������� ������� � ������� �� ����� logins.txt
	void SaveLogin(const string* login, const string* pass); //���������� ������� � ������� � ���� logins.txt
};