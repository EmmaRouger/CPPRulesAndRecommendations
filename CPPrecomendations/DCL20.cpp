//DCL20 states that when there is a function that takes no parameters, you should write 'void' so the
//compiler knows what parameters it should take in regardless.
//Mason Myre
#include <iostream>
using namespace std;

void printHello(void){ //creating the function that takes no parameters
  cout << "Hello, World!" << endl;
}

int main(){
  printHello(); //running the function passing no parameters
}
