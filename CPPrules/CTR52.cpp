#include <iostream>
using namespace std;

void helper(int copyMe[], int size);
/* 

    When creating the array copy, we ensure that it can hold the copyMe items by 
    using copyMe's size to initialize the container array. 

*/
int main(){
    int v1[] = {1,2,3,4,5,6,7,8,9,10};
    helper(v1, sizeof(v1)/sizeof(v1[0]));

    return 0;
}

void helper(int copyMe[], int size){
    int container [size];

    for (int i = 0; i < size; i++)
    {
        container[i] = copyMe[i];
    }

    cout << "Size of argument array: " << size << "\n";
    cout << "Size of copy array: " << sizeof(container)/sizeof(container[0]) << "\n";

    for (int i : container)
    {
        cout << "Copied Container has " << i << "\n";
    }


}