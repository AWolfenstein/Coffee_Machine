#pragma once
#include <string>

using namespace std;

void testFunction();

double getBalance(double currentBalance);
int getCountOfCups(int emptyCups);
int decreaseCupFromCoffeeMachine(int emptyCups);
double getMoney(double currentBalance, double allCash);

bool isCorrectInputMoney(double inputMoney);
double setMoney(double inputMoney);

void showMissingAmountError(double missingAmmount);
bool isPaid(double currentBalance, double coffeePrice);

bool isCorrectPassword(string inputPass);
int setBlockMachine();