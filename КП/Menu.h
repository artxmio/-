#pragma once
#include <string>
#include <fstream>
using namespace std;

class Menu
{
protected:
	string functions; //��������� ��������� ���������� ����
	string path_in;
public:
	virtual void show(); //������� ����������
};