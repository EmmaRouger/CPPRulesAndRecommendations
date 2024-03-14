#include <iostream>

int main() {
    int *array = new int[3];
    array[0]=array[1]=array[2]=2;
    std::cout << array[0] +","+array[1]+","+array[2]+" this is the array"<< std::endl;
    delete[] array;

    std::cout << "array deleted" << std::endl;

    return 0;
}