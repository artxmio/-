#pragma once
#include "includes_file.h"
using namespace std;

class User;

class error
{
	friend class UI;
private:
	const string invalid_symbols = "!@#$%^&*()-\"\'�;%:?<>/\\";
public:
	string message;
	bool is;

	error() noexcept : message(""), is(false)
	{}
	error(string message) : message(message), is(true)
	{}
};

class UI
{
private:
	map<string, string> _logins;		   //�������� ������ � ������

	const string tab = "\t\t\t\t";         //������ �� �����������
	const string n = "\n\n\n\n\n\n\n\n\n"; //������ �� ���������

	//������� ����������� ��� ���������� ������� ��� ������ ����� ����
	char change_options(const string* opt, int size, string title, bool admin);
public:
	void Hello() const;				//����� ��� ������� ���������
	void ByeBye() const;			//����� ��� �������� ���������

	char StartMenu();				//��������� ���
	char MainMenu(User* u);			//������� ����
	char OrderMenu(const User* u);  //���� ��� ������ ������ "������ � ��������"
	char RMenuMenu(const User* u);  //���� ��� ������ ������ "������ � ����"

	void About() const;				//���������� � ���������

	User Autorization();								//�����������
	void Registration();								//�����������
	error Validation(string _login, string password);	//�������� ������ � ������

	void SingInAdmin(User* u);			//���� ��� �����
	void ExitAdmin(User* u);			//����� �� admin mode

	void RestaurantHistory() const;		//����� � �������� ���������

	void LoadMenuAnimation() const;		//�������� �������� (����� � ���������� "�������� �������� ����� ������")
	void AdminModeMessage() const;		//��������� � ���, ��� ������ �� ���������� ��� ������� ������� ��������������

	void LoadLogins();					//�������� ������� � ������� �� ����� logins.txt
	void SaveLogin(const string* login, const string* pass); //���������� ������� � ������� � ���� logins.txt
};