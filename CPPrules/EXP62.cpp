//EXP62-CPP. Do not access the bits of an object representation that are not part of the object's value representation
#include <iostream>

// Define a struct named S
struct Structure {
    int i, j;

    void clear() {//instead of memset use of clear to follow rules
        i = j = 0;
    }
};

void f() {
    Structure *s = new Structure;
    s->i=s->j=s->k=2;
    std::cout << "Values before clearing: i = " << s->i << ", j = " << s->j <<  std::endl;

    s->clear();
    std::cout << "Values after clearing: i = " << s->i << ", j = " << s->j <<  std::endl;

    delete s;
}

// Main function
int main() {
    f();
    return 0;
}