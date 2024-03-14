#include <iostream>
#include <random>
using namespace std;

/*

    All Possuble Paths the function can take has a return value. 

*/
int main(){

    cout << "Generating 5 Random Numbers:\n";
    
    random_device randDevice;
    minstd_rand0 engine(randDevice());

    for(int i = 0; i < 5; i++){
        cout << engine() << "\n";
    }

    return 0;
}