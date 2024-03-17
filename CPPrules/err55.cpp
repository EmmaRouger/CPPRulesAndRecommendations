//Rule ERR55-CPP
//Throw exception if the number entered of people to calculate pie is negative

#include <iostream>
#include <stdexcept>

int pieSlices(int people) {
  if (people < 0) {
    //Avoid use of throw() or noexcept()
    std::cerr<<"Invalid number of people"<<std::endl;
    std::exit(1);
  }

  people = people * 2;
  return people;
}

int main() {
  int pie = pieSlices(2);
  std::cout<<"Pie slices determined: "<<pie<<std::endl;

  return 0;
}
