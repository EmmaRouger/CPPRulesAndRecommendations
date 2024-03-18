//PRE10-C. Wrap multistatement macros in a do-while loop

#include <iostream>

#define SWAP(x, y) \
  do { \
    if ((x) < (y)) { \
      int temp = (x); \
      (x) = (y); \
      (y) = temp; \
    } else { \
      std::cout<<"The first number is greater than the second"<<std::endl; \
      std::exit(1); \
    } \
  } while(0)

int main() {
  int m = 20;
  int n = 10;
  std::cout<<"Prior to swap, first number = "<<m<<" and second number = "<<n<<std::endl;
  SWAP(m, n);
  std::cout<<"After swap, first number = "<<m<<" and second number = "<<n<<std::endl;
  return 0;
}
