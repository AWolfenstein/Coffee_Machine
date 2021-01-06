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
#include "LogicFunctions.h"
#include "UIFunctions.h"

void allBalanceService(double& revenue) {
	Cursor.setPosition(3, 2);
	Cursor.setColor(LIGHTYELLOW);
	cout << balanceMessage[3];
	Cursor.setPosition(15, 2);
	Cursor.setColor(LIGHTCYAN);
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << revenue;
	Cursor.setPosition(22, 2);
	Cursor.setColor(LIGHTYELLOW);
	cout << balanceMessage[1];
}

void headLogoT(int type, double& revenue) {
	Color colorFrame;
	Color colorText;
	string text;
	int x = 0;
	int y = 2;
	switch (type)
	{
	case LOGO: {
		colorFrame = WHITE;
		colorText = LIGHTYELLOW;
		text = coffee[1];
		x = 8;
		Cursor.setPosition(16, 2);
		Cursor.setColor(LIGHTGREEN);
		cout << coffee[5];
		break;
	}
	case WARNINGM: {
		colorFrame = YELLOW;
		colorText = LIGHTYELLOW;
		text = warning[0];
		x = 12;
		break;
	}
	case ERRORM: {
		colorFrame = RED;
		colorText = LIGHTRED;
		text = warning[1];
		x = 12;
		break;
	}
	case BALANCEM: {
		allBalanceService(revenue);
		break;
	}
	default:
		break;
	}
	if (type != BALANCEM) {
		Cursor.setColor(colorFrame);
		printFrame(4, 1, 21, 1);
		Cursor.setPosition(x, y);
		Cursor.setColor(colorText);
		cout << text;
	}
}
void layuout(int type, double& revenue) {
	Cursor.clearScreen();
	Cursor.setColor(YELLOW);
	printFrame(2, 0, 25, 26);
	headLogoT(type, revenue);
}

void userMessange(string str, int type, double& revenue) {
	layuout(type, revenue);

	Color color = type == ERRORM ? LIGHTRED : LIGHTYELLOW;
	Cursor.setColor(color);
	if (str.length() > 21) {
		int numOfLines = ceil(str.length() / 21);
		int pos = 0;
		for (int i = 0; i <= numOfLines; i++) {

			Cursor.setPosition(5, 7 + i);
			if (i != 0) {
				pos += 21;
			}
			else {
				pos = 0;
			}
			string newLine = str.substr(pos, 21);
			cout << newLine;
		}
	}
	else {
		Cursor.setPosition(5, 7);
		cout << str;
	}
	Cursor.setColor(LIGHTGREEN);
	Cursor.setPosition(3, 20);

	cout << continueMessage;
	Keyboard.waitUser();
}

void block(double& revenue) {
	layuout(LOGO, revenue);
	Cursor.setColor(RED);
	Cursor.setPosition(4, 7);
	cout << blockMachineMessage[0];
	cout << blockMachineMessage[1];

	while (!Keyboard.getPressed(VK_ESCAPE)) {
		Keyboard.waitUser();
		block(revenue);
	}
}



void allCupsService(int& emptyCups) {
	Cursor.setPosition(3, 4);
	Cursor.setColor(LIGHTYELLOW);
	cout << getCupMessage[2];
	Cursor.setPosition(12, 4);
	Cursor.setColor(LIGHTCYAN);
	cout << emptyCups;
	Cursor.setPosition(16, 4);
	Cursor.setColor(LIGHTYELLOW);
	cout << getCupMessage[3];
}

void balance(double& revenue) {
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 1);
	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << balanceMessage[3];
	Cursor.setPosition(15, 5);
	Cursor.setColor(LIGHTCYAN);
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << revenue << " ";
	Cursor.setPosition(22, 5);
	Cursor.setColor(LIGHTYELLOW);
	cout << balanceMessage[1];
}
