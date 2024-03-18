//SIG02-C. Avoid using signals to implement normal functionality

#include <iostream>
#include <thread>
#include <chrono>

int countPie(int people) {
  //do some work
  int pieSlices = people * 2;
  std::cout<<"\nCounting..."<<std::endl;

  //Instead of using signals, call this function to say the counting is complete
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return pieSlices;
}

int main() {
  int number = 5;
  std::cout<<"Number of slices required as a function of people: "<<countPie(number)<<std::endl;
  return 0;
}
