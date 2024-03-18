//OOP58-CPP. Copy operations must not mutate the source object

#include <iostream>

class Pie {
public:
  Pie(int i) : pieces(i) {} //Constructor

  Pie(const Pie& newPie) : pieces(newPie.pieces) {} //Copy constructor creates a new object without mutating the source
  Pie& operator=(const Pie& newPie) { //Copy assignment operator
    if (this != &newPie) {
      pieces = newPie.pieces; //Copy the value without mutating the source
    }
    return *this;
  }

  int getValue() const { return pieces; } //Getter

private:
  int pieces;
};

int main() {
  Pie pie1(8);
  Pie pie2 = pie1;
  pie1 = Pie(4);
  std::cout<<"Pieces in original pie: "<<pie1.getValue()<<"\nPieces in new pie: "<<pie2.getValue()<<std::endl;
  return 0;
}
