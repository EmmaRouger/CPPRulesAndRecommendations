//MSC52-CPP states that a function that returns a value and has 
//multiple paths must always return a value regardless of path taken
//Mason Myre
#include <iostream>

//we have a function that takes a different path depending on the value passed in
//this function is required to return a value
int paths(int a){
  if(a == 0){ //in the specified cases, we return a value
    return 0;
  }
  else if(a == 1){
    return 4;
  }
  else if(a == 2){
    return 9;
  }
  else if(a == 3){
    return 16;
  }
    //if none of the specified cases are the path taken, we have an
  else{ //else statement with a return to ensure a return regardlesss of path taken
    return 25;
  }
}


int main(){
  std::cout << paths(3) << " " << paths(12) << std::endl; //example code
}
