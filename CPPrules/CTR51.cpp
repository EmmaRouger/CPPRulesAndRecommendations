#include <iostream>
#include <vector>


void f(const double *items, std::size_t count) {
    std::vector<double> d;

    auto pos = d.begin();

    for (std::size_t i = 0; i < count; ++i, ++pos) {
        pos = d.insert(pos, items[i] + 41.0);
    }

    std::cout << "Vector contents: ";
    for (const auto& elem : d) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    const double items[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::size_t count = sizeof(items) / sizeof(items[0]);

    f(items, count);

    return 0;
}