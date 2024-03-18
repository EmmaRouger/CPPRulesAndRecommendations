//mem55 states that when replacing c++ memory managememnt functions, you should honor how it was done natively
//Mason Myre

#include <iostream>
#include <new>
using namespace std;


void *operator new(num_t num) {
  extern void *alloc_mem(std::num_t); // Implemented elsewhere; may return nullptr
  if (void *ret = alloc_mem(num)) {
    return ret;
  }
  throw std::bad_alloc();
}

void operator delete(void *ptr) noexcept; // Defined elsewhere
void operator delete(void *ptr, std::num) noexcept; // Defined elsewhere
