#include <iostream>

// Corrected macro with parenthesized replacement list
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 5, y = 10;
    int result = MAX(x, y + 1); 


    std::cout << "Result 1: " << result1 << std::endl;

    return 0;
}