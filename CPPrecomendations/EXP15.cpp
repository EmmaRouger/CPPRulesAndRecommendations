//EXP15-C. Do not place a semicolon on the same line as an if, for, or while statement
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main(){
  srand(time(0));
  int num = rand()%100;
  if(num<50){ // Don't put a semicolon after an if statement
    cout<<"The number is larger than 50"<<endl;
  }else{
    cout<<"The number is smaller than 50"<<endl;
  }

  return 0;
}
