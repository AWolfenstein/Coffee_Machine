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
enum TypesMenu { COFFEE, SERVICE, COINS, SUBSERVICE };

const string coffee[6] = { "Deposit Money", "Espresso", "Cappuccino",  "Latte", "Service","Binacci" };
const string cash[5] = { "", "1", "1.50",  "1.50" ,"" };
const string warning[2] = { "Warning!","Error!" };
const string blockMachineMessage[3] = { "The machine" ," is blocked","Coffee machine has been blocked" };
const string bestCoffeeMessage[3] = { "Here is the best " ," in the city.", "Please help yourself!" };
const string choiceService[2] = { "Input PIN " ,"Back to Main Menu" };
const string readyCoffeeMessage[2] = { "Your " , " is ready." };
const string serviceButtons[3] = { "Add cups", "Revenue getting", "Back to Main Menu" };
const string buttonBack[2] = { "Back to Main Menu" ,"to Service Menu" };
const string coinsButtons[6] = { " 10 Coins", " 20 Coins", " 50 Coins"," 1 BYN"," 2 BYN"," Back" };
const string emptyCupsMessage = "We are very sorry butthere are no cup left";
const string continueMessage = "Press any key to continue";
const string getCupMessage[5] = { "Please get a cup!","How many cups","They are ","cups loaded.","are you adding? " };
const string pinMessage[2] = { "Please input PIN: ","PIN is wrong! Left: " };
const string depositMoneyMessage = "Please deposit coins.Pay attention that the coffee machine doesnot give change ";
const string balanceMessage[4] = { "Preeceds " ,"BYN", "were given away!","Balance " };
const string yourChoice = "Your choice: ";

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
