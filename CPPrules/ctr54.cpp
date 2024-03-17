//Rule CTR54-CPP

#include <iostream>
#include <vector>
#include <iterator>

template <typename Iterator>
bool sameContainer(Iterator it1, Iterator it2) {
  auto distance = std::distance(it1, it2); //Subtracting iterators in compliance with Rule CTR54-CPP
  return distance >= 0; //If the distance is non-negative, the iterators are in the same container
}

int main() {
  std::vector<int> numbers = {12, 23, 34, 45, 56, 67, 78, 89, 90};
  auto it3 = numbers.begin(); //Create two iterators within the same container
  auto it4 = numbers.end();

  if (sameContainer(it3, it4)) {
    std::cout<<"Same container!"<<std::endl;
  } else {
    std::cout<<" NOT the same container, please revise."<<std::endl;
  }

  return 0;
}
