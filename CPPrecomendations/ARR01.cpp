#include <iostream>
using namespace std;

int * arr01Helper(int arr [], int size);
int main();

/*
    Returns an array pointer with double the size. 
*/
int * arr01Helper(int arr [], int size){
    int * newArr = new int [size*2] {0};

    for(int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    for(int i = size; i < size*2; i++){
        newArr[i] = arr[i-size];
    }

    return newArr;
}

/*
    When calculating the size of an array, the array must be created in the same scope of the sizeof operator's use.
*/
int main(){
    int arr[] = {1,2,3,4,5,6};
    int arr1Size = sizeof(arr)/sizeof(arr[0]);
    int * newArrPointer = arr01Helper(arr, arr1Size);

    cout << "Size: " << arr1Size << "\n";
    
    cout << "Print new Array with double size: \n";
    
    for (int i = 0; i < arr1Size*2; i++)
    {
        cout << *(newArrPointer + i) << " | ";
    }
    cout << "\n";
    delete[] newArrPointer;

    return 0;
}