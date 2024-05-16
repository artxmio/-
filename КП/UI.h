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

	error() : message("success"), is(false)
	{}
};

class UI
{
public:
	void Hello() const;  //����� ��� ������� ���������
	void ByeBye() const; //����� ��� �������� ���������

	void StartMenu() const;
	void MainMenu(User* u);
	void OrderMenu(const User* u);

	User Autorization() const;
	void Registration();
	error Validation(string _login, string password);

	void SingInAdmin(User* u); //���� ��� �����
	void ExitAdmin(User* u);   //����� �� admin mode

	void RestaurantHistory() const; //����� � �������� ���������

	void LoadMenuAnimation() const; //�������� �������� (����� � ���������� "�������� �������� ����� ������")
	void AdminModeMessage() const; //��������� � ���, ��� ������ �� ���������� ��� ������� ������� ��������������

	void LoadLogins(); //�������� ������� � ������� �� ����� logins.txt
	void SaveLogin(const string* login, const string* pass); //���������� ������� � ������� � ���� logins.txt
private:
	map<string, string> _logins;

	const string tab = "\t\t\t\t";         //������ �� �����������
	const string n = "\n\n\n\n\n\n\n\n\n"; //������ �� ���������
};