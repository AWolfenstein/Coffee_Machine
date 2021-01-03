#pragma once
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

#define WINDOW_COLUMS  30
#define WINDOW_ROWS  28
#define PIXEL_SIZE_X  15
#define PIXEL_SIZE_Y  20
#define WINDOW_TITLE L"EspressoBiancci LEI700"
#define START_CUPS 7
#define INPUT_PIN_TRIES 3
#define PASSWORD "1234"
using namespace std;

enum TypesHead { LOGO, WARNINGM, ERRORM, BALANCEM };
enum TypesMenu { COFFEE, SERVICE, COINS };

const string coffee[5] = { "Deposit Money", "Espresso", "Cappuccino",  "Latte", "Service" };
const string cash[5] = { "", "1", "1.50",  "1.50" ,"" };
const string serviceButtons[3] = { "Add cups", "Withdrawal of proceeds,", "Back to Main Menu" };
const string buttonBack[1] = { "Back to Main Menu" };
const string coinsButtons[6] = { " 10 Coins", " 20 Coins", " 50 Coins"," 1 BYN"," 2 BYN"," Back" };
const double coins[5] = { 0.10, 0.20, 0.50,1,2 };
const int numPadKeys[10] = { VK_NUMPAD0,VK_NUMPAD1,VK_NUMPAD2,VK_NUMPAD3,VK_NUMPAD4,VK_NUMPAD5,VK_NUMPAD6,VK_NUMPAD7,VK_NUMPAD8,VK_NUMPAD9 };
const int minButtonCol = 5;
const int maxButtonCol = 25;

const int firstButtonRow = 9;
const int twoButtonRow = 12;
const int threeButtonRow = 15;
const int fourButtonRow = 18;
const int fiveButtonRow = 21;
const int sixButtonRow = 24;
