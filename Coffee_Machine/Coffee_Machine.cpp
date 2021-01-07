// Coffee_Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
#include <thread>

#include "ConstantsAndStrings.h"
#include "LogicFunctions.h"
#include "UIFunctions.h"
#include "Components.h"

using namespace std;

void userButtonMenu(TypesMenu typeMenu, int& emptyCups, int& pinTries, double& balanceNow, double& revenue);
void makingCoffee(int coffee, int& emptyCups, int& pinTries, double& balanceNow, double& revenue);

bool coffeeInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);
bool coinsInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);
bool serviceInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);
bool subServiceInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);

void inputingCups(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);
void inputingPin(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);

void addingCups(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);
void addMoney(double coins, int& emptyCups, int& pinTries, double& balanceNow, double& revenue);

void resetBalance(int& emptyCups, int& pinTries, double& balanceNow, double& revenue);

int main()
{
	Cursor.setFontPixels(PIXEL_SIZE_X, PIXEL_SIZE_Y);
	Window.setSizeChars(WINDOW_COLUMS, WINDOW_ROWS);
	Window.hideResize();
	Window.hideBlinking();
	Window.hideScrollbars();
	Window.hideSelection();
	Window.setTitle(WINDOW_TITLE);

	int emptyCups = START_CUPS;
	int inputPasswordTries = INPUT_PIN_TRIES;
	double balanceNow = 0;
	double revenue = 0;

	layuout(LOGO, revenue);
	userButtonMenu(COFFEE, emptyCups, inputPasswordTries, balanceNow, revenue);
	return 0;
}

void userButtonMenu(TypesMenu typeMenu, int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	bool isService = typeMenu == SERVICE;
	bool isCoffee = typeMenu == COFFEE;
	bool isCoins = typeMenu == COINS;
	bool isSub = typeMenu == SUBSERVICE;
	bool chosen = true;

	if (isCoffee && emptyCups == 0) {
		userMessange(emptyCupsMessage, ERRORM, revenue);
		userButtonMenu(SUBSERVICE, emptyCups, pinTries, balanceNow, revenue);
	}

	layuout(isService ? BALANCEM : LOGO, revenue);

	if (isSub) {
		Cursor.setPosition(6, 5);
		Cursor.setColor(WHITE);
		cout << yourChoice;
	}
	else {
		isService ? allCupsService(emptyCups) : balance(balanceNow);
	}

	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 18);

	if (isService) { userButtons(serviceButtons, 2, false); };
	if (isCoffee) { userButtons(coffee, 4, true); };
	if (isCoins) { userButtons(coinsButtons, 5, false); };
	if (isSub) { userButtons(choiceService, 1, false); };

	Keyboard.wait(40);
	while (chosen)
	{
		if (isService) { chosen = serviceInput(emptyCups, pinTries, balanceNow, revenue); };
		if (isCoffee) { chosen = coffeeInput(emptyCups, pinTries, balanceNow, revenue); };
		if (isCoins) { chosen = coinsInput(emptyCups, pinTries, balanceNow, revenue); };
		if (isSub) { chosen = subServiceInput(emptyCups, pinTries, balanceNow, revenue); }
		Keyboard.wait(30);
		cin.clear();
		fflush(stdin);
	}
}

void makingCoffee(int coffeeChoice, int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	layuout(LOGO, revenue);

	int yLoader = 11;
	double status = 0;

	Cursor.setColor(RED);
	Cursor.setPosition(4, 5);
	cout << bestCoffeeMessage[0];
	Cursor.setPosition(4, 6);
	cout << coffee[coffeeChoice - 1] << bestCoffeeMessage[1];
	Cursor.setPosition(4, 7);
	cout << bestCoffeeMessage[2];
	Cursor.printChar(3, yLoader, '[', WHITE);
	Cursor.printChar(27, yLoader, ']', WHITE);

	for (int i = 0; i <= 22; i++) {
		for (int b = 0; b <= 4; b++) {
			Cursor.setPosition(13, yLoader);
			status += 0.867;
			cout << ceil(status) << " %";
			Sleep(40);

		}
		Cursor.printChar(4 + i, yLoader, SQUARE_M, WHITE);
		Sleep(150);
	}

	layuout(LOGO, revenue);
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(3, 7);
	cout << readyCoffeeMessage[0] << coffee[coffeeChoice - 1] << readyCoffeeMessage[1];

	Cursor.setColor(RED);
	Cursor.setPosition(7, 9);
	cout << getCupMessage[0];
	Keyboard.waitUser();

	userButtonMenu(COFFEE, emptyCups, pinTries, balanceNow, revenue);
}

void inputingCups(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	layuout(LOGO, revenue);

	Cursor.setColor(BLACK, BLACK);
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 5);

	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << getCupMessage[1];
	Cursor.setPosition(6, 6);
	cout << getCupMessage[4];

	Cursor.setColor(BLACK, WHITE);
	for (int i = 6; i <= 24; i++)
	{
		Cursor.printBlank(i, 8);
	}

	Cursor.setPosition(6, 8);
	ClearConsoleInputBuffer();
	string input = inputKeybordString(6, 8, false, 10);
	emptyCups += setEmptyCups(stoi(input));
	Cursor.setColor(BLACK, BLACK);
	//Keyboard.waitUser();
	userButtonMenu(SERVICE, emptyCups, pinTries, balanceNow, revenue);
}

void inputingPin(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	if (pinTries == 0) {
		userMessange(blockMachineMessage[2], ERRORM, revenue);
		block(revenue);
	}
	layuout(LOGO, revenue);
	Cursor.setColor(BLACK, BLACK);
	const int xStart = 13;
	const int yStart = 7;

	Cursor.setColor(RED);
	printFrame(4, 4, 21, 3);
	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << pinMessage[0];
	Cursor.setColor(BLACK, WHITE);

	for (int i = xStart - 1; i <= 18; i++)
	{
		Cursor.printBlank(i, yStart);
	}

	ClearConsoleInputBuffer();
	string pin = inputKeybordString(xStart, yStart, true, 4);
	Cursor.setColor(BLACK, BLACK);

	if (pinTries != 0) {
		if (isCorrectPassword(pin, PASSWORD)) {
			pinTries = INPUT_PIN_TRIES;
			userButtonMenu(SERVICE, emptyCups, pinTries, balanceNow, revenue);
		}
		else {
			pinTries--;
			userMessange(pinMessage[1] + to_string(pinTries), WARNINGM, revenue);
			ClearConsoleInputBuffer();
			Keyboard.wait(70);
			inputingPin(emptyCups, pinTries, balanceNow, revenue);
		}
	}
}

bool coinsInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {

	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);
	bool fourButtonPressed = isPressedButton(fourButtonRow);
	bool fiveButtonPressed = isPressedButton(fiveButtonRow);
	bool sixButtonPressed = isPressedButton(sixButtonRow);

	if (firstButtonPressed || isKeybordPressed(1)) {
		addMoney(coins[0], emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2)) {
		addMoney(coins[1], emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3)) {
		addMoney(coins[2], emptyCups, pinTries, balanceNow, revenue);
		return false;
	}
	if (fourButtonPressed || isKeybordPressed(4)) {
		addMoney(coins[3], emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (fiveButtonPressed || isKeybordPressed(5)) {
		addMoney(coins[4], emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (sixButtonPressed || isKeybordPressed(6)) {
		userButtonMenu(COFFEE, emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	return true;
}

bool coffeeInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {

	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);
	bool fourButtonPressed = isPressedButton(fourButtonRow);
	bool fiveButtonPressed = isPressedButton(fiveButtonRow);

	if (firstButtonPressed || isKeybordPressed(1)) {
		cin.clear();
		fflush(stdin);
		userMessange(depositMoneyMessage, WARNINGM, revenue);
		userButtonMenu(COINS, emptyCups, pinTries, balanceNow, revenue);
		return false;
	}
	cout << setprecision(2);
	if (twoButtonPressed || isKeybordPressed(2)) {
		if (isPaid(balanceNow, stod(cash[1])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[1]), emptyCups, pinTries, balanceNow, revenue);
			makingCoffee(2, emptyCups, pinTries, balanceNow, revenue);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[1])), WARNINGM, revenue);
			userMessange(depositMoneyMessage, WARNINGM, revenue);
			userButtonMenu(COINS, emptyCups, pinTries, balanceNow, revenue);
		}
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3)) {
		if (isPaid(balanceNow, stod(cash[2])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[2]), emptyCups, pinTries, balanceNow, revenue);
			makingCoffee(3, emptyCups, pinTries, balanceNow, revenue);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[2])), WARNINGM, revenue);
			userMessange(depositMoneyMessage, WARNINGM, revenue);
			userButtonMenu(COINS, emptyCups, pinTries, balanceNow, revenue);
		}
		return false;
	}
	if (fourButtonPressed || isKeybordPressed(4)) {
		if (isPaid(balanceNow, stod(cash[3])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[3]), emptyCups, pinTries, balanceNow, revenue);
			makingCoffee(4, emptyCups, pinTries, balanceNow, revenue);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[3])), WARNINGM, revenue);
			userMessange(depositMoneyMessage, WARNINGM, revenue);
			userButtonMenu(COINS, emptyCups, pinTries, balanceNow, revenue);
		}
		return false;
	}

	if (fiveButtonPressed || isKeybordPressed(5)) {
		userButtonMenu(SUBSERVICE, emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	return true;
}

bool serviceInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);
	pinTries = INPUT_PIN_TRIES;
	if (firstButtonPressed || isKeybordPressed(1)) {
		addingCups(emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2)) {
		resetBalance(emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3)) {
		userButtonMenu(COFFEE, emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	return true;
}

bool subServiceInput(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);

	if (firstButtonPressed || isKeybordPressed(1)) {
		inputingPin(emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2)) {
		userButtonMenu(COFFEE, emptyCups, pinTries, balanceNow, revenue);
		return false;
	}

	return true;
}

void addingCups(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	layuout(LOGO, revenue);
	inputingCups(emptyCups, pinTries, balanceNow, revenue);
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(6, 7);
	cout << emptyCups;
	Cursor.setColor(RED);
	Cursor.setPosition(4, 11);
	cout << continueMessage;
	Cursor.setPosition(8, 12);
	cout << buttonBack[1];
	Keyboard.waitUser();
	userButtonMenu(SERVICE, emptyCups, pinTries, balanceNow, revenue);
}


void resetBalance(int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	layuout(LOGO, revenue);
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(7, 7);
	cout << balanceMessage[3];
	cout << setprecision(2);
	cout << revenue << " " << balanceMessage[1];
	Cursor.setPosition(7, 9);
	Cursor.setColor(LIGHTCYAN);
	cout << fixed << showpoint;
	cout << balanceMessage[2];
	Keyboard.waitUser();

	balanceNow = 0;
	revenue = 0;

	userButtonMenu(SERVICE, emptyCups, pinTries, balanceNow, revenue);
}


void addMoney(double coins, int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {
	balanceNow += setMoney(coins);
	revenue += setMoney(coins);
	userButtonMenu(COFFEE, emptyCups, pinTries, balanceNow, revenue);
}