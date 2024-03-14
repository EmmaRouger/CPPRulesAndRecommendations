#include <iostream>
#include <random>
using namespace std;

int helper();
/*

    All Possuble Paths the function can take has a return value. 

*/
int main(){
    int exitPath = helper();
    cout << "Exited Successfully with Path: " << exitPath << "\n";
    
    return 0;
}

int helper(){

    random_device randDevice;
    minstd_rand0 engine(randDevice());

    int rand = engine() % 3;
    cout << "Generated: " << rand << "\n";
    if (rand == 0)
    {
        return 0;
    }
    else if(rand==1){
        return 1;
    }
    else if(rand==2){
        return 2;
    }
    else if(rand==3){
        return 3;
    }
    else{
        return -1;
    }
}