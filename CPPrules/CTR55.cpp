//prevent overflow when using additive operators on an iterator
//Mason Myre
#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[]) {

  int arr [10] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9, 10};
  int n = sizeof(arr)/sizeof(arr[0]); //get the number of iterations directly from the size of the list
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
