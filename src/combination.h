#ifndef __COMBINATION__
#define __COMBINATION_H__

#include <bits/stdc++.h>

using namespace std;

float evaluate(int op, float a, float b);
// evaluate a and b using operator op

string opToStr(int op);
// convert operator to string

void permutationCards(vector<int> &cards, vector<int> &combination, set<vector<int>> &usedPermute); 
// permutation of number input

void permutationOps(vector<vector<int>> &combinationOp);
// permutation of operators

#endif