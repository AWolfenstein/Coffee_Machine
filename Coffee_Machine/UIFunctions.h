#pragma once
#include "ConstantsAndStrings.h"
void printVerticalLine(int x, int y);
void printFrame(int x, int y, int columns, int rows);

string inputKeybordString(int xStart, int yStart, bool isPin, int size);
void ClearConsoleInputBuffer();


void userButtons(const string str[], int size, bool isCash);
void userButtonMenu(TypesMenu typeMenu);


bool isPressedButton(const int buttonRow);
bool isKeybordPressed(int Key);
