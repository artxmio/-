#pragma once
#include <string>
using namespace std;

class User
{
private:
	bool _is_admin;   //�������� �� ������������� ���������������
	string _login;    //����� ������������
	string _password; //������ ������������
	bool user_alive;  
public: 
	User(); //����������� ��� ����������
	User(bool is_admin, string login, string pass, bool u = false); //����������� �� ����� ����������� ��� ���������� �����

	bool is_admin() const noexcept; //������� ��� ��������� �������� ���� is_admin
	void set_admin(bool w); //��������� ���� is_admin
	bool alive();
};