// Coffee_Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include "swti/swti.hpp"
#include <windows.h>
#include <stdio.h>
#include "LogicFunctions.h"

using namespace std;

void headLogo();
void balance(double byn);
void coffeeMenu();
void coffeeButtons();
void layuout();
void makingCoffee(int coffee);


const string coffee[5] = { "Input Money", "Espresso", "Cappuccino",  "Latte", "Service" };
const string cash[5] = { "", "1", "1.50",  "1.50" ,"" };

const int minButtonCol = 5;
const int maxButtonCol = 25;

const int firstButtonRow = 9;
const int twoButtonRow = 12;
const int threeButtonRow = 15;
const int fourButtonRow = 18;
const int fiveButtonRow = 21;

int balanceNow = 0;

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
	for (int i = 0; i <= 4; i++) {
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

		Cursor.setColor(GRAY);
		Cursor.setPosition(5, 9 + i * b);
		cout << i + 1;
		Cursor.setColor(LIGHTYELLOW);
		Cursor.setPosition(7, 9 + i * b);
		cout << coffee[i];

		if (i != 0 && i != 4) {
			Cursor.setColor(LIGHTMAGENTA);
			printVerticalLine(17, 8 + i * b);
			Cursor.setColor(LIGHTCYAN);
			Cursor.setPosition(18 + space, 9 + i * b);
			cout << cash[i];
			Cursor.setPosition(23, 9 + i * b);
			Cursor.setColor(LIGHTYELLOW);
			cout << "BYN";
		}
	}
}

void makingCoffee(int coffeeChoice) {
	layuout();
	Cursor.setColor(RED);
	Cursor.setPosition(6, 5);
	cout << "Making " << coffee[coffeeChoice - 1];
	Keyboard.waitUser();
	coffeeMenu();
}
void ClearConsoleInputBuffer()
{
	PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
	DWORD ClearingVar2;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ClearingVar1, 256, &ClearingVar2);
	delete[] ClearingVar1;
}

void inputingMoney() {
	layuout();
	Cursor.setColor(BLACK, BLACK);
	int input = 0;
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 2);
	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Please input money: ";
	Window.showBlinking();
	Cursor.setColor(BLACK, WHITE);
	for (int i = 6; i <= 24; i++)
	{
		Cursor.printBlank(i, 6);
	}
	Cursor.setPosition(6, 6);
	ClearConsoleInputBuffer();
	cin.clear();
	fflush(stdin);

	cin >> input;
	balanceNow += input;

	Cursor.setColor(BLACK, BLACK);
	Window.hideBlinking();
	Keyboard.waitUser();
	coffeeMenu();
}


bool coffeeInput() {
	bool borderMouse = Mouse.getColumns() >= minButtonCol && Mouse.getColumns() <= maxButtonCol;
	bool firstButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == firstButtonRow || Mouse.getRows() == firstButtonRow + 1);
	bool twoButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == twoButtonRow || Mouse.getRows() == twoButtonRow + 1);
	bool threeButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == threeButtonRow || Mouse.getRows() == threeButtonRow + 1);
	bool fourButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == fourButtonRow || Mouse.getRows() == fourButtonRow + 1);
	bool fiveButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == fiveButtonRow || Mouse.getRows() == fiveButtonRow + 1);

	if (firstButtonPressed || Keyboard.getReleased('1')) {
		cin.clear();
		fflush(stdin);
		inputingMoney();
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
	if (fourButtonPressed || Keyboard.getPressed('4')) {
		makingCoffee(4);
		return false;
	}

	if (fiveButtonPressed || Keyboard.getPressed('5')) {
		makingCoffee(5);
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
	layuout();
	bool chosen = true;
	balance(balanceNow);
	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 15);
	coffeeButtons();
	Keyboard.wait(40);
	//	Cursor.setPosition(7, 20);
	//	cout << Mouse.getColumns() << "   " << Mouse.getRows() << "   ";
	//	Keyboard.waitUser();
	while (chosen)
	{
		chosen = coffeeInput();
		Keyboard.wait(30);
		cin.clear();
		fflush(stdin);
	}
}


