// Coffee_Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "swti/swti.hpp"
using namespace std;
void headLogo();
void balance(int byn);
bool mainMenu();

void printVerticalLine(int x, int y) {

	Cursor.printChar(x, y + 1, DLINE_V);

};

void printFrame(int x, int y, int columns, int rows)
{
	// corners
	Cursor.printChar(x, y, DLINE_UR);
	Cursor.printChar(x, y + rows + 1, DLINE_DR);
	Cursor.printChar(x + columns + 1, y, DLINE_UL);
	Cursor.printChar(x + columns + 1, y + rows + 1, DLINE_DL);

	// horizontal bars
	for (int i = x + 1; i <= x + columns; i++)
	{
		Cursor.printChar(i, y, DLINE_H);
		Cursor.printChar(i, y + rows + 1, DLINE_H);
	}

	// vertical bars
	for (int i = y + 1; i <= y + rows; i++)
	{
		Cursor.printChar(x, i, DLINE_V);
		Cursor.printChar(x + columns + 1, i, DLINE_V);
	}
}

int main()
{
	Cursor.setFontPixels(15, 20);
	Window.setSizeChars(30, 25);
	Window.hideResize();
	Window.hideBlinking();
	Window.hideScrollbars();
	Window.setTitle(L"EspressoBiancci LEI700");

	Cursor.setColor(YELLOW);
	printFrame(2, 0, 25, 23);

	headLogo();
	while (mainMenu()) {}
	return 0;
}

void headLogo() {
	Cursor.setColor(WHITE);
	printFrame(4, 1, 21, 1);
	Cursor.setPosition(8, 2);
	Cursor.setColor(LIGHTYELLOW);
	cout << "Espresso";
	Cursor.setPosition(16, 2);
	Cursor.setColor(LIGHTGREEN);
	cout << "Biancci";
}

void balance(int byn) {
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 1);
	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Balance: ";
	Cursor.setPosition(18, 5);
	Cursor.setColor(LIGHTCYAN);
	cout << byn;//BYN
	Cursor.setPosition(22, 5);
	Cursor.setColor(LIGHTYELLOW);
	cout << "BYN";
}


bool mainMenu() {
	int rows = Window.getRows();
	balance(999);

	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 15);

	Cursor.setColor(WHITE);
	printFrame(4, 8, 21, 1);
	printVerticalLine(7, 8);
	printVerticalLine(17, 8);
	Keyboard.waitUser();
	return false;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
