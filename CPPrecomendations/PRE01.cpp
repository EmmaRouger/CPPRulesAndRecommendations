//PRE01-C. Use parentheses within macros around parameter names
#include <iostream>

using namespace std;

#define AREA(a, b) (a*b)
int main(){
  int length = 5;
  int width = 2;
  int area = AREA(length, width);
  cout<<"Area of a rectangle with length = "<<length<<" and width = "<<width<<" : "<<area<<endl;

  return 0;
}
