//Mason Myre
//CON52-CPP. Prevent data races when accessing bit-fields from multiple threads
#include <iostream>
using namespace std;
struct t {
  unsigned char it; //define as char
  unsigned char broken; //to allow defined bahavior
};

void a(t example){
  example.it = 1;
}

void b(t example){
  example.broken = 2;
}

int main(int argc, char const *argv[]) {
  /* code */
  t example;

  a(example);
  b(example);
  
  cout << example.it << ", " << example.broken << endl;

  return 0
}
