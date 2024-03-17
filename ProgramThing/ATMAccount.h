#ifndef ATM_ACCOUNT
#define ATM_ACCOUNT
#include <string>
using namespace std;

class ATMAccount{

private:
    string nameOnAccount;
    int balance;
    int pin;//limit to 4 digits on create
    int accountNumber;

public:
    ATMAccount(string nameForAccount, int enteredAccountNum, int enteredPin, int enteredBalance);

    string getAccountName() const { return nameOnAccount; }
    int checkBalance() const { return balance; }

//possibly change so it returns new balance?
    void withdrawal( int amount );
    void deposit ( int amount );

    bool checkEnteredPin( int enteredPin );
};

#endif