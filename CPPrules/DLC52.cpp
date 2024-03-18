//DLC52-CPP. Never qualify a reference type with const or volatile
#include <iostream>

int main()
{

    char const &char1 = 'a';//this rule is kinda straight forward - There is a correct way and a wrong way

    std::cout<<char1<<std::endl;

    return 0;
}