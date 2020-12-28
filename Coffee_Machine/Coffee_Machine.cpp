// Coffee_Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>	
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

//print EspressoBinacci
void layuout(int type);    //logo || 
void balance(double byn);
void coffeeMenu();
void userButtons(const string str[], int size, bool isCash);
bool coffeeInput();
void makingCoffee(int coffee);
void serviceMenu();
void allBalanceService();
void allCupsService();
bool serviceInput();
void resetBalance();
void userMessange(string str, void retry(), int type);


void headLogoT(int type);
void block();
void addingCups();
bool isPressedButton(const int buttonRow);
bool isKeybordPressed(int oneKey, int twoKey);

void inputingMoney();
void inputingPin();

void printVerticalLine(int x, int y);
void printFrame(int x, int y, int columns, int rows);
string inputKeybordString(int xStart, int yStart, bool isPin, int size);
void ClearConsoleInputBuffer();
enum TypesHead { LOGO, WARNINGM, ERRORM, BALANCEM };
const string coffee[5] = { "Input Money", "Espresso", "Cappuccino",  "Latte", "Service" };
const string cash[5] = { "", "1", "1.50",  "1.50" ,"" };
const string serviceButtons[3] = { "Add cups", "Revenue getting", "Back to Main Menu" };

const int minButtonCol = 5;
const int maxButtonCol = 25;

const int firstButtonRow = 9;
const int twoButtonRow = 12;
const int threeButtonRow = 15;
const int fourButtonRow = 18;
const int fiveButtonRow = 21;

double balanceNow = 0;
double revenue = 0;
int inputPasswordTries = 2;
int emptyCups = 0;

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

	while (!Keyboard.getPressed(VK_RETURN)) {
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
				str += "3";
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



string showDifference(double currentBalance, double price);
void makePaymentAndPrepeareEmptyCups(double price);

int main()
{
	Cursor.setFontPixels(15, 20);
	Window.setSizeChars(30, 25);
	Window.hideResize();
	Window.hideBlinking();
	Window.hideScrollbars();
	Window.hideSelection();
	Window.setTitle(L"EspressoBiancci LEI700");
	emptyCups += setEmptyCups(7); ///initial rule
	layuout(LOGO);
	testFunction();
	coffeeMenu();

	return 0;
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
			cout << "BYN";
		}
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
	layuout(LOGO);

	Cursor.setColor(BLACK, BLACK);
	Cursor.setColor(GREEN);
	printFrame(4, 4, 21, 2);

	Cursor.setPosition(6, 5);
	Cursor.setColor(WHITE);
	cout << "Please input money: ";

	Cursor.setColor(BLACK, WHITE);
	for (int i = 6; i <= 24; i++)
	{
		Cursor.printBlank(i, 6);
	}
	Cursor.setPosition(6, 6);
	ClearConsoleInputBuffer();
	string input = inputKeybordString(6, 6, false, 10);
	balanceNow += setMoney(stod(input));
	revenue += balanceNow;

	Cursor.setColor(BLACK, BLACK);
	Keyboard.waitUser();
	coffeeMenu();
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
			serviceMenu();
		}
		else {
			inputPasswordTries--;
			userMessange("PIN is wrong! Left: " + to_string(inputPasswordTries + 1), inputingPin, WARNINGM);

		}
	}
	else {
		userMessange("Coffee machine has been blocked", block, ERRORM);
	}
}
bool isPressedButton(const int buttonRow) {
	bool borderMouse = Mouse.getColumns() >= minButtonCol && Mouse.getColumns() <= maxButtonCol;
	bool isButtonPress = (Keyboard.getPressed(VK_LBUTTON) && borderMouse
		&& (Mouse.getRows() == buttonRow || Mouse.getRows() == buttonRow + 1));
	return isButtonPress;
}

bool coffeeInput() {

	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);
	bool fourButtonPressed = isPressedButton(fourButtonRow);
	bool fiveButtonPressed = isPressedButton(fiveButtonRow);

	if (firstButtonPressed || isKeybordPressed(1, VK_NUMPAD1)) {
		cin.clear();
		fflush(stdin);
		userMessange("Pay attention that the coffee machine doesn't give change! ", inputingMoney, WARNINGM);
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2, VK_NUMPAD2)) {
		if (isPaid(balanceNow, stod(cash[1])))
		{
			//balanceNow -= stod(cash[1]);
			//emptyCups = decreaseCupFromCoffeeMachine(emptyCups);
			makePaymentAndPrepeareEmptyCups(stod(cash[1]));
			makingCoffee(2);

		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[2])), inputingMoney, WARNINGM);

		}
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3, VK_NUMPAD3)) {
		if (isPaid(balanceNow, stod(cash[2])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[2]));
			makingCoffee(3);
		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[3])), inputingMoney, WARNINGM);
		}
		return false;
	}
	if (fourButtonPressed || isKeybordPressed(4, VK_NUMPAD4)) {
		if (isPaid(balanceNow, stod(cash[3])))
		{
			makePaymentAndPrepeareEmptyCups(stod(cash[3]));
			makingCoffee(4);

		}
		else
		{
			userMessange(showDifference(balanceNow, stod(cash[3])), inputingMoney, WARNINGM);
		}
		return false;
	}

	if (fiveButtonPressed || isKeybordPressed(5, VK_NUMPAD5)) {

		inputingPin();
		return false;
	}

	return true;
}



void coffeeMenu() {
	if (emptyCups == 0) {
		userMessange("We are very sorry, but unfortunately there are no cups left", inputingPin, ERRORM);
	}
	layuout(LOGO);

	bool chosen = true;

	balance(balanceNow);
	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 15);
	userButtons(coffee, 4, true);
	Keyboard.wait(40);
	while (chosen)
	{
		chosen = coffeeInput();
		Keyboard.wait(30);
		cin.clear();
		fflush(stdin);
	}
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

bool isKeybordPressed(int oneKey, int twoKey) {
	return Keyboard.getReleased(oneKey) || Keyboard.getReleased(twoKey);
}
bool serviceInput() {
	bool firstButtonPressed = isPressedButton(firstButtonRow);
	bool twoButtonPressed = isPressedButton(twoButtonRow);
	bool threeButtonPressed = isPressedButton(threeButtonRow);

	if (firstButtonPressed || isKeybordPressed(1, VK_NUMPAD1)) {

		addingCups();
		return false;
	}

	if (twoButtonPressed || isKeybordPressed(2, VK_NUMPAD2)) {
		resetBalance();
		return false;
	}

	if (threeButtonPressed || isKeybordPressed(3, VK_NUMPAD3)) {
		coffeeMenu();
		return false;
	}

	return true;
}

void serviceMenu() {
	layuout(BALANCEM);

	bool chosen = true;

	allCupsService();
	Cursor.setColor(YELLOW);
	printFrame(3, 7, 23, 15);
	userButtons(serviceButtons, 2, false);
	Keyboard.wait(30);
	while (chosen)
	{
		chosen = serviceInput();
		Keyboard.wait(30);
		cin.clear();
		fflush(stdin);
	}
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
	serviceMenu();
}

void addingCups() {
	layuout(LOGO);
	emptyCups += setEmptyCups(7);
	Cursor.setColor(LIGHTYELLOW);
	Cursor.setPosition(6, 7);
	cout << "You have add 7 cups";
	Cursor.setColor(RED);
	Cursor.setPosition(4, 11);
	cout << "Press any key to return";
	Cursor.setPosition(8, 12);
	cout << "to Service Menu";
	Keyboard.waitUser();
	balanceNow = 0;
	revenue = 0;
	serviceMenu();
}
void layuout(int type) {
	Cursor.clearScreen();
	Cursor.setColor(YELLOW);
	printFrame(2, 0, 25, 23);
	headLogoT(type);
}

void headLogoT(int type) {
	Color colorFrame;
	Color colorText;
	string text;
	int x;
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

void userMessange(string str, void retry(), int type) {
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
	retry();
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
	cout << "Sorry!!"; ///////////
	while (!Keyboard.getPressed(VK_ESCAPE)) {
		Keyboard.waitUser();
		block();
	}
}

string showDifference(double currentBalance, double price) {
	string warningMessageString = "Please deposit ";
	string differrence = to_string(getPriceDifference(currentBalance, price));
	string resultString = "Please deposit " + differrence + " BYR";
	return resultString;
}

void makePaymentAndPrepeareEmptyCups(double price) {
	balanceNow -= price;
	emptyCups = decreaseCupFromCoffeeMachine(emptyCups);
}