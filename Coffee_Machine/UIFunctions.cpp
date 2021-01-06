#include <iostream>
#include <iomanip>	
#include "swti/swti.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <cctype>
#include <cstddef> 
#include <conio.h>
#include <math.h>
#include "ConstantsAndStrings.h"

using namespace std;

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

	Keyboard.wait(30);
	while (!Keyboard.getPressed(VK_RETURN)) {

		if (Keyboard.get(VK_BACK) && input != 0) {
			Cursor.printBlank(xStart + input - 1, yStart);
			input -= 1;
			str = str.substr(0, str.size() - 1);
		}
		if (input < size) {
			char key = _getch();
			int i = key - '0';
			if (i >= 0 && i <= 9) {
				isPin ? sym = '*' : sym = i + '0';
				Cursor.printChar(xStart + input, yStart, sym);
				input += 1;
				str += to_string(i);
			}
		}
		Keyboard.wait(30);
	}
	return str;
}

void ClearConsoleInputBuffer()
{
	PINPUT_RECORD ClearingVar1 = new INPUT_RECORD[256];
	DWORD ClearingVar2;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ClearingVar1, 256, &ClearingVar2);
	delete[] ClearingVar1;
}

void userButtons(const string str[], int size, bool isCash) {

	for (int i = 0; i <= size; i++) {
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

		cout << str[i];

		if (isCash && i != 0 && i != size) {
			Cursor.setColor(LIGHTMAGENTA);
			printVerticalLine(17, 8 + i * b);
			Cursor.setColor(LIGHTCYAN);
			Cursor.setPosition(18 + space, 9 + i * b);

			cout << cash[i];

			Cursor.setPosition(23, 9 + i * b);
			Cursor.setColor(LIGHTYELLOW);

			cout << balanceMessage[1];
		}
	}
}

bool isPressedButton(const int buttonRow) {
	bool borderMouse = Mouse.getColumns() >= minButtonCol && Mouse.getColumns() <= maxButtonCol;
	bool isButtonPress = (Keyboard.getPressed(VK_LBUTTON) && borderMouse
		&& (Mouse.getRows() == buttonRow || Mouse.getRows() == buttonRow + 1));
	return isButtonPress;
}

bool isKeybordPressed(int Key) {
	return (Keyboard.getReleased(Key + '0') || Keyboard.getReleased(numPadKeys[Key]));
}

