#include <iostream>

#include "move_semantics.h"

int main()
{
    MemoryBlock<int> In1(10);
    for (size_t i = 0; i < In1.size(); ++i) {
        In1[i] = i;
    }
    std::cout << "In1 = " << In1 << std::endl;

    // Copy constructor
    MemoryBlock In2(In1);
    std::cout << "In2 = " << In2 << std::endl;
    In2.resize(5);

    // Copy assignment operator
    MemoryBlock<int> In3;
    In3 = In2;
    std::cout << "In3 = " << In3 << std::endl;
    In3.resize(10);

    // Move assignment operator
    MemoryBlock In4(std::move(In3));
    std::cout << "In4 = " << In4 << std::endl;
    In4.resize(5);

    MemoryBlock<int> In5;
    In5 = std::move(In4);
    std::cout << "In5 = " << In5 << std::endl;

    return EXIT_SUCCESS;
}
