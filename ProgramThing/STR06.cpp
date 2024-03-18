//STR06 Do not assume that strtok() leaves the parse string unchanged

#include <iostream>
#include <cstring>

int main() 
{
    
    char input[] = "123,456,789";
    char *copy = (char *)malloc(strlen(input) + 1);
    strcpy(copy, input);
    std::cout << input<<std::endl;
    char* token;

    // Split the input string into tokens separated by commas
    token = strtok(input, ",");
    while (token != NULL) {
        std::cout << "Token: " << token << std::endl;
        token = strtok(NULL, ",");
    }
    std::cout << input<<std::endl;
        std::cout << "Truncated when using strtok so copy it before using it, the copy doesn't change: "<<std::endl;
        std::cout << copy << std::endl;

    return 0;
}