#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H
#include <string>
#include <iostream>
using namespace std;

// namespace n{ //rule DCL59 - defining a named namespace (as opposed to a nonnamed namespace) in a header file
//     void printHello(){
//         cout << "Hello, World!\n";
//     }
// }

class ATMAccount{

private:
    string nameOnAccount;
    int balance;
    int pin;//limit to 4 digits on create
    int accountNumber;
    int numCheck;

public:
    ATMAccount(string nameForAccount, int enteredAccountNum, int enteredPin, int enteredBalance);

    string getAccountName() const { return nameOnAccount; }
    int checkBalance() const { return balance; }
    int getAccountNum() const { return accountNumber; }
    int getNumCheck() const { return numCheck; }
    void setNumCheck() { this->numCheck++ ;}

//possibly change so it returns new balance?
    void withdrawal( int amount );
    void deposit ( int amount );

    bool checkEnteredPin( int enteredPin );
};

#endif