//OOP54-CPP. Gracefully handle self-copy assignment
#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {}  // virtual destructor
};

class Derived : public Base {
   ~Derived(){
    cout<<"Derived destructor called."<<endl;
  }
};

int main(){
  Base *b = new Derived();  // polymorphic pointer
  delete b; // safely deleting the object
  return 0;
}
