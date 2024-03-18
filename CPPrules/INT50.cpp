#include <iostream>

using namespace std;

enum EnumType{
  One, Two, Three, Four, Five
};
int main(){
  int pos;
  cout<<"Index to find : ";
  cin>>pos;
  if(pos<One || pos>Five){
    cout<<"Index not found."<<endl;
  }else{
    EnumType retVal = static_cast<EnumType>(pos);
    cout<<"Index found."<<endl;
  }

  return 0;
}
