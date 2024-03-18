//DCL50-CPP. Do not define a C-style variadic function
#include <iostream>

using namespace std;

template <typename... Args>
int add(Args... args){
  return (args+...);
}

int main(){
  int retVal = add(0, 5, 10, 15, 20, 25, 30);
  cout<<"Sum of the arguements: "<<retVal<<endl;
  return 0;
}
