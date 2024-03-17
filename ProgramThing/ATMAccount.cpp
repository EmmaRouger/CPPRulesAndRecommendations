#include "ATMAccount.h"
using namespace std;

ATMAccount::ATMAccount( string nameForAccount, int enteredAccountNum, int enteredPin, int enteredBalance):
    nameOnAccount{ nameForAccount },
    accountNumber{enteredAccountNum},
    balance { enteredBalance },
    pin { enteredPin }{}

bool ATMAccount::checkEnteredPin(int enteredPin)
{ return (enteredPin == this->pin); }

void ATMAccount::withdrawal( int amount )
{ if(this->balance > amount)
    this->balance = this->balance-amount; }

void ATMAccount::deposit( int amount )
{ this->balance += amount; }
