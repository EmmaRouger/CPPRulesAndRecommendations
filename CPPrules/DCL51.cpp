#include <iostream>

//everything uses a user defined
void printMessage() {
    std::cout << "Hello, world!" << std::endl;
}

int main() {

    int count = 5;

    printMessage();

    std::cout << "Count: " << count << std::endl;

    return 0;
}