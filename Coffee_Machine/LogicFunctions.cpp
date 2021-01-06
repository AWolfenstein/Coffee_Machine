#include <iostream>
#include <string>
#include <iomanip> 
#include "swti/swti.hpp"

using namespace std;

int decreaseCupFromCoffeeMachine(int emptyCups) {
	emptyCups--;
	return emptyCups;
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
