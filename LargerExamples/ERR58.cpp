//handle all exceptions before main begins executing
//Mason Myre

#include <iostream>
#include <fstream>
using namespace std;

int numCheck(int num){
  try { //handle the try/catch
    if(num == 7){
      return 1;
    }
    else{
      throw(num);
    }

  }
  catch(int num){
    return 0;
  }

}

int a = numCheck(1); //use the try/catch functions BEFORE we run main
int b = numCheck(7);
int c = numCheck(12);


int main(int argc, char const *argv[]) {
  /* code */
  cout << a << ", " << b << ", " << c << endl;


  return 0;
}








//spacing
