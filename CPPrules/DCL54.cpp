#include <iostream>
#include <new>

using namespace std;

class Library{
public:
  void *operator new(size_t size){
    cout<<"Allocation Overloading"<<endl;
    return malloc(size);
  }
  void operator delete(void *ptr, size_t size) noexcept{
    cout<<"Deallocation Overloading"<<endl;
    free(ptr);
  }
};

int main(){
  Library* book1 = new Library;
  delete book1;
  return 0;
}
