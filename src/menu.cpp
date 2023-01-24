#include <bits/stdc++.h>
#include "menu.h"
#include "solver.h"
#include <time.h>

using namespace std;

map<string, int> playableCards{
    {"2",2},
    {"3",3},
    {"4",4},
    {"5",5},
    {"6",6},
    {"7",7},
    {"8",8},
    {"9",9},
    {"10",10},
    {"A",1},
    {"J",11},
    {"Q",12},
    {"K",13}
    };

/**
 * @brief result after using brute force algorithm
 * if the choice is '1' then user manually input their cards, if '2' system will generate randomized cards
 * 
 * @param choice 
 */
void result(int choice){
    vector<int> cards;
    if (choice==1){
        cards =userInput();
    }else{
        cards =randomInput();
    }
    auto start = chrono::high_resolution_clock::now();
    vector<string> ans = finalSolver(cards);
    auto end = chrono::high_resolution_clock::now();
    float executionTime = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "==== SOLUTIONS =====" << endl;
    if (ans.size()==0){
        cout << "No Solution found" << endl;
    }else{
        cout << ans.size() << " solutions found!" << endl;
        for (auto i=0;i<ans.size();i++){
            cout << ans[i]<<endl;
        }
        cout << setprecision(3) << fixed;
        cout << "Execution time: " << executionTime << " ms" << endl;
        
        string choice;
        do{
            cout << "Do you want to save the solutions to file? (y/n)" << endl<<"Choice: ";
            getline(cin, choice);
            if (choice=="y"){
                ansToTxt(cards, ans, executionTime);
            }else if(choice=="n"){
                continue;
            }else{
                cout << "invalid input! please input (y/n)" << endl;
            }
        } while (choice != "y" && choice != "n");
    }
    
    bool run = true;
    do{
        string choice;
        cout << "Do you want to play again?(y/n)" << endl<<"Choice: ";
        getline(cin, choice);
        if (choice=="y"){
            run = false;
            mainmenu();                
        }else if(choice=="n"){
            cout << "========== Thanks for using 24Solver =========="<<endl;
            run = false;
        }else{
            cout << "invalid input! please input (y/n)" << endl;
        }
    }while(run);
};

/**
 * @brief user manually input their cards
 * 
 * @return vector<int> 
 */
vector<int> userInput(){
    vector<int> finalCards;
    
    bool valid = false;
    
    cout << "\n====== INPUT =======" << endl;
    do{
        string inputCards;
        printf("Input 4 Cards each separated by space\n"
            "Valid cards: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K\n"
            "(example: A 2 3 Q)\n"
            "Input: ");
        getline(cin, inputCards);
        stringstream charCard(inputCards);
        string inp;
        while (charCard>>inp){
            auto i = playableCards.find(inp);
            if (i != playableCards.end()){
                finalCards.push_back(i->second);
                valid = true;
            }else{
                cout<<inp<<" is not valid, please input again\n"<<"----------------------------\n";
                finalCards.clear();
                valid = false;
                break;
            }
        }
        if (finalCards.size()!=4 and finalCards.size()!=0){
            printf("Please input exactly 4 cards\n"
                   "----------------------------\n");
            finalCards.clear();
            valid = false;
        }
    } while (!valid);
    printf("\n");
    return finalCards;
};

/**
 * @brief generate random 4 cards
 * 
 * @return vector<int> 
 */
vector<int> randomInput(){
    vector<int> randCards;
    int random;
    
    cout << "\n====== RANDOM ======" << endl;
    srand(time(0));
    
    printf("Valid cards: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K\n"
           "Generating random cards......\n");
    for (int i = 0; i < 4;i++){
        random = rand() % 13 + 1;
        randCards.push_back(random);
    }
    printf("Random Cards: ");
    
    int i = 0;
    while (i<4){
        auto op = playableCards.begin();
        while(op!=playableCards.end()){
            if(randCards[i]==op-> second){
                cout << op->first;
                if (i!=3){
                    cout << " ";
                }
                break;
            }
            op++;
        }
        i++;
    }
    printf("\n\n");
    return randCards;
};

/**
 * @brief save solutions to file .txt
 * 
 * @param cards 
 * @param solutions 
 * @param time 
 */
void ansToTxt(vector<int> cards, vector<string> solutions, float time){
    string namafile;
    cout << "Enter your file name: ";
    getline(cin, namafile);
    ofstream text("../test/"+namafile+".txt");
    text << "Cards: ";
    for (auto j=0;j<cards.size();j++){
        text << cards[j]<<" ";
    }
    text << endl<<solutions.size() << " solutions found!" << endl;
    for (auto i=0;i<solutions.size();i++){
        text << solutions[i]<<endl;
    }
    text << setprecision(3) << fixed;
    text << "Execution time: " << time << " ms" << endl;
        
};

/**
 * @brief main menu
 * 
 */
void mainmenu(){
    string choice;
    bool valid=false;
    printf("\n");
    printf("======= MENU =======\n"
           "1. Input Cards\n"
           "2. Random Cards\n"
           "3. Exit\n");
    do{
        printf("Input your choice: ");
        getline(cin, choice);
        if (choice =="1"){
            valid = true;
            result(1);
        }else if (choice=="2"){
            valid = true;
            result(2);
        }else if (choice=="3"){
            valid = true;
            printf("\n"
                   "========== Thanks for using 24Solver ==========\n");
        }else{
            printf("Invalid Input!\n");
        }
    } while (!valid);
}