#ifndef __MENU__
#define __MENU_H__

#include <bits/stdc++.h>

using namespace std;

void mainmenu();
// User choice cards' input manually or randomly

void result(int choice);
// if the choice is '1' then user manually input their cards, if '2' system will generate randomized cards

vector<int> userInput();
// user manually input their cards

vector<int> randomInput();
// auto generate random 4  cards

void ansToTxt(vector<int> cards, vector<string> solutions);
// save solutions to file .txt

#endif