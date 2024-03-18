//EXP60-CPP. Do not pass a nonstandard-layout type object across execution boundaries

#include <iostream>

struct nonStandardLayoutType {
  int m;
  double n;
};

void modifyValues(nonStandardLayoutType& obj) {
  obj.m /= 5;
  obj.n *= 2;
}

int main() {
  nonStandardLayoutType obj2; //create an instance of nonStandardLayoutType
  obj2.m = 25;
  obj2.n = 3.1415;

  std::cout<<"Value before: "<<obj2.m<<std::endl;
  modifyValues(obj2); //The function is called within the same compilation unit (no execution boundary)
  std::cout<<"Value after: "<<obj2.m<<std::endl;
  return 0;
}
