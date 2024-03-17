#include <iostream>
#include <string>

int main() {
    char* strPtr = nullptr; 

    if(rand() % 2 == 0)//50% chance to happen
    {
        strPtr = ['h','e','l','l','o'];
    }

    std::string str;

    if (strPtr != nullptr) {// make sure it isn't null before using it
        str = strPtr; 
        std::cout << "the string got assigned to: " << str << std::endl;
    }
    else
    {
        std::cout << "it was null so assignment did not happen"<<std::endl;
    }


    delete[] strPtr;
    return 0;
}