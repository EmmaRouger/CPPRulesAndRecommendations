//Recommendation MEM00-C
//Allocate and deallocate memory in the same module and at the same abstraction level

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
