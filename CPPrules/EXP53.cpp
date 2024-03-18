//EXP53-CPP. Do not read uninitialized memory
#include <iostream>
using namespace std;

void exampleFunction(int ex);
int main()
{
    int example = 50;//initialized data -- Rule states do not access uninitialized memory
    exampleFunction(example);
}

void exampleFunction(int ex)
{
    std::cout<<ex<<std::endl;
}