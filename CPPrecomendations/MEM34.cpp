//only free memory allocated dynamically
//Mason Myre

#include <iostream>
using namespace std;

class c{
public:
  int* arr;
  int size;

  c(int s){
    size = s;
    arr = new int[size];
    cout << "test 2a" << size << "\n";
    for(int i = 0; i < s; i++){
      arr[i] = i + 1;
    }
  }

  void print(){
    for(int i = 0; i < size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  ~c(){ //destructor
    delete[] arr;
  }
};


int main() {
  /* code */
  int a = 12;
  c example(a);
  cout << "test1a \n";
  example.print();

  return 0;
}



//spacing
