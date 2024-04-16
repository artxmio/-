#include "UI.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

void pause();

void UI::MainMenu()
{
	cout << "����� ���������� � �Trendy�������" << endl;
	cout << "\n��� ����������� ������� ����� �������...";
	pause();

	system("cls");
	LoadMenuAnimation();
	system("cls");

	cout << "������� ����" << endl;
	cout << "1. ���� �������" << endl;
	cout << "2. ������� ���������" << endl;
	cout << "0. �����" << endl;
}

void UI::OrderMenu()
{
	system("cls");
	LoadMenuAnimation();
	system("cls");

	cout << "���� �������" << endl;
	cout << "1. ���������� �������" << endl;
	cout << "2. �������� ����� (admin)" << endl;
	cout << "3. ������� ����� (admin)" << endl;
	cout << "0. ����� � ������� ����" << endl;
}

void UI::�uthenticationMenu()
{
}

void UI::RestaurantHistory()
{
	pause();
	system("cls");
	LoadMenuAnimation();
	system("cls");

	string line;

	ifstream in("source\\history.txt");
	if (in.is_open())
		while (getline(in, line))
		{
			cout << line << endl;
			Sleep(100);
		}
	in.close();
}

void UI::LoadMenuAnimation()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const string load_simb = " - ";

	cout << "��������..." << endl;
	cout << "\n[";
	for (int i = 0; i < 10; i++)
	{
		cout << load_simb;
		Sleep(500);
	}
	cout << "]";
	cout << "\n\n�������� ���������. ������� ����� ������� ��� �����������..." << endl;
	pause();
}
