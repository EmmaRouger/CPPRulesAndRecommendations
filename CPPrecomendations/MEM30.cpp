//MEM30-C. Do not access freed memory
#include <iostream>
using namespace std;

/*
    We use the int pointer to an array before it is deleted.
*/
int main(){

    int * arr = new int [5] {10,15,45,32,55};
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr+i) << " | ";
    }
    delete[] arr;

    return 0;
}
