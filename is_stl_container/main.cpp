#include <iostream>

#include "is_stl_container.h"

int main()
{
    std::cout << std::boolalpha;
    std::cout << is_stl_container<std::vector<int>>::value << std::endl;
    std::cout << is_stl_container<std::vector<int> const&>::value << std::endl;
    std::cout << is_stl_container<int>::value << std::endl;

    return EXIT_SUCCESS;
}