#include <iostream>
#include "ATMAccount.h"
#include <random>
#include <fstream>
#include <algorithm>
using namespace std;


void gamble (ATMAccount *account);
void printMenu1(void); //uses DCL20 - use void when a method takes no parameters
void printMenu2(void); //DCL20
void create_check(ATMAccount *account);
int * shuffle(int copyMe [], int size);

//DLC58-CPP  -  we never modify the standared namespaces
//EXP63 - Never moved values so we never rely on moved-from object assumptions
////DLC52-CPP - Never use Const on a reference Type
/*
    main function
    uses Rule EXP50 EXP60 MEM00 MEM51 MEM53 DCL53 DCL57 DCL51 STR51 CTR54 EXP53
    uses Recommendations EXP15
*/
int main(){
    int accountNumCounter = 2;
    ATMAccount acc1("Alfred Yankovic", 1, 1234, 8000);
    ATMAccount acc2("John Mann", 2, 1234, 10);
    vector<ATMAccount> vect {acc1,acc2};


    int choice = 0;

    cout<<"Welcome to The Casino ATM"<<endl;

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
                ATMAccount *account = &vect[getAccountNum-1]; //follows rule DCL53, EXP60, CTR55 - Don't access nonexistent element in a list //Follows MEM52 - no need to check for null
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
                    else if(choice == 5){
                        gamble( &(vect.at(getAccountNum-1)));
                    }
                }while(choice != 6);
                delete account; //MEM51, MEM53,
                //MEM160 - not accessing freed memory after it was deleted
            //should have a choice to exit to main menu
            }
        }
        else if(choice == 3)
        {
            string name;
            cout << "Enter your name on the account: ";
            cin >> name;
            bool found=false;
            for (auto it = vect.begin(); it != vect.end(); ++it) //CTR54 //CRT53 - Never goes outside the iterator ranges
            {
                if(it->getAccountName() == name)
                {
                    cout << "Your Account Number is: " << it->getAccountNum()<<endl;
                    found=true;
                }
            }

            if(!found)
            {
                cout << "No Account Link to the name you Entered: "<< name<< endl;
            }
        }
    }while(choice != -1); //EXP 20 rec

    
    vect.clear(); // EXP62 //CTR51 //MEM34

}

void printMenu1(void){ //uses DCL20 - use 'void' when a method does not take in any parameters
    cout<<"1) Create a new account\n2) Enter Account Number\n3) Forgot Account Number\n> ";
}

void printMenu2(void) //uses DCL20
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

    unsigned char g = 0; //STR00
    int gamble = g;

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
    
    // MSC51 - Optimal random number generation
    // 
    random_device fate;
    minstd_rand0 engine(fate());

    // int lucky = engine() % 10;
    // int unlucky = engine() % 10;

    // while (lucky == unlucky)
    // {
    //     unlucky = engine() % 10;
    // }

    int randomArr [20] = {0};
    for (int i = 0; i < 20; i++)
    {
        randomArr[i] = engine() % 99;
    }
    
    cout << "\nPlease select a number from the list: \n";
    for (int i : randomArr)
    {
        cout << i << " | ";
    }

    // Shuffle
    int * shuffledArr = shuffle(randomArr, (sizeof(randomArr)/sizeof(randomArr[0])));
    

    vector<int> lucky;
    for (int i = 0; i < 5; i++)
    {   
        int temp = *(shuffledArr+i);
        lucky.push_back(temp);
    }
    
    vector<int> unlucky;
    for (int i = 19; i > 14; i--)
    {
        int temp = *(shuffledArr + i);
        unlucky.push_back(temp);
    }
    cout << "\nEnter Here: ";
    int input = 0;
    bool validInput = false;
    cin >> input;

    while (!validInput){
        if (input >= 0 && input <= 99)
        {
            validInput = true;
        }
        else
        {
            cout << "\nInvalid guess. Please type a numnber from the list: ";
            for (int i : randomArr)
            {
                cout << i << " | ";
            }
            cin >> input;
        }
    }
    
    vector<int>::iterator luckySearch = find(lucky.begin(), lucky.end(), input);
    vector<int>::iterator unluckySearch = find(unlucky.begin(), unlucky.end(), input);

    if (luckySearch != lucky.end()) // Big Win
    {
        cout << "\nYou got it! Lucky you! Depositing: " << gamble*3 << " into your account.\n";
        account->deposit(gamble*3);
    }
    else if (unluckySearch != unlucky.end()) //Big Lose
    {
        cout << "\nYeouch! How unfortunate, you got the unlucky number... Removing: " << gamble*2 << " from your account.\n";
        account->withdrawal(gamble*2);
    }
    else // Lose
    {
        cout << "\nDarn. Ya didn't get the unlucky number atleast! Removing: " << gamble << " from your account.\n";
        account->withdrawal(gamble);
    }

    cout << "New Account Balance: " << account->checkBalance() << "\n";
    delete[] shuffledArr;
}
/*

    Creates a copy of a given array and shuffles the copied array
    Uses CTR52
*/
int * shuffle(int copyMe [], int size){
    int * shuffledArr = new int [20] {0};
    int * shuffledArrPtr = shuffledArr;
    for (int i = 0; i < size; i++)
    {
        shuffledArr[i] = copyMe[i];
    }
    
    random_device fate;
    minstd_rand0 engine(fate());

    shuffle(shuffledArr, shuffledArr + size, default_random_engine(engine()));

    return shuffledArrPtr;
}


/*
    create a check
    use Rule FIO50 DLC57 ERR55, ERR59
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
    {//FIO50
        string fileName = "Check"+ to_string(account->getNumCheck()); //STR52 - valid reference to a basic_string
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
    catch(const std::exception& e)//DCL 57 //ERR54 - This is the lowest level of derived exception
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }


    cout << "Is the information correct (y/n): ";
    string validator;
    cin >> validator;
    cout << endl;
    if(validator=="y") //EXP20 rec
    {
        account->withdrawal(amount);
        account->setNumCheck();
    }
    else
    {
        create_check(account);
    }

}