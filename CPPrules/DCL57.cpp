#include <iostream>
#include <stdexcept>
#include <cstdlib>

class Resource {
public:
    Resource() { std::cout << "Resource allocated." << std::endl; }
    ~Resource() { std::cout << "Resource deallocated." << std::endl; }
};

int main() {
    try {
        Resource* res = new Resource();
        delete res; 
    } catch (const std::exception& e) {// make sure there isn't a problem with dealloation
        std::cerr << "Exception: " << e.what() << std::endl;
        std::exit(1);//even with error will deallocated the memory with exit(1)
    }

    return 0;
}