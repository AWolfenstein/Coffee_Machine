#pragma once
#include <string>

using namespace std;

int setEmptyCups(int emptyCups);

int decreaseCupFromCoffeeMachine(int emptyCups);

double setMoney(double inputMoney);

double getPriceDifference(double currentBalance, double coffeePrice);

bool isPaid(double currentBalance, double coffeePrice);

bool isCorrectPassword(string inputPass, string pin);

string showDifference(double currentBalance, double price);

string getNonEmptyString(string str);

void makePaymentAndPrepeareEmptyCups(double price, int& emptyCups, int& pinTries, double& balanceNow, double& revenue);

string setPrecision(string str);