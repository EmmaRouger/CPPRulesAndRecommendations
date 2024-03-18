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
    if(this->balance > amount) //STR53 - Checks that the balance is within the range of the amount the person is able to withdraw
                               //EXP15 - No semicolon after the if statement
        #define withdraw(a, b) (a-b)//PRE01
        this->balance = withdraw(this->balance, amount); 
    else
        cout<<"Insufficient Funds";

}

void ATMAccount::deposit( int amount )
{ this->balance += amount; }
