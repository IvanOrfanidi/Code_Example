#include <iostream>

#include "is_stl_container.h"

int main()
{
    std::cout << std::boolalpha;
    std::cout << "std::vector is stl container:     " << is_stl_container<std::vector<int>>::value << std::endl;
    std::cout << "std::list is stl container:       " << is_stl_container<std::list<int> const&>::value << std::endl;
    std::cout << "std::array is stl container:      " << is_stl_container<std::array<int, 1> const&>::value << std::endl;

    std::cout << "std::string is stl container:     " << is_stl_container<std::string>::value << std::endl;
    std::cout << "char[] is stl container:          " << is_stl_container<char[1]>::value << std::endl;
    std::cout << "std::fstream is stl container:    " << is_stl_container<std::fstream>::value << std::endl;

    return EXIT_SUCCESS;
}