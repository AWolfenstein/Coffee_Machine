// Coffee_Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include "swti/swti.hpp"
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include <cstddef> 
#include <math.h>
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
	Cursor.printChar(x, y, DLINE_UR);
	Cursor.printChar(x, y + rows + 1, DLINE_DR);
	Cursor.printChar(x + columns + 1, y, DLINE_UL);
	Cursor.printChar(x + columns + 1, y + rows + 1, DLINE_DL);

	for (int i = x + 1; i <= x + columns; i++)
	{
		Cursor.printChar(i, y, DLINE_H);
		Cursor.printChar(i, y + rows + 1, DLINE_H);
	}

	for (int i = y + 1; i <= y + rows; i++)
	{
		Cursor.printChar(x, i, DLINE_V);
		Cursor.printChar(x + columns + 1, i, DLINE_V);
	}
}

string inputKeybordString(int xStart, int yStart, bool isPin, int size) {
	int input = 0;
	char sym;
	string str = "";
	while (!Keyboard.getReleased(VK_RETURN)) {
		if (input < size) {
			if (Keyboard.getReleased('0') || Keyboard.getReleased(VK_NUMPAD0)) {
				isPin ? sym = '*' : sym = '0';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "0";
			}
			if (Keyboard.getReleased('1') || Keyboard.getReleased(VK_NUMPAD1)) {
				isPin ? sym = '*' : sym = '1';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "1";
			}
			if (Keyboard.getReleased('2') || Keyboard.getReleased(VK_NUMPAD2)) {
				isPin ? sym = '*' : sym = '2';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "2";
			}
			if (Keyboard.getReleased('3') || Keyboard.getReleased(VK_NUMPAD3)) {
				isPin ? sym = '*' : sym = '3';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "1";
			}
			if (Keyboard.getReleased('4') || Keyboard.getReleased(VK_NUMPAD4)) {
				isPin ? sym = '*' : sym = '4';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "4";
			}
			if (Keyboard.getReleased('5') || Keyboard.getReleased(VK_NUMPAD5)) {
				isPin ? sym = '*' : sym = '5';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "5";
			}
			if (Keyboard.getReleased('6') || Keyboard.getReleased(VK_NUMPAD6)) {
				isPin ? sym = '*' : sym = '6';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "6";
			}
			if (Keyboard.getReleased('7') || Keyboard.getReleased(VK_NUMPAD7)) {
				isPin ? sym = '*' : sym = '7';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "7";
			}
			if (Keyboard.getReleased('8') || Keyboard.getReleased(VK_NUMPAD8)) {
				isPin ? sym = '*' : sym = '8';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "8";
			}
			if (Keyboard.getReleased('9') || Keyboard.getReleased(VK_NUMPAD9)) {
				isPin ? sym = '*' : sym = '9';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += "9";
			}

		}
		if (Keyboard.getReleased(VK_BACK) && input != 0) {
			Cursor.printBlank(xStart + input - 1, yStart);
			input -= 1;
			str = str.substr(0, str.size() - 1);
		}
		Keyboard.wait(30);
	}
	return str;
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
	int yLoader = 7;
	double status = 0;
	Cursor.setColor(RED);
	Cursor.setPosition(6, 5);
	cout << "Making " << coffee[coffeeChoice - 1];
	Cursor.printChar(3, yLoader, '[', WHITE);
	Cursor.printChar(27, yLoader, ']', WHITE);
	for (int i = 0; i <= 22; i++) {
		for (int b = 0; b <= 4; b++) {
			Cursor.setPosition(13, yLoader);
			status += 0.867;
			cout << ceil(status) << " %";
			Sleep(80);

		}
		Cursor.printChar(4 + i, yLoader, SQUARE_M, WHITE);
		Sleep(300);
	}
	layuout();
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(4, 7);
	cout << "Your " << coffee[coffeeChoice - 1] << " is ready.";
	Cursor.setColor(RED);
	Cursor.setPosition(7, 9);
	cout << "Please get a cup!";
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
	string input = inputKeybordString(6, 6, false, 10);

	balanceNow += stoi(input);


	Cursor.setColor(BLACK, BLACK);
	Window.hideBlinking();
	Keyboard.waitUser();
	coffeeMenu();
}



void inputingPin() {
	layuout();
	Cursor.setColor(BLACK, BLACK);
	const int xStart = 13;
	const int yStart = 7;

	Cursor.setColor(RED);
	printFrame(4, 4, 21, 3);

	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Please input PIN: ";
	Cursor.setColor(BLACK, WHITE);

	for (int i = xStart - 1; i <= 18; i++)
	{
		Cursor.printBlank(i, yStart);
	}

	ClearConsoleInputBuffer();
	Keyboard.wait(30);
	string pin = inputKeybordString(xStart, yStart, true, 4);

	Cursor.setColor(BLACK, BLACK);
	//pin -string  pin -> false
}


bool coffeeInput() {
	bool borderMouse = Mouse.getColumns() >= minButtonCol && Mouse.getColumns() <= maxButtonCol;
	bool firstButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == firstButtonRow || Mouse.getRows() == firstButtonRow + 1);
	bool twoButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == twoButtonRow || Mouse.getRows() == twoButtonRow + 1);
	bool threeButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == threeButtonRow || Mouse.getRows() == threeButtonRow + 1);
	bool fourButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == fourButtonRow || Mouse.getRows() == fourButtonRow + 1);
	bool fiveButtonPressed = Keyboard.getPressed(VK_LBUTTON) && borderMouse && (Mouse.getRows() == fiveButtonRow || Mouse.getRows() == fiveButtonRow + 1);

	if (firstButtonPressed || Keyboard.getReleased('1') || Keyboard.getReleased(VK_NUMPAD1)) {
		cin.clear();
		fflush(stdin);
		inputingMoney();
		return false;
	}

	if (twoButtonPressed || Keyboard.getPressed('2') || Keyboard.getReleased(VK_NUMPAD2)) {
		makingCoffee(2);
		return false;
	}

	if (threeButtonPressed || Keyboard.getPressed('3') || Keyboard.getReleased(VK_NUMPAD3)) {
		makingCoffee(3);
		return false;
	}
	if (fourButtonPressed || Keyboard.getPressed('4') || Keyboard.getReleased(VK_NUMPAD4)) {
		makingCoffee(4);
		return false;
	}

	if (fiveButtonPressed || Keyboard.getPressed('5') || Keyboard.getReleased(VK_NUMPAD5)) {
		inputingPin();
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


