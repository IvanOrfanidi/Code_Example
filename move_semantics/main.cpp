#include <iostream>
#include <vector>

#include "move_semantics.h"

int main()
{
    MemoryBlock<int> In1(1);

    // Copy constructor
    MemoryBlock<int> In2(In1);
    std::cout << In2.size() << std::endl;
    In2.resize(2);

    // Copy assignment operator
    MemoryBlock<int> In3;
    In3 = In1;
    std::cout << In3.size() << std::endl;

    // Move assignment operator
    MemoryBlock<int> In4(std::move(In3));
    std::cout << In4.size() << std::endl;

    MemoryBlock<int> In5;
    In5 = std::move(In2);
    std::cout << In5.size() << std::endl;

    return 0;
}
