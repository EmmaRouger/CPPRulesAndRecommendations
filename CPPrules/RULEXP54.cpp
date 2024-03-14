#include <iostream>
using namespace std;
/*      

    Two variables. One is used after being initialized, the other is used before it is destroyed

*/
int main(){  

    int num = 50;

    int *deletedData = new int;
    *deletedData = 50;
    
    cout << num + *deletedData;

    // Deleted the pointer after it's used and is no longer needed. 
    delete deletedData;

    return 0;
}