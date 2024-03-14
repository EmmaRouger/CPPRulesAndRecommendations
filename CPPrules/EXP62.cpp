#include <iostream>

// Define a struct named S
struct Structure {
    int i, j, k;
    virtual void f() {
        std::cout << "This is inside S::f()" << std::endl;
    }
    void clear() {//instead of memset use of clear to follow rules
        i = j = k = 0;
    }
};

void f() {
    Structure *s = new Structure;
    std::cout << "Values before clearing: i = " << s->i << ", j = " << s->j << ", k = " << s->k << std::endl;

    s->clear();
    std::cout << "Values after clearing: i = " << s->i << ", j = " << s->j << ", k = " << s->k << std::endl;

    s->f();

    delete s;
}

// Main function
int main() {
    f();
    return 0;
}