#include <iostream>
#include <stdexcept>
#include <cstdlib>

bool perform_dealloc(void *ptr) {
    // Simulate deallocation failure for demonstration purposes, 50% chance of failure
    return (rand() % 2 == 0); 
}

void log_failure(const char *message) {
    std::cerr << "Error: " << message << std::endl;
}

void operator delete(void *ptr) noexcept(true) {
    if (perform_dealloc(ptr)) {
        log_failure("Deallocation of pointer failed");
        exit(1); // Fail, but still call destructors
    }
}

class Resource {
public:
    Resource() { std::cout << "Resource allocated." << std::endl; }
    ~Resource() { std::cout << "Resource deallocated." << std::endl; }
};

int main() {
    try {
        Resource* res = new Resource();
        delete res; 
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}