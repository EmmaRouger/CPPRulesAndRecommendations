//CTR53-CPP. Use valid iterator ranges
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect = {1,2,3,4,5};

    std::vector<int>::iterator iter;

    for(iter = vect.begin(); iter < vect.end(); iter++) // here we only iterate from the start to end not going past the vector bounds
        std::cout<<*iter<<std::endl;

    return 0;
}