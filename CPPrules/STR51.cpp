#include <iostream>
#include <string>

int main() {
    char* strPtr = nullptr; 
    std::string str;

    if (strPtr != nullptr) {
        str = strPtr; 
    }

    std::cout << "String value: " << str << std::endl;

    return 0;
}