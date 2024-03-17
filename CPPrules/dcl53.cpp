//Rule DCL53-CPP
//Initialize Pie objects with the number of pieces in each

#include <iostream>

class Pie {
public:
  int pieces;
  Pie(int i) : pieces(i) {}
  int getPieces() const {
    return pieces;
  }
};

int main() {
  //All three demonstrations below are clearly declarations
  Pie p1(8);
  Pie p2 = Pie(6);
  Pie p3((7)); //As noted, extra parentheses help ensure clarity

  std::cout<<p1.getPieces()<<std::endl;
  std::cout<<p2.getPieces()<<std::endl;

  return 0;
}
