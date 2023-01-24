#include <bits/stdc++.h>
#include "menu.h"
#include "combination.h"
#include "solver.h"
using namespace std;

int main(){
    std::string inp, choice;
    bool valid=false;
    //displaying ascii art
    string fileline;
    ifstream file("../src/ascii.txt");
    while(getline(file, fileline)){
        cout << fileline << endl;
    }
    file.close();
    printf("Welcome to 24 Solver!\n");
    mainmenu();
    return 0;
}