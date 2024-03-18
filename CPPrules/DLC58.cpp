//DCL58-CPP. Do not modify the standard namespaces
#include <iostream>

//this code below violates the rule because it changes the standard namespace
// namespace std
// {
//     void printHello()
//     {
//         std::cout<<"Hello World"<<std::endl;
//     }
// }
namespace myNameSpace//here we use a uniquely named namespace
{
    void printHello()
    {
        std::cout<<"Hello World"<<std::endl;
    }
}
int main()
{
    myNameSpace::printHello();
    return 0;
}