#include <iostream>
#include "ATMAccount.h"
#include <random>

void gamble (ATMAccount account);
void printMenu1();

int main(){

    ATMAccount acc1("Alfred Yankovic", 1, 1234, 8000);
    ATMAccount acc2("John Mann", 2, 1234, 10);

    vector<ATMAccount> vect {acc1,acc2};

    int choice = 0;
    cout<<"Welcome to The Casion ATM"<<endl;
    while(choice != -1)
    {
        if(choice == 0)
        {
            printMenu1();
            cin>>choice;
            cout<<endl;
            if(choice > 2 || choice < 1)
            {
                cout<<"Invalid Choice\n";
                choice = 0;
            }
            if(choice == 1)
            {
                //make process for creating an new account and add it the vector
            }
            else if (choice == 2)
            {
                //enter accout and pin

                //print choices
            }
            
        }

    }

}

void printMenu1(){
    cout<<"1) Enter Account Number\n2) Create a new account\n> ";
}

/*

    Insert amount you want to gamble. Guess a number between 1 & 10.
    Rules Used: MSC51, EXP54

*/
void gamble(ATMAccount account){

    cout << "If you guess the lucky number, you can get back triple of your money back.\n" <<
    "If you guess the unlucky number, you lose double the amount you gambled!\n" <<
    "If you get neither, you lose the amount you gambled\n" <<
    "Always remember: there is no losing in gambling, only quitting!\n";

    int gamble = 0;

    cout << "Enter an amount to gamble: ";
    cin >> gamble;
    bool validAmount = false;
    while (!validAmount)
    {
        if (gamble > 0 && gamble <= account.checkBalance())
        {
            validAmount = true;
        }
        else{
            cout << "Invalid, please enter an amount to gamble: ";
            cin >> gamble;
        }
    }


    random_device fate;
    minstd_rand0 engine(fate());

    int lucky = engine() % 10;
    int unlucky = engine() % 10;

    while (lucky == unlucky)
    {
        int unlucky = engine() % 10;
    }

    cout << "\nPlease type a number between 0 & 10: ";

    int input = 0;
    bool validInput = false;
    cin >> input;

    while (!validInput){
        if (input >= 0 && input <= 10)
        {
            validInput = true;
        }
        else
        {
            cout << "\nInvalid guess. Please type a numnber between 0 & 10: ";
            cin >> input;
        }
    }

    if (input == lucky) // Big Win
    {
        cout << "You got it! Lucky you! Depositing: " << gamble*3 << " into your account.\n";
        account.deposit(gamble*3);
    }
    else if (input == unlucky) //Big Lose
    {
        cout << "Yeouch! How unfortunate, you got the unlucky number... Removing: " << gamble*2 << " from your account.\n";
        account.withdrawal(gamble*2);
    }
    else // Lose
    {
        cout << "Darn. Ya didn't get the unlucky number atleast! Removing: " << gamble << " from your account.\n";
        account.withdrawal(gamble);
    }
}