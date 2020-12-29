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

#include "ConstantsAndStrings.h"
#include "LogicFunctions.h"
#include "UIFunctions.h"
#include "Components.h"

using namespace std;

double balanceNow = 0;
double revenue = 0;
int inputPasswordTries = 2;
int emptyCups = 0;

void layuout(int type);
void userButtonMenu(TypesMenu typeMenu);
void userMessange(string str, int type);
void headLogoT(int type);

void makingCoffee(int coffee);


bool coffeeInput();
bool coinsInput();
bool serviceInput();


void makePaymentAndPrepeareEmptyCups(double price);
void inputingCups();
void inputingPin();

void block();
void addingCups();
void addMoney(double coins);
void allBalanceService();
void allCupsService();
void balance(double byn);

void resetBalance();

int main()
{
	Cursor.setFontPixels(PIXEL_SIZE_X, PIXEL_SIZE_Y);
	Window.setSizeChars(WINDOW_COLUMS, WINDOW_ROWS);
	Window.hideResize();
	Window.hideBlinking();
	Window.hideScrollbars();
	Window.hideSelection();
	Window.setTitle(WINDOW_TITLE);
	emptyCups += setEmptyCups(START_CUPS); ///initial rule
	layuout(LOGO);
	testFunction();
	userButtonMenu(COFFEE);
	return 0;
}

void layuout(int type) {
	Cursor.clearScreen();
	Cursor.setColor(YELLOW);
	printFrame(2, 0, 25, 26);
	headLogoT(type);
}

void userButtonMenu(TypesMenu typeMenu) {
	bool isService = typeMenu == SERVICE;
	bool isCoffee = typeMenu == COFFEE;
	bool isCoins = typeMenu == COINS;

	if (isCoffee && emptyCups == 0) {
		userMessange("We are very sorry, but unfortunately there are no cups left", ERRORM);
		inputingPin();
	}

	layuout(isService ? BALANCEM : LOGO);
	bool chosen = true;
	bool input = true;
	isService ? allCupsService() : balance(balanceNow);

	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 18);

	if (isService) { userButtons(serviceButtons, 2, false); };
	if (isCoffee) { userButtons(coffee, 4, true); };
	if (isCoins) { userButtons(coinsButtons, 5, false); };

	Keyboard.wait(40);
	while (chosen)
	{
		if (isService) { chosen = serviceInput(); };
		if (isCoffee) { chosen = coffeeInput(); };
		if (isCoins) { chosen = coinsInput(); };
		Keyboard.wait(30);
		cin.clear();
		fflush(stdin);
	}
}

void headLogoT(int type) {
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
		text = "Espresso";
		x = 8;
		Cursor.setPosition(16, 2);
		Cursor.setColor(LIGHTGREEN);
		cout << "Biancci";
		break;
	}
	case WARNINGM: {
		colorFrame = YELLOW;
		colorText = LIGHTYELLOW;
		text = "Warning!";
		x = 12;
		break;
	}
	case ERRORM: {
		colorFrame = RED;
		colorText = LIGHTRED;
		text = "Error!";
		x = 12;
		break;
	}
	case BALANCEM: {
		allBalanceService();
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

void userMessange(string str, int type) {
	layuout(type);

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
	cout << "Press any key to continue";
	Keyboard.waitUser();
}

void block() {
	layuout(LOGO);
	Cursor.setColor(RED);
	Cursor.setPosition(7, 7);
	cout << "Coffee machine has ";
	Cursor.setPosition(9, 8);
	cout << " been blocked";
	Cursor.setPosition(12, 10);
	Cursor.setColor(LIGHTCYAN);
	cout << "Sorry!!";
	while (!Keyboard.getPressed(VK_ESCAPE)) {
		Keyboard.waitUser();
		block();
	}
}


void makingCoffee(int coffeeChoice) {
	layuout(LOGO);

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
			Sleep(40);

		}
		Cursor.printChar(4 + i, yLoader, SQUARE_M, WHITE);
		Sleep(150);
	}

	layuout(LOGO);
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(4, 7);
	cout << "Your " << coffee[coffeeChoice - 1] << " is ready.";

	Cursor.setColor(RED);
	Cursor.setPosition(7, 9);
	cout << "Please get a cup!";
	Keyboard.waitUser();

	userButtonMenu(COFFEE);
}



void inputingCups() {
	layuout(LOGO);

	Cursor.setColor(BLACK, BLACK);
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 2);

	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Add empty cups: ";

	Cursor.setColor(BLACK, WHITE);
	for (int i = 6; i <= 24; i++)
	{
		Cursor.printBlank(i, 6);
	}
	Cursor.setPosition(6, 6);
	ClearConsoleInputBuffer();
	string input = inputKeybordString(6, 6, false, 10);
	emptyCups += setEmptyCups(stoi(getNonEmptyString(input)));
	Cursor.setColor(BLACK, BLACK);
	Keyboard.waitUser();
	userButtonMenu(SERVICE);
}

void inputingPin() {
	layuout(LOGO);
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
	Keyboard.wait(70);
	string pin = inputKeybordString(xStart, yStart, true, 4);

	Cursor.setColor(BLACK, BLACK);
	if (inputPasswordTries != 0) {
		if (isCorrectPassword(pin, "1111")) {
			userButtonMenu(SERVICE);
		}
		else {
			inputPasswordTries--;
			userMessange("PIN is wrong! Left: " + to_string(inputPasswordTries + 1), WARNINGM);
			inputingPin();
		}
	}
	else {
		userMessange("Coffee machine has been blocked", ERRORM);
		block();
	}
}

bool coinsInput() {

	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);
	bool fourButtonPressed = isPressedButton(fourButtonRow);
	bool fiveButtonPressed = isPressedButton(fiveButtonRow);
	bool sixButtonPressed = isPressedButton(sixButtonRow);

	if (firstButtonPressed || isKeybordPressed(1)) {
		addMoney(coins[0]);
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2)) {
		addMoney(coins[1]);
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3)) {
		addMoney(coins[2]);
		return false;
	}
	if (fourButtonPressed || isKeybordPressed(4)) {
		addMoney(coins[3]);
		return false;
	}

	if (fiveButtonPressed || isKeybordPressed(5)) {
		addMoney(coins[4]);
		return false;
	}

	if (sixButtonPressed || isKeybordPressed(6)) {
		userButtonMenu(COFFEE);
		return false;
	}

	return true;
}

bool coffeeInput() {

	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);
	bool fourButtonPressed = isPressedButton(fourButtonRow);
	bool fiveButtonPressed = isPressedButton(fiveButtonRow);

	if (firstButtonPressed || isKeybordPressed(1)) {
		cin.clear();
		fflush(stdin);
		userMessange("Pay attention that the coffee machine doesn't give change! ", WARNINGM);
		userButtonMenu(COINS);
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2)) {
		if (isPaid(balanceNow, stod(cash[1])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[1]));
			makingCoffee(2);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[2])), WARNINGM);
			userButtonMenu(COINS);
		}
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3)) {
		if (isPaid(balanceNow, stod(cash[2])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[2]));
			makingCoffee(3);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[3])), WARNINGM);
			userButtonMenu(COINS);
		}
		return false;
	}
	if (fourButtonPressed || isKeybordPressed(4)) {
		if (isPaid(balanceNow, stod(cash[3])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[3]));
			makingCoffee(4);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[3])), WARNINGM);
			userButtonMenu(COINS);
		}
		return false;
	}

	if (fiveButtonPressed || isKeybordPressed(5)) {
		inputingPin();
		return false;
	}

	return true;
}

bool serviceInput() {
	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);

	if (firstButtonPressed || isKeybordPressed(1)) {
		addingCups();
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2)) {
		resetBalance();
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3)) {
		userButtonMenu(COFFEE);
		return false;
	}

	return true;
}

void addingCups() {
	layuout(LOGO);
	inputingCups();
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(6, 7);
	cout << emptyCups;
	Cursor.setColor(RED);
	Cursor.setPosition(4, 11);
	cout << "Press any key to return";
	Cursor.setPosition(8, 12);
	cout << "to Service Menu";
	Keyboard.waitUser();
	userButtonMenu(SERVICE);
}

void balance(double byn) {
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 1);
	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Balance: ";
	Cursor.setPosition(15, 5);
	Cursor.setColor(LIGHTCYAN);
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << byn;//BYN
	Cursor.setPosition(22, 5);
	Cursor.setColor(LIGHTYELLOW);
	cout << "BYN";
}

void resetBalance() {
	layuout(LOGO);
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(7, 7);
	cout << "Your revenue was ";
	Cursor.setPosition(7, 9);
	Cursor.setColor(LIGHTCYAN);
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << revenue; ///////////
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(16, 9);
	cout << "BYN";
	Cursor.setColor(RED);
	Cursor.setPosition(4, 11);
	cout << "Press any key to return";
	Cursor.setPosition(8, 12);
	cout << "to Service Menu";
	Keyboard.waitUser();
	balanceNow = 0;
	revenue = 0;
	userButtonMenu(SERVICE);
}

void allBalanceService() {
	Cursor.setPosition(3, 2);
	Cursor.setColor(LIGHTYELLOW);
	cout << "Balance is ";
	Cursor.setPosition(15, 2);
	Cursor.setColor(LIGHTCYAN);
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << revenue;
	Cursor.setPosition(22, 2);
	Cursor.setColor(LIGHTYELLOW);
	cout << "BYN.";
}

void allCupsService() {
	Cursor.setPosition(3, 4);
	Cursor.setColor(LIGHTYELLOW);
	cout << "They are ";
	Cursor.setPosition(12, 4);
	Cursor.setColor(LIGHTCYAN);
	cout << emptyCups;//<-max 3 digit
	Cursor.setPosition(16, 4);
	Cursor.setColor(LIGHTYELLOW);
	cout << "cups loaded.";
}

void addMoney(double coins) {
	balanceNow += setMoney(coins);
	revenue += balanceNow;
	userButtonMenu(COINS);
}

void makePaymentAndPrepeareEmptyCups(double price) {
	balanceNow -= price;
	emptyCups = decreaseCupFromCoffeeMachine(emptyCups);
}
