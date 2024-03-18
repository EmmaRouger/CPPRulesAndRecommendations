//OOP55-CPP. Do not use pointer-to-member operators to access nonexistent members
#include <iostream>

class MyClass {
public:
    int value;

    MyClass(int val) : value(val) {}
};

int main() {
    MyClass obj(42);

    int MyClass::*ptr = &MyClass::value;

    int result = obj.*ptr;

    std::cout << "Value: " << result << std::endl;

    return 0;
}