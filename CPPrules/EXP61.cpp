//EXP61-CPP. A lambda object must not outlive any of its reference captured objects
#include <iostream>
#include <functional>

using namespace std;

auto lambda(int val){
  auto out = [val]{
    int i = val;
    auto in = [i]{
      return i+13;
    };
    return in;
  };
  return out();
}

int main(){
  int x = 11;
  auto y = lambda(11);
  cout<<"Original Value : "<<x<<endl;
  int newVal = y();
  cout<<"New Value : "<<newVal<<endl;

  return 0;
}
