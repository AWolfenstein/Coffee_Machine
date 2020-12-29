#include <iostream>
#include <string>
#include "swti/swti.hpp"

using namespace std;

void testFunction() {
	Cursor.setPosition(7, 20);
	cout << "I Working";
};


double getBalance(double allCash) {
	return allCash;
}

int getCountOfCups(int emptyCups) {
	return emptyCups;
}

int decreaseCupFromCoffeeMachine(int emptyCups) {
	emptyCups--;
	return emptyCups;
}

double getMoney(double currentBalance, double allCash) {
	currentBalance = 0;
	return allCash;
}

void showMoneyLessInput() {
	cout << "The denomination of this bill is less than the allowed" << endl;
}

bool isCorrectInputMoney(double inputMoney) {
	if (inputMoney > 2 && 0.10 < inputMoney) {
		showMoneyLessInput();
		return false;
	}
	else {
		return true;
	}

}

double setMoney(double inputMoney) {
	if (isCorrectInputMoney(inputMoney) == true) {
		return inputMoney;
	}
}

bool isPaid(double currentBalance, double coffeePrice) {

	if (currentBalance >= coffeePrice) {
		return true;
	}
	else {
		return false;
	}

}

double getPriceDifference(double currentBalance, double coffeePrice) {
	return coffeePrice - currentBalance;
}

int setBlockMachine() {
	return 1;
}

double updateBalance(double inputMoney, double currentBalance) {
	currentBalance += inputMoney;
	return currentBalance;
}

bool isCorrectPassword(string inputPass, string pin) {
	return inputPass == pin;
}

int setEmptyCups(int emptyCups) {
	return emptyCups;
}


string showDifference(double currentBalance, double price) {
	string warningMessageString = "Please deposit ";
	string differrence = to_string(getPriceDifference(currentBalance, price));
	string resultString = "Please deposit " + differrence + " BYR";
	return resultString;
}
string getNonEmptyString(string str) {
	if (str == "") {
		return "0";
	}
	else {
		return str;
	}
}

//Test commit