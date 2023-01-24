#include <bits/stdc++.h>

using namespace std;

/**
 * @brief evaluate a and b using operator op
 * 
 * @param op 
 * @param a 
 * @param b 
 * @return float 
 */
float evaluate(int op, float a, float b){
    switch (op){
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    }
};
string opToStr(int op){
    switch (op){
    case 0:
        return "+";
    case 1:
        return "-";
    case 2:
        return "x";
    case 3:
        return "/";
    }
};
/**
 * @brief permutation of input number
 * 
 * @param cards 
 * @param combination 
 * @param usedPermute 
 */
void permutationCards(vector<int> &cards, vector<int> &combination, set<vector<int>> &usedPermute ){
    int i, j, k, l;
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 4;j++){
            for (int k = 0; k < 4;k++){
                for (int l = 0; l < 4;l++){
                    if(i!=j && i!= k && i!=l && j!=k && j!=l && k!=l){
                        combination.clear();
                        combination.push_back(cards[i]);
                        combination.push_back(cards[j]);
                        combination.push_back(cards[k]);
                        combination.push_back(cards[l]);
                        usedPermute.insert(combination);
                    }
                }
            }
        }
    }
};

/**
 * @brief permutation operators
 * 
 * @param combinationOp 
 */
void permutationOps(vector<vector<int>> &combinationOp){
    vector<int> temp(3);
    for (int i = 0; i < 4;i++){
        for (int j = 0; j < 4;j++){
            for (int k = 0; k < 4;k++){
                temp[0] = i;
                temp[1] = j;
                temp[2] = k;
                combinationOp.push_back(temp);
            }
        }
    }
}

vector<vector<int>> combinationList(vector<int> input){
    set<vector<int>> ans;
    vector<int> combination;
    permutationCards(input, combination, ans);
};

