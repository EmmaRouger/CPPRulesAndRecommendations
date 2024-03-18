//MEM00-C. Allocate and free memory in the same module, at the same level of abstraction

#include <iostream>

class MemoryStuff {
public:
  MemoryStuff() { std::cout<<"Memory created"<<std::endl; }
  ~MemoryStuff() { std::cout<<"Memory destroyed"<<std::endl; }
};

int main() {
  char* newMemory = new char[sizeof(MemoryStuff)]; //Properly allocate memory
  MemoryStuff* obj = new (newMemory) MemoryStuff;

  obj->~MemoryStuff();
  delete[] newMemory; //Properly deallocate memory

  return 0;
}
