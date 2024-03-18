//PRE02-C. Macro replacement lists should be parenthesized
#include <iostream>

// Corrected macro with parenthesized replacement list
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 5, y = 10;
    int result = MAX(x, y + 1); 


    std::cout << "Result: " << result << std::endl;

    return 0;
}