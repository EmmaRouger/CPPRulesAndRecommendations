#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void valSet(mutex &mtx, int &valueToSet, int val);

/*

    When locking and unlocking access to shared/important data, ensure that 
    the state of the program can continue to the unlock if an exception occurs. 

*/
int main(){
    
    int val = 0;
    cout << "Value was: " << val << "\n";    
    
    mutex mtx;
    
    thread t1 (valSet, ref(mtx), ref(val), 36);
    thread t2 (valSet, ref(mtx), ref(val), 72);
    
    t1.join();
    t2.join();

    return 0;
}

/*
    
    Helper method for ruleCon51 for accessing a val variable.
    
*/
void valSet(mutex &mtx, int &valueToSet, int val){
    mtx.lock();
    try
    {
        valueToSet = val;
        cout << "Value is now: " << val << " by thread: " << __threadid << "\n";
        
        
    }
    catch(const std::exception& e)
    {
        mtx.unlock();
        std::cerr << e.what() << '\n';

    }
    mtx.unlock();

}