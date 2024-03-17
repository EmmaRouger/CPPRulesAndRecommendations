//Rule MSC50-CPP
//Uses a method other than std::rand() to generate pseudorandom numbers

#include <iostream>
#include <random>

class RandomNumberGenerator {
public:
  RandomNumberGenerator() = default;

  int getRandomInteger(int lower, int upper) {
    std::uniform_int_distribution<int> distribution(lower, upper);
    return distribution(rd);
  }

private:
  std::random_device rd;
};

int main() {
  RandomNumberGenerator rng;
  int randomInteger = rng.getRandomInteger(1,1000);
  std::cout<<"Random integer: "<<randomInteger<<std::endl;
  return 0;
}
