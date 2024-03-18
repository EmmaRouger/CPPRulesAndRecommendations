//STR51-CPP. Do not attempt to create a std::string from a null pointer
#include <iostream>
#include <string>
#include <cstring>
#include <random>

int main() {
    char* strPtr = nullptr; 
    std::random_device randDevice;
    std::minstd_rand0 engine(randDevice());
 
    if(engine() %2 == 0)//50% chance to happen
    {
        strPtr = new char[14]; // Allocate memory for "Hello, world!" and null terminator
        strcpy(strPtr, "Hello, world!");

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