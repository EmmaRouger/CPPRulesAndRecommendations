#include <string>

class ATMAccount{

private:
    std::string nameOnAccount;
    int balance;
    int pin;//limit to 4 digits on create

public:
    ATMAccount(std::string nameForAccount,int pin, int enteredBalance);

    std::string getAccountName() const { return nameOnAccount; }
    int checkBalance() const { return balance; }

//possibly change so it returns new balance?
    void withdrawal( int amount );
    void deposit ( int amount );

    bool checkEnteredPin( int enteredPin );
};