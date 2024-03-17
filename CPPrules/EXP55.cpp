//Do not access a cvqualified object through a unqualified type
//Mason Myre
#include <iostream>

using namespace std;

void pass(int &a){
  a = 101;
}

int main(int argc, char const *argv[]) {
  /* code */
  int a = 1;
  pass(a);
  cout << a << endl;

  return 0;
}










//spacing
