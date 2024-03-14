#include <iostream>
using namespace std;

// Macro Statement
#define LOOP_UNTIL_ZERO(n)  for(n; n > 0; n--) //<--the end of this line should not have a semi-colon

int main(){
    int num = 10;
    int track = 0;
    cout << "Num before loop: " << num << "\n";
    cout << "Track before loop: " << track << "\n";
    LOOP_UNTIL_ZERO(num){
        track++;
    }
    cout << "Num after loop: " << num << "\n"; 
    cout << "Track after loop: " << track << "\n";
    // If the semi-colon was there, then track would be 1, not 10. 

    return 0;
}