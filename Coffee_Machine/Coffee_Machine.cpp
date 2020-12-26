// Coffee_Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "swti/swti.hpp"
#include "LogicFunctions.h"
using namespace std;

void headLogo();
void balance(double byn);
void coffeeMenu();
void coffeeButtons();
void layuout();
void makingCoffee(int coffee);

const string coffee[3] = { "Espresso", "Cappuccino",  "Latte" };
const string cash[3] = { "1", "1.50",  "1.50" };

const int minButtonCol = 5;
const int maxButtonCol = 25;

const int firstButtonRow = 9;
const int twoButtonRow = 12;
const int threeButtonRow = 15;

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
	Window.hideSelection();
	Window.setTitle(L"EspressoBiancci LEI700");


	layuout();
	testFunction();
	coffeeMenu();

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

void balance(double byn) {
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 1);
	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Balance: ";
	Cursor.setPosition(15, 5);
	Cursor.setColor(LIGHTCYAN);
	cout << byn;//BYN
	Cursor.setPosition(22, 5);
	Cursor.setColor(LIGHTYELLOW);
	cout << "BYN";
}

void coffeeButtons() {
	for (int i = 0; i <= 2; i++) {
		int b = 1;
		int space = 0;

		if (i != 0) {
			b = 3;
		}

		if (cash[i].length() <= 1) {
			space = 2;
		}
		else {
			space = 0;
		}

		Cursor.setColor(LIGHTMAGENTA);
		printFrame(4, 8 + i * b, 21, 1);
		printVerticalLine(6, 8 + i * b);
		printVerticalLine(17, 8 + i * b);
		Cursor.setColor(GRAY);
		Cursor.setPosition(5, 9 + i * b);
		cout << i + 1;
		Cursor.setColor(LIGHTYELLOW);
		Cursor.setPosition(7, 9 + i * b);
		cout << coffee[i];
		Cursor.setColor(LIGHTCYAN);
		Cursor.setPosition(18 + space, 9 + i * b);
		cout << cash[i];
		Cursor.setPosition(23, 9 + i * b);
		Cursor.setColor(LIGHTYELLOW);
		cout << "BYN";
	}
}

void makingCoffee(int coffeeChoice) {
	layuout();
	Cursor.setColor(RED);
	Cursor.setPosition(6, 5);
	cout << "Making " << coffee[coffeeChoice];
	Keyboard.waitUser();
}

bool coffeeInput() {
	bool borderMouse = Mouse.getColumns() >= minButtonCol && Mouse.getColumns() <= maxButtonCol;
	bool firstButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == firstButtonRow || Mouse.getRows() == firstButtonRow + 1);
	bool twoButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == twoButtonRow || Mouse.getRows() == twoButtonRow + 1);
	bool threeButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == threeButtonRow || Mouse.getRows() == threeButtonRow + 1);

	if (firstButtonPressed || Keyboard.getPressed('1')) {
		makingCoffee(1);
		return false;
	}

	if (twoButtonPressed || Keyboard.getPressed('2')) {
		makingCoffee(2);
		return false;
	}

	if (threeButtonPressed || Keyboard.getPressed('3')) {
		makingCoffee(3);
		return false;
	}
	return true;
}
void layuout() {
	Cursor.clearScreen();
	Cursor.setColor(YELLOW);
	printFrame(2, 0, 25, 23);
	headLogo();
}

void coffeeMenu() {
	bool chosen = true;
	balance(999.55);
	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 15);
	coffeeButtons();
	//	Cursor.setPosition(7, 20);
	//	cout << Mouse.getColumns() << "   " << Mouse.getRows() << "   ";
	//	Keyboard.waitUser();
	while (chosen)
	{
		chosen = coffeeInput();
		Keyboard.wait(30);
	}
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
