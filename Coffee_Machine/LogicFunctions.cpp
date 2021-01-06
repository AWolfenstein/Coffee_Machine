#include <iostream>
#include <string>
#include <iomanip> 
#include "swti/swti.hpp"

using namespace std;

int decreaseCupFromCoffeeMachine(int emptyCups) {
	emptyCups--;
	return emptyCups;
}

string setPrecision(string str) {

	string newString = "     ";

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '.') {

			newString[i] = str[i];
			newString[i + 1] = str[i + 1];

			if (str[i + 2] == ' ') {

				newString[i + 2] = '0';

			}
			else {

				newString[i + 2] = str[i + 2];

			}

			return newString;
		}
		else {

			newString[i] = str[i];

		}
	}

	return newString;
}

double setMoney(double inputMoney) {
	return inputMoney;
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
	cout << setprecision(2);

	return coffeePrice - currentBalance;
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
	differrence = setPrecision(differrence);
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

void makePaymentAndPrepeareEmptyCups(double price, int& emptyCups, int& pinTries, double& balanceNow, double& revenue) {

	balanceNow -= price;
	emptyCups = decreaseCupFromCoffeeMachine(emptyCups);
}

