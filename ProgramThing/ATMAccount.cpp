#include "ATMAccount.h"
#include <iostream>
using namespace std;
//DCL56
ATMAccount::ATMAccount( string nameForAccount, int enteredAccountNum, int enteredPin, int enteredBalance):
    nameOnAccount{ nameForAccount },
    accountNumber{enteredAccountNum},
    balance { enteredBalance },
    pin { enteredPin }, numCheck{1}{}

bool ATMAccount::checkEnteredPin(int enteredPin) //follows MSC52 - value returning functions must always return a value regardless of path taken
{ return (enteredPin == this->pin); }

void ATMAccount::withdrawal( int amount ) //EXP55
{
    if(this->balance > amount)
        this->balance = this->balance-amount;
    else
        cout<<"Insufficient Funds";

}

void ATMAccount::deposit( int amount )
{ this->balance += amount; }
