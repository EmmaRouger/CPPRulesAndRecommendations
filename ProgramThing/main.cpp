#include <iostream>
#include "ATMAccount.h"
#include <random>
// using namespace std;

void gamble (int amount);

int main(){

    ATMAccount acc1("Alfred Yankovic", 1, 1234, 8000);

    vector<ATMAccount> vect {acc1};

    int choice = 0;

    while(choice != -1)
    {
        
    }

}

/*

    Insert amount you want to gamble. Guess a number between 1 & 10.
    Rules Used: MSC51, MSC52, EXP54

*/
void gamble(int amount){

    std::cout << "If you guess the lucky number, you can get back triple of your money back.\n" <<
    "If you guess the unlucky number, you lose double the amount you gambled!\n" <<
    "If you get neither, you lose the amount you gambled\n" <<
    "Always remember: there is no losing in gambling, only quitting!\n" <<
    "Please type a number between 1 & 10: ";

    random_device fate;
    minstd_rand0 engine(fate());

    int lucky = engine() % 10;
    int unlucky = engine() % 10;

    while (lucky == unlucky)
    {
        int unlucky = engine() % 10;
    }

    int input = 0;
    bool validInput = false;
    while (!validInput){

        cin >> input;
        while ()
        {
            /* code */
        }


    }
}