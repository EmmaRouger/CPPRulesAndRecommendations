#include <iostream>
using namespace std;

/*

    Runs through an array, an error occurs but program state is not altered and continues. 

*/
int main(){
    cout << "Rule ERR 56----------\n";
    int a [] = {1,2,3,4,5,6};
    int b = 10;
    int i = 0;
    for (i = 0; i < b; i++)
    {
        try
        {
            if (i >= sizeof(a)/sizeof(a[0]))
            {
                throw out_of_range("Iterator has gone out of bounds.");
                break;
            }
            else
            {
                cout << a[i] << "\n";
            }
        }
        catch(const std::exception& e)
        {
            cout << e.what() << '\n';
        }
    }

    cout << "Function Complete.\n";

    return 0;
}