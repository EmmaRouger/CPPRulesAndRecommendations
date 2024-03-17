#include <iostream>
#include "ATMAccount.h"
#include <random>
#include <fstream>
using namespace std;


void gamble (ATMAccount *account);
void printMenu1();
void printMenu2();
void create_check(ATMAccount *account);


/*
    main function
    uses Rule MEM51 DCL57 OOP55 DCL51
*/
int main(){
    int accountNumCounter = 2;
    ATMAccount acc1("Alfred Yankovic", 1, 1234, 8000);
    ATMAccount acc2("John Mann", 2, 1234, 10);
    vector<ATMAccount> vect {acc1,acc2};


    int choice = 0;

    cout<<"Welcome to The Casion ATM"<<endl;
    do
    {
        printMenu1();
        cin>>choice;
        cout<<endl;
        if(choice > 3 || choice < (-1))
        {
            cout<<"Invalid Choice\n";
            choice = 0;
        }
        if(choice == 1)
        {
            //make process for creating an new account and add it the vector
            // Account Name Setup
            string accName = "";
            int id = accountNumCounter+1;
            accountNumCounter++;
            int pin = 0;
            cout << "Please enter an account name: ";
            cin >> accName;
            // Account Pin setup
            cout << "Please enter a 4 digit pin for your account: ";
            cin >> pin;
            bool validPin = false;
            int pinLength = 0;
            while(!validPin){
                pinLength = log10(pin) + 1;
                if (pinLength == 4)
                {
                    cout << "\nPin Accepted.\n";
                    validPin = true;
                }
                else{
                    cout << "\nInvalid pin. Please try again.";
                    cout << "\nPlease enter a 4 digit pin for your account: ";
                    cin >> pin;
                }
            }

            //Account Balance setup
            int balance = 0;
            cout << "\nPlease enter a starting balance: ";
            cin >> balance;
            bool validBalance = false;
            while(!validBalance){
                if (balance > 0)
                {
                    cout << "\nStarting balance set.";
                    validBalance = true;

                }
                else{
                    cout << "\nInvalid input. Please try again.";
                    cout << "\nPlease enter a starting balance: ";
                    cin >> balance;
                }

            }
            // Add Account to vector
            ATMAccount newAcc(accName, id, pin, balance);
            vect.push_back(newAcc);

            cout << "\nAccount Added. Your account number is " << id <<"\n";
            choice = 2;
        }
        else if (choice == 2)
        {
            int getAccountNum, getPinNum;
            //enter account num and pin
            cout<<"Enter Account Number\n> ";
            cin >> getAccountNum;
            cout<<endl;

            if((getAccountNum > accountNumCounter) || (getAccountNum < 1)){
                cout<<"Not a valid Account Number\n";
                choice = 2;
            }
            else
            {
                ATMAccount *account = &vect[getAccountNum-1];
                cout<<"Welcome "<< account->getAccountName()<<"\nEnter Pin\n> ";
                cin>>getPinNum;
                cout<<"\n";
                while(!account->checkEnteredPin(getPinNum))
                {
                    cout<<"Incorrect Pin\nEnter a Pin\n> ";
                    cin>>getPinNum;
                    cout<<"\n";
                }

                //print new choices when in account
                do
                {
                    printMenu2();
                    cin>>choice;
                    cout<<"\n";
                    if(choice > 6 || choice < 1)
                    {
                        cout<<"Invalice Choice\n";
                        choice = 0;
                    }
                    if(choice == 1)
                    {
                        cout<<"Current Balance: $"<<account->checkBalance()<<endl;
                    }
                    else if(choice == 2)
                    {
                        int amount;
                        cout << "Please enter the amount you want to deposit\n>";
                        cin >> amount;

                        account->deposit(amount);
                        cout << "New Account Balance: $"<<account->checkBalance()<<endl;
                    }
                    else if(choice == 3)
                    {
                        int amount;
                        cout << "Please enter the amount you want to withdraw\n>";
                        cin >> amount;

                        account->withdrawal(amount);
                        cout << "New Account Balance: $"<<account->checkBalance()<<endl;
                    }
                    else if(choice == 4)
                    {
                        create_check(account);
                    }
                }while(choice != 6);
                delete account;
            //should have a choice to exit to main menu
            }
        }
        else if(choice == 3)
        {

        }
    }while(choice != -1);


}

void printMenu1(){
    cout<<"1) Create a new account\n2) Enter Account Number\n3) Forgot Account Number\n> ";
}

void printMenu2()
{
    cout<<"1) Check Balance\n2) Deposit\n3) Withdrawal\n4) Create check\n5) Gamble\n6) Log Out\n> ";
}

/*

    Insert amount you want to gamble. Guess a number between 1 & 10.
    Rules Used: MSC50, MSC51, EXP54

*/
void gamble(ATMAccount *account){

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
        if (gamble > 0 && gamble <= account->checkBalance())
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
        account->deposit(gamble*3);
    }
    else if (input == unlucky) //Big Lose
    {
        cout << "Yeouch! How unfortunate, you got the unlucky number... Removing: " << gamble*2 << " from your account.\n";
        account->withdrawal(gamble*2);
    }
    else // Lose
    {
        cout << "Darn. Ya didn't get the unlucky number atleast! Removing: " << gamble << " from your account.\n";
        account->withdrawal(gamble);
    }
}


/*
    create a check
    use Rule FIO50 DLC57
*/
void create_check(ATMAccount *account)
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

    try
    {
        string fileName = "Check"+ to_string(account->getNumCheck());
        fstream myFile(fileName, ios::in | ios::out | ios::trunc);
            
        myFile << "To : "<< recipient << endl ;
        myFile << "Amount : " << amount << " dollars"<<endl;
        myFile << "From : " << account->getAccountName()<<endl;

        myFile.seekg(0, ios::beg); //allow to do both write and read from same opened filed

        cout << "Data read from Check (make sure everything is right on the check): " << endl;
        // Print the content of the file
        string line;
        while (getline(myFile, line)) {
            cout << line << endl;
        }

        cout<< endl;

        myFile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        fclose(myFile);
    }


    cout << "Is the information correct (y/n): ";
    string validator;
    cin >> validator;
    cout << endl;
    if(validator=="y")
    {
        account->withdrawal(amount);
        account->setNumCheck();
    }
    else
    {
        create_check(account);
    }

}