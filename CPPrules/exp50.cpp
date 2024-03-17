//Rule EXP50-CPP
//Find the required slices of pie based on the number of people

#include <iostream>

void calculateSize(int& n) {
  n = n * 2;
}

void totalPeople(int& p) {
  //Avoid complex expressions and multiple side effects per statmeent
  p++; //Increment i (side effect) - order is well-defined
  calculateSize(p);
}

int main() {
  int peopleBesidesMe = 2;
  totalPeople(peopleBesidesMe);
  std::cout<<"Slices of pie needed:"<<peopleBesidesMe<<std::endl;
  return 0;
}
