#pragma once
#include <string>

using namespace std;

void testFunction();

double getBalance(double currentBalance);
int getCountOfCups(int emptyCups);
int setEmptyCups(int emptyCups);
int decreaseCupFromCoffeeMachine(int emptyCups);
double getMoney(double currentBalance, double allCash);

bool isCorrectInputMoney(double inputMoney);
double setMoney(double inputMoney);

double getPriceDifference(double currentBalance, double coffeePrice);


bool isPaid(double currentBalance, double coffeePrice);

bool isCorrectPassword(string inputPass, string pin);

int setBlockMachine();



string showDifference(double currentBalance, double price);
