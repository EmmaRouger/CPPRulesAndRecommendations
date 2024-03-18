//CTR50-CPP. Guarantee that container indices and iterators are within the valid range
#include <iostream>
#include <string>

using namespace std;

string findLetter(string str, int pos);

int main(){
  string str = "the quick brown fox jumps over the lazy dog";
  int pos;
  cout<<"Enter string index to be returned: ";
  cin>>pos;
  cout<<"Letter at index "<<pos<<" : "<<findLetter(str, pos)<<endl;
  return 0;
}

string findLetter(string str, int pos){
  string retVal;
  if(pos>=str.length() || pos<0){ //checks to make sure the index is within the length of the string
    retVal = "Index not found.";
  }else{
    retVal = str.at(pos);
  }
  return retVal;
}
