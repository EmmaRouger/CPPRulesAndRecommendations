//DCL59 states that a programmer should not declare an unnamed namespace
//Mason Myre

#include <iostream>
namespace n { //a named namespace
  void printHello(){
    std::cout << "Hello World!" << std::endl;
  }
}

using namespace n;
int main(){
  printHello();
  return 0;
}
