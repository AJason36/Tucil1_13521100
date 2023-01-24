#include <bits/stdc++.h>
#include "menu.h"
#include "combination.h"
using namespace std;

vector<string> finalSolver(vector<int> cards){
    vector<int> combinationCards;
    vector<vector<int>> combinationOps;
    set<vector<int>> cardsPermute;
    vector<string> ans;
    permutationOps(combinationOps);
    permutationCards(cards, combinationCards, cardsPermute);
    /* parantheses combinations
    (a op b) op (c op d)
    ((a op b) op c) op d
    (a op (b op c)) op d
    a op ((b op c) op d)
    a op (b op (c op d))
    */
    float res=0;
    // all parantheses combinations
    for (int i = 0; i < combinationOps.size();i++){
        for (auto ptr = cardsPermute.begin(); ptr != cardsPermute.end();ptr++)
        {
            auto tmpCards = *ptr;
            //(a op b) op (c op d)
            res = evaluate((int)combinationOps[i][1], evaluate(combinationOps[i][0], tmpCards[0], tmpCards[1]), evaluate(combinationOps[i][2], tmpCards[2], tmpCards[3]));
            if (res == 24.0){
                string tempAns="", space=" ";
                tempAns = "( ";
                tempAns +=to_string(tmpCards[0])+space+opToStr(combinationOps[i][0])+space+to_string(tmpCards[1]);
                tempAns += " ) ";
                tempAns += opToStr(combinationOps[i][1]);
                tempAns += " ( ";
                tempAns +=to_string(tmpCards[2])+space+opToStr(combinationOps[i][2])+space+to_string(tmpCards[3]);
                tempAns += " )";
                ans.push_back(tempAns);
            }

            // ((a op b) op c) op d
            res = evaluate((int)combinationOps[i][2], evaluate(combinationOps[i][1], evaluate(combinationOps[i][0], tmpCards[0],tmpCards[1]), tmpCards[2]), tmpCards[3]);
            if (res == 24.0){
                string tempAns="", space=" ";
                tempAns = "(( ";
                tempAns +=to_string(tmpCards[0])+space+opToStr(combinationOps[i][0])+space+to_string(tmpCards[1]);
                tempAns += " ) ";
                tempAns += opToStr(combinationOps[i][1])+ space+to_string(tmpCards[2]);
                tempAns += " ) ";
                tempAns += opToStr(combinationOps[i][2])+space+to_string(tmpCards[3]);
                ans.push_back(tempAns);
            }
            //  (a op (b op c)) op d
            res = evaluate((int)combinationOps[i][2], evaluate(combinationOps[i][0], tmpCards[0], evaluate(combinationOps[i][1], tmpCards[1],tmpCards[2])), tmpCards[3]);
            if (res == 24.0){
                string tempAns="", space=" ";
                tempAns = "( ";
                tempAns += to_string(tmpCards[0]) + space + opToStr(combinationOps[i][0]);
                tempAns += " ( ";
                tempAns+= to_string(tmpCards[1])+space+opToStr(combinationOps[i][1])+ space+to_string(tmpCards[2]);
                tempAns += " )) ";
                tempAns += opToStr(combinationOps[i][2])+space+to_string(tmpCards[3]);
                ans.push_back(tempAns);
            }
            // a op ((b op c) op d)
            res = evaluate((int)combinationOps[i][0], tmpCards[0],evaluate(combinationOps[i][2], evaluate(combinationOps[i][1], tmpCards[1],tmpCards[2]),tmpCards[3]));
            if (res == 24.0){
                string tempAns="", space=" ";
                tempAns += to_string(tmpCards[0]) + space + opToStr(combinationOps[i][0]);
                tempAns += " (( ";
                tempAns+= to_string(tmpCards[1])+space+opToStr(combinationOps[i][1])+ space+to_string(tmpCards[2]);
                tempAns += " ) ";
                tempAns += opToStr(combinationOps[i][2])+space+to_string(tmpCards[3]);
                tempAns += " )";
                ans.push_back(tempAns);
            }
            // a op (b op (c op d))
            res = evaluate((int)combinationOps[i][0], tmpCards[0],evaluate(combinationOps[i][1], tmpCards[1],evaluate(combinationOps[i][2], tmpCards[2],tmpCards[3])));
            if (res == 24.0){
                string tempAns="", space=" ";
                tempAns += to_string(tmpCards[0]) + space + opToStr(combinationOps[i][0]);
                tempAns += " ( ";
                tempAns += to_string(tmpCards[1]) + space + opToStr(combinationOps[i][1]);
                tempAns += " ( ";
                tempAns += to_string(tmpCards[2])+space+opToStr(combinationOps[i][2])+space+to_string(tmpCards[3]);
                tempAns += " ))";
                ans.push_back(tempAns);
            }
        }
    }
    return ans;
}