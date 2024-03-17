//Rule MEM53-CPP

#include <iostream>

//Ensure the objects are not trivially constructible/destructible
class MemoryStuff {
public:
  MemoryStuff() { std::cout<<"Memory created"<<std::endl; } //Constructor
  ~MemoryStuff() { std::cout<<"Memory destroyed"<<std::endl; } //Destructor
};

int main() {
  char* newMemory = new char[sizeof(MemoryStuff)]; //Properly allocate memory
  MemoryStuff* obj = new (newMemory) MemoryStuff;

  obj->~MemoryStuff();
  delete[] newMemory; //Properly deallocate memory

  return 0;
}
