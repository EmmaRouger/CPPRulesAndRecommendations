//MEM57-CPP. Avoid using default operator new for over-aligned types
#include <iostream>
#include <cstdlib>


struct alignas(16) my_struct{
    int a;
    int b;

    static void *operator new(size_t nbytes)
    {
        if(void *ptr=_aligned_malloc(alignof(my_struct),nbytes))
        {
            return ptr;
        }
        throw std::bad_alloc();

    }
    static void operator delete(void *ptr)
    {
        std::cout<<"deallocating ptr"<<std::endl;
        free(ptr);
    }
};



int main()
{
    my_struct* myStruct = new my_struct;

    std::cout << "Address of Structure: " << myStruct << std::endl;

    delete(myStruct);
}