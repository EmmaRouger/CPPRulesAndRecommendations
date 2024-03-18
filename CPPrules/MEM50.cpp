//MEM50-CPP. Do not access freed memory
#include <iostream>
#include <string>
#include <new>

using namespace std;

int main(){

  string temp = "Hello World";
  string *temp2 = new string(temp);
  cout<<*temp2<<endl;
  delete temp2;
  //Don't access elements that have been freed/deleted

  return 0;
}
