//INT18-C. Evaluate integer expressions in a larger size before comparing or assigning to that size

#include <iostream>
#include <limits.h>

int main() {
  int i = 1000000000;
  short j = 0;

  if (32767 < i) { //Evaluate the size
    std::cout<<"Assignment of i to j will not work; j size is too small"<<std::endl;
  }
  else {
    j = i; //Assign after evaluating size
  }

  return 0;
}
