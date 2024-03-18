#include <iostream>
#include <string>

using namespace std;

string transformString(const string str){
  return str;
}

int main(){
  string input;
  cout<<"Enter a string : ";
  cin>>input;
  cout<<transformString(input)<<endl;

  return 0;
}
