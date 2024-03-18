//API05-C. Use conformant array parameters
#include <iostream>

int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    printArr(arr, size);
}

void printArr(int arr[], int size)//Here we use conformat array parameters to allow for any size array
{
    for(int i = 0; i < size; i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
}