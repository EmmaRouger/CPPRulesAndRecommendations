//Rule ERR59-CPP
//Throw exception if the number entered of people to calculate pie is negative...
//... within the same program, NOT across any execution boundaries

#include <iostream>
#include <stdexcept>

int pieSlices(int people) {
  if (people < 0) {
    std::cerr<<"Invalid number of people"<<std::endl;
    std::terminate(); //Terminate the program to avoid crossing an execution boundary
  }

  people = people * 2;
  return people;
}

int main() {
  int pie = pieSlices(2);
  std::cout<<"Pie slices determined: "<<pie<<std::endl;

  return 0;
}
