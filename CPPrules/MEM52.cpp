//MEM52-CPP. Detect and handle memory allocation errors
#include <iostream>
using namespace std;
int main()
{
    int *test = new (nothrow) int;//no throw stopes a bad_alloc exeption from throwing

    *test = 100;

    if(test == nullptr)//when dealing with no throw we must check for null pointer
    {
        cout<<*test<<endl;
    }
}