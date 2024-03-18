//EXP15-C. Do not place a semicolon on the same line as an if, for, or while statement
#include <iostream>
#include <cstdio>
#include <ostream>

int main() {
    FILE* file = fopen("data.txt", "r");
    if (file == nullptr) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    char buffer[30]; // Buffer size is intentionally small
    char buffer2[3000];
    if (fgets(buffer, sizeof(buffer), file) != nullptr) {
        std::cout << "Read line: " << buffer << std::endl;
    } else {
        std::cerr << "Error reading line." << std::endl;
    }
    fclose(file);
    std::cout<<std::endl;
    file = fopen("data.txt", "r");
    if (file == nullptr) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    if (fgets(buffer2, sizeof(buffer2), file) != nullptr) {
        std::cout << "Read line with new buffer: " << buffer2 << std::endl;
    } else {
        std::cerr << "Error reading line." << std::endl;
    }
    fclose(file);
    return 0;
}


