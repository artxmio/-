#pragma once

class UI
{
public:
	void MainMenu();
	void OrderMenu();
	void �uthenticationMenu();
	void RestaurantHistory();
private:
	bool isadmin; //true - ������������ �������� �������.

	void LoadMenuAnimation();
};

