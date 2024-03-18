//ARR02-C. Explicitly specify array bounds, even if implicitly defined by an initializer
#include <iostream>
using namespace std;
int main()
{
    int numElements = 10;
    int arr[numElements] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Declare the size
    for(int i = 0; i < numElements; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}
