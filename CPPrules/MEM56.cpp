//MEM56-CPP. Do not store an already-owned pointer value in an unrelated smart pointer
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared_pointer1 = std::make_shared<int>(42);

    std::shared_ptr<int> shared_pointer2(shared_pointer1);

    std::cout << "shared_pointer1 value: " << *shared_pointer1 << std::endl;
    std::cout << "shared_pointer2 value: " << *shared_pointer2 << std::endl;

    *shared_pointer1 = 100;

    std::cout << "shared_pointer1 value after modification: " << *shared_pointer1 << std::endl;
    std::cout << "shared_pointer2 value after modification: " << *shared_pointer2 << std::endl;

    return 0;
}