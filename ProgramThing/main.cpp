#include <iostream>
#include "ATMAccount.h"
#include <random>
#include <fstream>
using namespace std;

void gamble (ATMAccount account);

void create_check(ATMAccount account);

int main(){

    ATMAccount acc1("Alfred Yankovic", 1, 1234, 8000);

    vector<ATMAccount> vect {acc1};

    int choice = 0;

    create_check(acc1);

}

/*

    Insert amount you want to gamble. Guess a number between 1 & 10.
    Rules Used: MSC51, EXP54

*/
void gamble(ATMAccount account){

    std::cout << "If you guess the lucky number, you can get back triple of your money back.\n" <<
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



void create_check(ATMAccount account)
{
    int amount ;
    string recipient;
    cout << "Check creation:" << endl;
    cout << "please enter the amount you want to put on the check: ";
    cin >> amount ;
    cout << endl;
    cout << "Enter the recipient of the check: ";
    cin >> recipient;
    cout << endl;

    string fileName = "Check"+ to_string(account.getNumCheck());
    fstream myFile(fileName, ios::in | ios::out | ios::trunc);

    if (!myFile.is_open()) {
        std::cerr << "WARNING!!! Error: Failed to open file " << fileName << std::endl;
        return; 
    }

    myFile << "To : "<< recipient << endl ;
    myFile << "Amount : " << amount << " dollars"<<endl;
    myFile << "From : " << account.getAccountName()<<endl;

    myFile.seekg(0, ios::beg); //allow to do both write and read from same opened filed

    cout << "Data read from Check (make sure everything is right on the check): " << endl;
    // Print the content of the file
    string line;
    while (getline(myFile, line)) {
        cout << line << endl;
    }

    cout<< endl;

    myFile.close();

    cout << "Is the information correct (y/n): ";
    string validator;
    cin >> validator;
    cout << endl;
    if(validator=="y")
    {
        account.withdrawal(amount);
        account.setNumCheck();
    } 
    else
    {
        create_check(account);
    }

}