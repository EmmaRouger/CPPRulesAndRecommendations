//EXP20-C: Perform explicit tests to determine success, true and false, and equality

#include <iostream>

int main() {
    int x = 5;
    int y = 10;
    int z = 15;

    if (x > 0 && y > 0 && z > 0) {
        std::cout << "All variables are greater than 0." << std::endl;
    } else {
        std::cout << "At least one variable is not greater than 0." << std::endl;
    }

    if (x != 5 || y != 5 || z != 5) {
        std::cout << "No variable is equal to 5." << std::endl;
    } else {
        std::cout << "At least one variable is equal to 5." << std::endl;
    }

    return 0;
}